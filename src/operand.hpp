#pragma once

#include "VarTable.hpp"

enum class operandcat {
    var,
    temp,
    const_,
    pointer,
    none
};

struct operand {
    vartype type;
    int addr;
    std::string scope;
    operandcat cat;

    operand(): type(vartype::unknown), scope(""), addr(-1) , cat(operandcat::none) {}
    operand(vartype t, std::string s, int a, operandcat c): type(t), scope(s), addr(a), cat(c) {}
};