#include "VarTable.hpp"

bool VarTable::insert(const std::string& name, vartype type) {
    if (exists(name)) {
        std::cerr << "Error: Variable '" << name << "' already declared.\n";
        return false;
    }

    table[name] = VarEntry(type);
    return true;
}

bool VarTable::exists(const std::string& name) const {
    return table.find(name) != table.end();
}

VarEntry* VarTable::getVar(const std::string& name) {
    if (exists(name)) {
        return &table[name];
    }
    
    std::cerr << "Error: Variable '" << name << "' does not exist.\n";
    return nullptr;
}

bool VarTable::empty() {
    return table.empty();
}

void VarTable::printAll() {
    std::unordered_map<std::string, VarEntry>::iterator it;
    for (it = table.begin(); it != table.end(); ++it) {
        std::cout << it->first << ", " << typeToString(it->second.type) << std::endl;
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

