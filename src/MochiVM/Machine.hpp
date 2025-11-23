#pragma once

#include "Memory.hpp"
#include "../quads.hpp"
#include <stack>

class Machine {
    friend struct binaryOperation;
    friend struct unaryOperation;
    friend struct goto_;
    friend struct condGoto;
    friend struct print;
    friend struct call;
    friend struct reserve;
    friend struct arg;
    friend struct endfunc;

    private:
        Memory* globalMemory;
        int instructionPointer = 0;
        std::stack<int> returnPointers;
        std::vector<quad*> quads;
        std::stack<Memory*> memoryStack;
        std::stack<Memory*> reservedMemory;
        
    public:
        Machine(std::vector<quad*> quads);
        
        void execute();

};