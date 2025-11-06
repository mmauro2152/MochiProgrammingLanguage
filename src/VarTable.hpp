#pragma once

#include <string>
#include <unordered_map>
#include <iostream>

enum class vartype {
    int_type,
    float_type,
    string_type,
    void_type,
    bool_type,
    unknown,
    none
};

static const char* vartype_string[] {
    "int", "float", "string", "void", "bool", "unknown", "none"
};


struct VarEntry
{
    vartype type;

    VarEntry(): type(vartype::void_type) {}
    VarEntry(vartype t):  type(t) {}
};


class VarTable {
private:
    std::unordered_map<std::string, VarEntry> table;

public:
    bool insert(const std::string& name, vartype type);

    bool exists(const std::string& name) const;

    VarEntry* getVar(const std::string& name);

    bool empty();

    void printAll();
    
    static std::string typeToString(vartype type);
};
