#pragma once

#include <string>
#include <unordered_map>
#include <iostream>

enum class VarType {
    INT,
    FLOAT,
    STRING,
    VOID
};

struct VarEntry
{
    VarType type;

    VarEntry(): type(VarType::VOID) {}
    VarEntry(VarType t):  type(t) {}
};


class VarTable {
private:
    std::unordered_map<std::string, VarEntry> table;

public:
    bool insert(const std::string& name, VarType type);

    bool exists(const std::string& name) const;

    VarEntry* getVar(const std::string& name);

    bool empty();

    void printAll();
    
    static std::string typeToString(VarType type);
};
