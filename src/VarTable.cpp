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
    table[addr] = VarEntry(type, addr, name, mem);
    return true;
}

bool VarTable::exists(const int& addr) {
    return table.find(addr) != table.end();
}

bool VarTable::exists(const std::string& name) {
    return nameToAddr.find(name) != nameToAddr.end();
}

VarEntry* VarTable::getVar(const int& addr) {
    if (exists(addr)) {
        return &table[addr];
    }
    
    std::cerr << "Error: Variable '" << addr << "' does not exist.\n";
    return nullptr;
}

VarEntry* VarTable::getVar(const std::string& name) {
    if (exists(name)) {
        return &table[nameToAddr[name]];
    }
    
    std::cerr << "Error: Variable '" << name << "' does not exist.\n";
    return nullptr;
}

bool VarTable::empty() {
    return table.empty();
}

void VarTable::printAll() {
    std::unordered_map<int, VarEntry>::iterator it;
    for (it = table.begin(); it != table.end(); ++it) {
        std::cout << it->second.name << ", " << typeToString(it->second.type) << std::endl;
    }
}

std::string VarTable::typeToString(vartype type) {
    switch(type){
        case (vartype::float_type):
            return "float";

        case (vartype::int_type):
            return "int";

        case (vartype::string_type):
            return "string";

        case (vartype::void_type):
            return "void";

        default:
            std::cerr << "Invalid var type" << std::endl;
            return nullptr;
    }
}

