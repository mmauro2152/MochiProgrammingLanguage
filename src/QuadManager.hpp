#pragma once

#include <stack>
#include <queue>
#include "SemanticCube.hpp"
#include "operand.hpp"
#include "VirtualMemoryManager.hpp"
#include "FuncDir.hpp"

struct quad {
    operatortype operator_;

    virtual void printQuad() {}

    quad(): operator_(operatortype::unknown) {}
    quad(operatortype o): operator_(o) {}
};

struct binaryOperation : quad {
    operand leftOperand;
    operand rightOperand;
    operand result;

    void printQuad() override {
        std::cout << operatortype_string[static_cast<int>(operator_)] << ", " <<
        leftOperand.str << ", " <<
        rightOperand.str << ", " <<
        result.str;
    }

    binaryOperation(): quad(), leftOperand(operand()), rightOperand(operand()), result(operand()) {}
    binaryOperation(operatortype o, operand l, operand r, operand res): quad(o), leftOperand(l), rightOperand(r), result(res) {}
};

struct unaryOperation : quad {
    operand operand_;
    operand result;

    void printQuad() override {
        std::cout << operatortype_string[static_cast<int>(operator_)] << ", " <<
        operand_.str << ", " <<
        result.str;
    }

    unaryOperation(): quad(), operand_(operand()), result(operand()) {}
    unaryOperation(operatortype o, operand o_, operand res): quad(o),  operand_(o_), result(res) {}
};

struct goto_ : quad {
    int jump;

    void printQuad() override {
        std::cout << operatortype_string[static_cast<int>(operator_)] << ", " << jump;
    }

    goto_(): quad(operatortype::goto_), jump(-1) {}
    goto_(int i): quad(operatortype::goto_), jump(i) {} 
    goto_(operatortype o, int i): quad(o), jump(i) {}
};

struct condGoto : goto_ {
    operand condition;

    void printQuad() override {
        std::cout << operatortype_string[static_cast<int>(operator_)] << ", " 
        << condition.str << ", "
        << jump;
    }

    condGoto(): goto_(operatortype::unknown, -1), condition(operand()) {}
    condGoto(operatortype o, operand c, int i): goto_(o, i), condition(c) {}
};

struct print : quad {
    operand operand_;

    void printQuad() override {
        std::cout << operatortype_string[static_cast<int>(operator_)] << ", " << operand_.str;
    }

    print(): quad(operatortype::unknown), operand_(operand()) {}
    print(operand o): quad(operatortype::print), operand_(o) {}
};

struct operation : quad {
    operand leftOperand;
    operand rightOperand;
    operand result;

    void printQuad() override {
        std::cout << operatortype_string[static_cast<int>(operator_)] << ", " <<
        leftOperand.str << ", " <<
        rightOperand.str << ", " <<
        result.str;
    }

    operation(): quad(), leftOperand(operand()), rightOperand(operand()), result(operand()) {}
    operation(operatortype o, operand l, operand r, operand res): quad(o), leftOperand(l), rightOperand(r), result(res) {}
};

struct instruction : quad {
    int data1;
    int data2;
    int data3;

    void printQuad() override {
        std::cout << operatortype_string[static_cast<int>(operator_)] << ", " <<
        data1 << ", " <<
        data2 << ", " <<
        data3 << ", ";
    }

    instruction(): quad(), data1(-1), data2(-1), data3(-1) {}
    instruction(operatortype o, int d1, int d2, int d3) : quad(o), data1(d1), data2(d2), data3(d3) {}
};

struct call : quad {
    std::string funcName;
    int jump;

    void printQuad() override {
        std::cout << operatortype_string[static_cast<int>(operator_)] << ", " << 
        funcName << ", " <<
        jump;
    }

    call(): quad(operatortype::unknown), funcName(""), jump(-1) {}
    call(std::string n, int j): quad(operatortype::call), funcName(n), jump(j) {}
};

struct reserve : quad {
    VirtualMemoryManager* memory;

    void printQuad() override {
        std::cout << operatortype_string[static_cast<int>(operator_)] << ", " << memory->getscope();
    }

    reserve(): quad(operatortype::unknown), memory(nullptr) {}
    reserve(VirtualMemoryManager* m): quad(operatortype::reserve), memory(m) {}
};

struct arg : quad {
    operand argument;
    int pos;

    void printQuad() override {
        std::cout << operatortype_string[static_cast<int>(operator_)] << ", " << 
        argument.str << ", " <<
        pos;
    }

    arg(): quad(operatortype::unknown), argument(operand()), pos(-1) {}
    arg(operand a, int p): quad(operatortype::arg), argument(a), pos(p) {}
};

struct endfunc : quad {
    
    void printQuad() override {
        std::cout << operatortype_string[static_cast<int>(operator_)];
    }

    endfunc(): quad(operatortype::endfunc) {}
};

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

        // void debug() {
        //     for (int i = 0; i < quads.size(); i++) {
        //         std::cout << i << " " << operatortype_string[static_cast<int>(quads[i].operator_)] << " " << quads[i].leftOperand.addr << " " << quads[i].rightOperand.addr << " " << quads[i].result.addr << std::endl;
        //     }

        //     return;
        // }

        bool generateBinaryQuad(VirtualMemoryManager* memManager);
        bool generateUnaryQuad(VirtualMemoryManager* memManager);
};