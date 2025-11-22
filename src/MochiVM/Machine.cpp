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