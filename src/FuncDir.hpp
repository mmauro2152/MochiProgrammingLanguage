#pragma once

#include <vector>
#include "VarTable.hpp"
#include "VirtualMemoryManager.hpp"

struct FuncEntry {
    vartype returnType;
    std::vector<std::pair<std::string, vartype>> parameters;
    VarTable localVars;
    VirtualMemoryManager memManager;
    std::string scope;


    FuncEntry(): returnType(vartype::void_type) {}
    FuncEntry(vartype r) : returnType(r) {}
};

class FuncDir{
private:
    std::unordered_map<std::string, FuncEntry> table;
    std::string globalScope;

public:
    bool insertFunction(const std::string& name, vartype returnType);

    bool exists(const std::string& name);

    bool addParameter(const std::string& funcName, const std::string& paramName, vartype paramType);

    FuncEntry* getFunction(const std::string& name);

    void printAll();

    void setGlobalScope(const std::string& scope);

    VarEntry* getVar(const std::string& scope, const std::string& varName);
};