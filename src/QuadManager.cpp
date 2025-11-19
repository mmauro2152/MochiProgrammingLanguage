#include "QuadManager.hpp"

void QuadManager::push(quad q) {
    quads.push_back(q);
    instructionPointer++;
}

bool QuadManager::generateBinaryQuad(VirtualMemoryManager memManager){
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

    operand temp = memManager.getTemp(restype);
    quad q = quad(op, lOperand, rOperand, temp);

    push(q);
    operands.push(temp);

    return true;
}

bool QuadManager::generateUnaryQuad(VirtualMemoryManager memManager){
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

    operand temp = memManager.getTemp(restype);
    quad q = quad(op, operand(), rOperand, temp);

    push(q);
    operands.push(temp);
    
    return true;
}