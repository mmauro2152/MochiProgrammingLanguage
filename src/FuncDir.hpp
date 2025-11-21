#pragma once

#include <vector>
#include "VarTable.hpp"
#include "VirtualMemoryManager.hpp"
#include "ConstTable.hpp"

struct FuncEntry {
    VarTable localVars;
    ConstTable localConsts;
    VirtualMemoryManager* memManager;

    int start;
    std::string name;
    vartype returnType;
    std::vector<std::pair<std::string, vartype>> parameters;

    FuncEntry(): returnType(vartype::void_type), memManager(nullptr) {}
    FuncEntry(std::string n, vartype r) : name(n), returnType(r), memManager(new VirtualMemoryManager()) {}
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