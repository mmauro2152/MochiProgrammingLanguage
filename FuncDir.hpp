#pragma once

#include <vector>
#include "VarTable.hpp"

struct FuncEntry {
    vartype returnType;
    std::vector<std::pair<std::string, vartype>> parameters;
    VarTable localVars;

    FuncEntry(): returnType(vartype::void_type) {}
    FuncEntry(vartype r) : returnType(r) {}
};

class FuncDir{
private:
    std::unordered_map<std::string, FuncEntry> table;

public:
    bool insertFunction(const std::string& name, vartype returnType);

    bool exists(const std::string& name);

    bool addParameter(const std::string& funcName, const std::string& paramName, vartype paramType);

    FuncEntry* getFunction(const std::string& name);

    void printAll();
};