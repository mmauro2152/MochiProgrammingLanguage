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

    std::string str;

    operand(): type(vartype::unknown), scope(""), addr(-1) , cat(operandcat::none), str("") {}
    operand(vartype t, std::string s, int a, operandcat c, std::string s_): type(t), scope(s), addr(a), cat(c), str(s_) {}
};