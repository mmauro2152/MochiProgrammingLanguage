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
    std::string scope;
    int addr;
    memorytype mem;

    std::string str;

    operand(): type(vartype::unknown), scope(""), addr(-1) , mem(memorytype::const_), str("") {}
    operand(vartype t, std::string s, int a, memorytype m, std::string s_): type(t), scope(s), addr(a), mem(m), str(s_) {}
};