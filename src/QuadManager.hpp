#pragma once

#include <stack>
#include <queue>
#include "SemanticCube.hpp"
#include "operand.hpp"
#include "VirtualAddressManager.hpp"
#include "FuncDir.hpp"
#include "quads.hpp"

class QuadManager {
    private:
        int tempCount = 0;
    
    public:
        int instructionPointer = 0;
        std::vector<quad*> quads;
        std::stack<operatortype> operators;
        std::stack<operand> operands;
        std::stack<int> jumps;

        operand getTemp(vartype type);

        void push(quad* q);
        bool generateBinaryQuad(VirtualAddressManager* addrManager);
        bool generateUnaryQuad(VirtualAddressManager* addrManager);
};