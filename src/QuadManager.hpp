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
        std::queue<quad> quads;
        std::string tempScope = "__temps";
        int tempCount = 0;

    public:
        std::stack<operatortype> operators;
        std::stack<operand> operands;

        operand getTemp(vartype type);

        void push(quad q);

        void debug() {
            while (!quads.empty()) {
                quad q = quads.front();
                std::cout << operatortype_string[static_cast<int>(q.operator_)] << " " << q.leftOperand.name << " " << q.rightOperand.name << " " << q.result.name << std::endl;
                quads.pop();
             }

            return;
        }
};