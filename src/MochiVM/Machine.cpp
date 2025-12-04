#include "Machine.hpp"

Machine::Machine(std::vector<quad*> quads) {
    this->quads = quads;
}

void Machine::execute() {
    instructionPointer = 0;
    while (instructionPointer < quads.size()) {
        quads[instructionPointer]->execute(this);
    }
}

cell* Machine::getcell(operand o, bool is_param) {
    int i = VirtualAddressManager::getIndex(o);
    Memory* mem;

    if (is_param) {
        mem = reservedMemory.top();
    } else if (o.mem == memorytype::global || o.mem == memorytype::const_){
        mem = globalMemory;
    } else {
        mem = memoryStack.top();
    }

    return mem->operator[](o.mem)[o.type][i];
}