#pragma once

#include <vector>
#include "VarTable.hpp"

struct FuncEntry {
    VarType returnType;
    std::vector<std::pair<std::string, VarType>> parameters;
    VarTable localVars;

    FuncEntry(): returnType(VarType::VOID) {}
    FuncEntry(VarType r) : returnType(r) {}
};

class FuncDir{
private:
    std::unordered_map<std::string, FuncEntry> table;

public:
    bool insertFunction(const std::string& name, VarType returnType);

    bool exists(const std::string& name);

    bool addParameter(const std::string& funcName, const std::string& paramName, VarType paramType);

    FuncEntry* getFunction(const std::string& name);

    void printAll();
};