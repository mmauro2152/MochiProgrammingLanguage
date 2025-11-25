#include "quads.hpp"
#include "MochiVM/Machine.hpp"
#include "VirtualMemoryManager.hpp"
#include "MochiVM/functors.hpp"


// empty parent class
void quad::printQuad() {}
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
    int leftindex = VirtualMemoryManager::getIndex(leftOperand);
    int rightindex = VirtualMemoryManager::getIndex(rightOperand);
    int resindex = VirtualMemoryManager::getIndex(result);
    Memory* leftmem = (leftOperand.mem == memorytype::global || leftOperand.mem == memorytype::const_) ? vm->globalMemory : vm->memoryStack.top();
    Memory* rightmem = (rightOperand.mem == memorytype::global || rightOperand.mem == memorytype::const_) ? vm->globalMemory : vm->memoryStack.top();
    Memory* resmem = (result.mem == memorytype::global || result.mem == memorytype::const_) ? vm->globalMemory : vm->memoryStack.top();
    datatypes leftval = leftmem->operator[](leftOperand.mem)[leftOperand.type][leftindex];
    datatypes rightval = rightmem->operator[](rightOperand.mem)[rightOperand.type][rightindex];

    resmem->operator[](result.mem)[result.type][resindex] = std::visit(binaryFunctor(operator_), leftval, rightval);
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
    int operindex = VirtualMemoryManager::getIndex(operand_);
    int resindex = VirtualMemoryManager::getIndex(result);
    Memory* opermem = (operand_.mem == memorytype::global || operand_.mem == memorytype::const_) ? vm->globalMemory : vm->memoryStack.top();
    Memory* resmem = (result.mem == memorytype::global || result.mem == memorytype::const_) ? vm->globalMemory : vm->memoryStack.top();
    datatypes operval = opermem->operator[](operand_.mem)[operand_.type][operindex];

    resmem->operator[](result.mem)[result.type][resindex] = std::visit(unaryFunctor(operator_), operval);
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
    int condindex = VirtualMemoryManager::getIndex(condition);
    Memory* condmem = (condition.mem == memorytype::global || condition.mem == memorytype::const_) ? vm->globalMemory : vm->memoryStack.top();
    datatypes condval = condmem->operator[](condition.mem)[condition.type][condindex];

    bool cond = std::get<bool>(condval);

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
    int operindex = VirtualMemoryManager::getIndex(operand_);
    Memory* opermem = (operand_.mem == memorytype::global || operand_.mem == memorytype::const_) ? vm->globalMemory : vm->memoryStack.top();
    datatypes operval = opermem->operator[](operand_.mem)[operand_.type][operindex];

    std::visit(printFunctor(endl), operval);
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
    std::cout << operatortype_string[operator_] << ", " << memory->getscope();
}

void reserve::execute(Machine* vm) {
    if (memory->global) {
        vm->globalMemory = new Memory(memory);
        vm->memoryStack.push(vm->globalMemory);
    }else {
        vm->reservedMemory.push(new Memory(memory));
    }

    vm->instructionPointer++;
}

reserve::reserve(): quad(operatortype::unknown), memory(nullptr) {}
reserve::reserve(VirtualMemoryManager* m): quad(operatortype::reserve), memory(m) {}


// arg - param
void arg::printQuad() {
    std::cout << operatortype_string[operator_] << ", " << 
    argument.str << ", " <<
    pos;
}

void arg::execute(Machine* vm) {
    int argindex = VirtualMemoryManager::getIndex(argument);
    int paramindex = VirtualMemoryManager::getIndex(param);
    Memory* argmem = (argument.mem == memorytype::global || argument.mem == memorytype::const_) ? vm->globalMemory : vm->memoryStack.top();
    Memory* parammem = vm->reservedMemory.top();
    datatypes argval = argmem->operator[](argument.mem)[argument.type][argindex];

    parammem->operator[](param.mem)[param.type][paramindex] = argval;
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
