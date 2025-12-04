#include "VarTable.hpp"

bool VarTable::insert(const int& addr, vartype type, std::string name, memorytype mem) {
    if (exists(name)) {
        std::cerr << "Error: Variable '" << addr << "' already declared.\n";
        return false;
    }
    else if (exists(addr)) {
        std::cerr << "Error: Address '" << addr << "' already in use.\n";
        return false;
    }

    nameToAddr[name] = addr;
    table[addr] = operand(type, scope, addr, mem, name);
    return true;
}

bool VarTable::exists(const int& addr) {
    return table.find(addr) != table.end();
}

bool VarTable::exists(const std::string& name) {
    return nameToAddr.find(name) != nameToAddr.end();
}

operand VarTable::getVar(const int& addr) {
    if (exists(addr)) {
        return table[addr];
    }
    
    std::cerr << "Error: Variable '" << addr << "' does not exist.\n";
    return operand();
}

operand VarTable::getVar(const std::string& name) {
    if (exists(name)) {
        return table[nameToAddr[name]];
    }
    
    std::cerr << "Error: Variable '" << name << "' does not exist.\n";
    return operand();
}

bool VarTable::empty() {
    return table.empty();
}

void VarTable::printAll() {
    for (auto it = table.begin(); it != table.end(); ++it) {
        std::cout << it->second.str << ", " << vartype_string[it->second.type] << std::endl;
    }
}
