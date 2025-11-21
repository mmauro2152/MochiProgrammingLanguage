#pragma once

#include <string>
#include <unordered_map>
#include <iostream>

enum class vartype {
    int_type,
    float_type,
    string_type,
    bool_type,
    void_type,
    unknown,
    none,
    func
};

static const std::string vartype_string[] {
    "int", "float", "string", "bool", "void", "unknown", "none", "func"
};


struct VarEntry
{
    vartype type;
    int addr;
    std::string name;

    VarEntry(): type(vartype::void_type), addr(-1), name("") {}
    VarEntry(vartype t, int a, std::string n):  type(t), addr(a), name(n) {}
};


class VarTable {
private:
    std::unordered_map<int, VarEntry> table;
    std::unordered_map<std::string, int> nameToAddr;

public:
    bool insert(const int& addr, vartype type, std::string name);

    bool exists(const int& addr);

    bool exists(const std::string& name);

    VarEntry* getVar(const int& addr);

    VarEntry* getVar(const std::string& name);

    bool empty();

    void printAll();
    
    static std::string typeToString(vartype type);
};
