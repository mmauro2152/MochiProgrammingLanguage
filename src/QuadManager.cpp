#include "QuadManager.hpp"

operand QuadManager::getTemp(vartype type) {
    return operand(type, tempScope, "t" + std::to_string(++tempCount));
}

void QuadManager::push(quad q) {
    quads.push_back(q);
    instructionPointer++;
}

bool QuadManager::generateBinaryQuad(){
    if (operands.size() < 2 || operators.empty()) {
        return false;
    }

    operand rOperand = operands.top();
    operands.pop();
    operand lOperand = operands.top();
    operands.pop();
    operatortype op = operators.top();
    operators.pop();

    CubeEntry entry = CubeEntry(lOperand.type, rOperand.type, op);
    vartype restype = SemanticCube::resultingType(entry);

    if (restype == vartype::unknown) {
        return false;
    }

    operand temp = getTemp(restype);
    quad q = quad(op, lOperand, rOperand, temp);

    push(q);
    operands.push(temp);

    return true;
}

bool QuadManager::generateUnaryQuad(){
    if (operands.empty() || operators.empty()) {
        return false;
    }

    operand rOperand = operands.top();
    operands.pop();
    operatortype op = operators.top();
    operators.pop();

    CubeEntry entry = CubeEntry(vartype::none, rOperand.type, op);
    vartype restype = SemanticCube::resultingType(entry);

    if (restype == vartype::unknown) {
        return false;
    }

    operand temp = getTemp(restype);
    quad q = quad(op, operand(vartype::none, "none", "none"), rOperand, temp);

    push(q);
    operands.push(temp);
    
    return true;
}