#include "quads.hpp"
#include "MochiVM/Machine.hpp"
#include "VirtualMemoryManager.hpp"
#include "SemanticCube.hpp"


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
    
}

unaryOperation::unaryOperation(): quad(), operand_(operand()), result(operand()) {}
unaryOperation::unaryOperation(operatortype o, operand o_, operand res): quad(o),  operand_(o_), result(res) {}


// goto
void goto_::printQuad() {
    std::cout << operatortype_string[operator_] << ", " << jump;
}

void goto_::execute(Machine* vm) {
    
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
    
}

condGoto::condGoto(): goto_(operatortype::unknown, -1), condition(operand()) {}
condGoto::condGoto(operatortype o, operand c, int i): goto_(o, i), condition(c) {}


// print
void print::printQuad() {
    std::cout << operatortype_string[operator_] << ", " << operand_.str;
}

void print::execute(Machine* vm) {
    
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
    
}

call::call(): quad(operatortype::unknown), funcName(""), jump(-1) {}
call::call(std::string n, int j): quad(operatortype::call), funcName(n), jump(j) {}


// reserve - era
void reserve::printQuad() {
    std::cout << operatortype_string[operator_] << ", " << memory->getscope();
}

void reserve::execute(Machine* vm) {
    
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
    
}

arg::arg(): quad(operatortype::unknown), argument(operand()), pos(-1) {}
arg::arg(operand a, int p): quad(operatortype::arg), argument(a), pos(p) {}


// endfunc
void endfunc::printQuad() {
    std::cout << operatortype_string[operator_];
}

void endfunc::execute(Machine* vm) {
    
}

endfunc::endfunc(): quad(operatortype::endfunc) {}
