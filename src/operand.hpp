#pragma once

#include "VarTable.hpp"

struct operand {
    vartype type;
    int addr;
    std::string scope;
    std::string name;

    operand(): type(vartype::unknown), scope(nullptr), name(nullptr), addr(-1) {}
    operand(vartype t, std::string s, std::string n, int a): type(t), scope(s), name(n), addr(a) {}
};