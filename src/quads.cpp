#include "quads.hpp"
#include "MochiVM/Machine.hpp"
#include "VirtualAddressManager.hpp"
#include "MochiVM/functors.hpp"


// empty parent class
quad::quad(): operator_(operatortype::unknown) {}
quad::quad(operatortype o): operator_(o) {}


// binary operation
void binaryOperation::printQuad() {
    std::cout << operatortype_string[operator_] << ", " <<
    leftOperand.str << ", " <<
    rightOperand.str << ", " <<
    result.str;
}

void binaryOperation::execute(Machine* vm) {
    cell* leftcell = vm->getcell(leftOperand);
    cell* rightcell = vm->getcell(rightOperand);

    if (!leftcell->initialized) {
        if (leftOperand.mem == memorytype::global || leftOperand.mem == memorytype::local){
            throw std::runtime_error("Uninitialized variable '" + leftOperand.str + "'");
        } else {
            // nunca deberia de suceder
            throw std::runtime_error("Uninitialized temp '" + leftOperand.str + "'");
        } 
    }

    if (!rightcell->initialized) {
        if (rightOperand.mem == memorytype::global || rightOperand.mem == memorytype::local){
            throw std::runtime_error("Uninitialized variable '" + rightOperand.str + "'");
        } else {
            // nunca deberia de suceder
            throw std::runtime_error("Uninitialized temp '" + rightOperand.str + "'");
        } 
    }

    datatypes r = std::visit(
        binaryFunctor(operator_), 
        leftcell->value, 
        rightcell->value);
        
    vm->getcell(result)->setvalue(r);
    vm->instructionPointer++;
}

binaryOperation::binaryOperation(): quad(), leftOperand(operand()), rightOperand(operand()), result(operand()) {}
binaryOperation::binaryOperation(operatortype o, operand l, operand r, operand res): quad(o), leftOperand(l), rightOperand(r), result(res) {}


// unary operation
void unaryOperation::printQuad() {
    std::cout << operatortype_string[operator_] << ", " <<
    operand_.str << ", " <<
    result.str;
}

void unaryOperation::execute(Machine* vm) {
    cell* opercell = vm->getcell(operand_);

    if (!opercell->initialized && operator_ != operatortype::input) {
        if (operand_.mem == memorytype::global || operand_.mem == memorytype::local){
            throw std::runtime_error("Uninitialized variable '" + operand_.str + "'");
        } else {
            throw std::runtime_error("Uninitialized temp '" + operand_.str + "'");
        }
    }

    datatypes r = std::visit(unaryFunctor(operator_), opercell->value);
    vm->getcell(result)->setvalue(r);
    vm->instructionPointer++;
}

unaryOperation::unaryOperation(): quad(), operand_(operand()), result(operand()) {}
unaryOperation::unaryOperation(operatortype o, operand o_, operand res): quad(o),  operand_(o_), result(res) {}


// goto
void goto_::printQuad() {
    std::cout << operatortype_string[operator_] << ", " << jump;
}

void goto_::execute(Machine* vm) {
    vm->instructionPointer = jump;
}

goto_::goto_(): quad(operatortype::goto_), jump(-1) {}
goto_::goto_(int i): quad(operatortype::goto_), jump(i) {} 
goto_::goto_(operatortype o, int i): quad(o), jump(i) {}


// cond goto
void condGoto::printQuad() {
    std::cout << operatortype_string[operator_] << ", " 
    << condition.str << ", "
    << jump;
}

void condGoto::execute(Machine* vm) {
    cell* condcell = vm->getcell(condition);

    if (!condcell->initialized) {
        if (condition.mem == memorytype::global || condition.mem == memorytype::local){
            throw std::runtime_error("Uninitialized variable '" + condition.str + "'");
        } else {
            throw std::runtime_error("Uninitialized temp '" + condition.str + "'");
        }
    }

    bool cond = std::get<bool>(condcell->value);

    switch (operator_) {
        case operatortype::gotof:
            if (!cond) 
                vm->instructionPointer = jump;
            else 
                vm->instructionPointer++;     
            break;

        case operatortype::gotot:
            if (cond) 
                vm->instructionPointer = jump;
            else 
                vm->instructionPointer++;
            break;

        default:
            throw std::runtime_error("Invalid operator");
            break;
    }
}

condGoto::condGoto(): goto_(operatortype::unknown, -1), condition(operand()) {}
condGoto::condGoto(operatortype o, operand c, int i): goto_(o, i), condition(c) {}


// print
void print::printQuad() {
    std::cout << operatortype_string[operator_] << ", " << operand_.str;
}

void print::execute(Machine* vm) {
    cell* opercell = vm->getcell(operand_);

    if (!opercell->initialized) {
        if (operand_.mem == memorytype::global || operand_.mem == memorytype::local){
            throw std::runtime_error("Uninitialized variable '" + operand_.str + "'");
        } else {
            throw std::runtime_error("Uninitialized temp '" + operand_.str + "'");
        }
    }

    std::visit(printFunctor(endl), opercell->value);
    vm->instructionPointer++;
}

print::print(): quad(operatortype::unknown), operand_(operand()) {}
print::print(operand o): quad(operatortype::print), operand_(o) {}


// call - gosub
void call::printQuad() {
    std::cout << operatortype_string[operator_] << ", " << 
    funcName << ", " <<
    jump;
}

void call::execute(Machine* vm) {
    vm->memoryStack.push(vm->reservedMemory.top());
    vm->reservedMemory.pop();

    vm->returnPointers.push(vm->instructionPointer + 1);
    vm->instructionPointer = jump;
}

call::call(): quad(operatortype::unknown), funcName(""), jump(-1) {}
call::call(std::string n, int j): quad(operatortype::call), funcName(n), jump(j) {}


// reserve - era
void reserve::printQuad() {
    std::cout << operatortype_string[operator_] << ", " << addrManager->getscope();
}

void reserve::execute(Machine* vm) {
    if (addrManager->global) {
        vm->globalMemory = new Memory(addrManager);
        vm->memoryStack.push(vm->globalMemory);
    }else {
        vm->reservedMemory.push(new Memory(addrManager));
    }

    vm->instructionPointer++;
}

reserve::reserve(): quad(operatortype::unknown), addrManager(nullptr) {}
reserve::reserve(VirtualAddressManager* m): quad(operatortype::reserve), addrManager(m) {}


// arg - param
void arg::printQuad() {
    std::cout << operatortype_string[operator_] << ", " << 
    argument.str << ", " <<
    pos;
}

void arg::execute(Machine* vm) {
    cell* argcell = vm->getcell(argument);

    if (!argcell->initialized) {
        if (argument.mem == memorytype::global || argument.mem == memorytype::local){
            throw std::runtime_error("Uninitialized variable '" + argument.str + "'");
        } else {
            throw std::runtime_error("Uninitialized temp '" + argument.str + "'");
        }
    }

    vm->getcell(param, true)->setvalue(argcell->value);
    vm->instructionPointer++;
}

arg::arg(): quad(operatortype::unknown), argument(operand()), pos(-1), param(operand()) {}
arg::arg(operand a, int p, operand pa): quad(operatortype::arg), argument(a), pos(p), param(pa) {}


// endfunc
void endfunc::printQuad() {
    std::cout << operatortype_string[operator_];
}

void endfunc::execute(Machine* vm) {
    vm->instructionPointer = vm->returnPointers.top();
    vm->returnPointers.pop();
    vm->memoryStack.pop();
}

endfunc::endfunc(): quad(operatortype::endfunc) {}
