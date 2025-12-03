#include "QuadManager.hpp"

void QuadManager::push(quad* q) {
    if (pushToTempQuads) {
        tempQuads.top().push_back(q);
    } else {
        quads.push_back(q);
        instructionPointer++;
    }
}

bool QuadManager::generateBinaryQuad(VirtualAddressManager* addrManager){
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

    operand temp = addrManager->getTemp(restype);
    quad* q = new binaryOperation(op, lOperand, rOperand, temp);

    push(q);
    operands.push(temp);

    return true;
}

bool QuadManager::generateUnaryQuad(VirtualAddressManager* addrManager){
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

    operand temp = addrManager->getTemp(restype);
    quad* q = new unaryOperation(op, rOperand, temp);

    push(q);
    operands.push(temp);
    
    return true;
}

void QuadManager::newTempQuads(){
    pushToTempQuads = true;
    tempQuads.push({});
}

void QuadManager::emptyTempQuads() {
    pushToTempQuads = false;

    for (auto q : tempQuads.top()) {
        push(q);
    }

    tempQuads.pop();
}