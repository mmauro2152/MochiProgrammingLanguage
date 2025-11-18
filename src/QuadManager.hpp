#pragma once

#include <stack>
#include <queue>
#include "SemanticCube.hpp"

struct operand {
    vartype type;
    std::string scope;
    std::string name;

    operand(): type(vartype::unknown), scope(nullptr), name(nullptr) {}
    operand(vartype t, std::string s, std::string n): type(t), scope(s), name(n) {}
};

struct quad {
    operatortype operator_;
    operand leftOperand;
    operand rightOperand;
    operand result;

    quad(): operator_(operatortype::unknown), leftOperand(operand()), rightOperand(operand()), result(operand()) {}
    quad(operatortype o, operand l, operand r, operand res): operator_(o), leftOperand(l), rightOperand(r), result(res) {}
};

class QuadManager {
    private:
        int tempCount = 0;
    
    public:
        std::string tempScope = "__temps";
        std::string constScope = "__constants";
        int instructionPointer = 0;
        std::vector<quad> quads;
        std::stack<operatortype> operators;
        std::stack<operand> operands;
        std::stack<int> jumps;

        operand getTemp(vartype type);

        void push(quad q);

        void debug() {
            for (int i = 0; i < quads.size(); i++) {
                std::cout << i << " " << operatortype_string[static_cast<int>(quads[i].operator_)] << " " << quads[i].leftOperand.name << " " << quads[i].rightOperand.name << " " << quads[i].result.name << std::endl;
            }

            return;
        }

        bool generateBinaryQuad();
};