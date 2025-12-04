#pragma once

#include <string>
#include <unordered_map>
#include <iostream>
#include "proxyarr.hpp"
#include "memorytype.hpp"
#include "operand.hpp"

static std::string var_s[] {
    "int", "float", "string", "bool", "void", "unknown", "none", "func"
};

static proxyarr<std::string> vartype_string = proxyarr<std::string>(var_s);

class VarTable {
private:
    std::string scope;
    std::unordered_map<int, operand> table;
    std::unordered_map<std::string, int> nameToAddr;

public:
    bool insert(const int& addr, vartype type, std::string name, memorytype mem);

    bool exists(const int& addr);

    bool exists(const std::string& name);

    operand getVar(const int& addr);

    operand getVar(const std::string& name);

    bool empty();

    void printAll();
};
