#pragma once

#include "operand.hpp"
#include "SemanticCube.hpp"


template<class... Ts> struct overload : Ts... { using Ts::operator()...; };
template<class... Ts> overload(Ts...) -> overload<Ts...>;

class Machine;
class VirtualMemoryManager;

struct quad {
    operatortype operator_;

    virtual void printQuad();
    virtual void execute(Machine* vm) = 0;

    quad();
    quad(operatortype o);
};

struct binaryOperation : quad {
    operand leftOperand;
    operand rightOperand;
    operand result;

    void printQuad() override;
    void execute(Machine* vm) override;

    binaryOperation();
    binaryOperation(operatortype o, operand l, operand r, operand res);
};

struct unaryOperation : quad {
    operand operand_;
    operand result;

    void printQuad();
    void execute(Machine* vm);

    unaryOperation();
    unaryOperation(operatortype o, operand o_, operand res);
};

struct goto_ : quad {
    int jump;

    void printQuad() override;
    void execute(Machine* vm) override;

    goto_();
    goto_(int i);
    goto_(operatortype o, int i);
};

struct condGoto : goto_ {
    operand condition;

    void printQuad() override;
    void execute(Machine* vm) override;

    condGoto();
    condGoto(operatortype o, operand c, int i);
};

struct print : quad {
    operand operand_;

    void printQuad() override;
    void execute(Machine* vm) override;

    print();
    print(operand o);
};

struct call : quad {
    std::string funcName;
    int jump;

    void printQuad() override;
    void execute(Machine* vm) override;

    call();
    call(std::string n, int j);
};

struct reserve : quad {
    VirtualMemoryManager* memory;

    void printQuad() override;
    void execute(Machine* vm) override;

    reserve();
    reserve(VirtualMemoryManager* m);
};

struct arg : quad {
    operand argument;
    operand param;
    int pos;

    void printQuad() override;
    void execute(Machine* vm) override;

    arg();
    arg(operand a, int p, operand pa);
};

struct endfunc : quad {
    void printQuad() override;
    void execute(Machine* vm) override;

    endfunc();
};