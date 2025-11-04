#include "FuncDir.hpp"

bool FuncDir::insertFunction(const std::string& name, VarType returnType) {
    if (exists(name)) {
        std::cerr << "Error: Function '" << name << "' already declared.\n";
        return false;
    }

    table[name] = FuncEntry(returnType);
    return true;
}

bool FuncDir::exists(const std::string& name) {
    return table.find(name) != table.end();
}

bool FuncDir::addParameter(const std::string& name, const std::string& paramName, VarType paramType){
    if (!exists(name)) {
        std::cerr << "Error: Function '" << name << "' does not exist" << std::endl;
        return false;
    }

    table[name].parameters.push_back({paramName, paramType});
    table[name].localVars.insert(paramName, paramType);
    return true;
}

FuncEntry* FuncDir::getFunction(const std::string& name) {
    if (exists(name)) {
        return &table[name];
    }

    return nullptr;
}

void FuncDir::printAll() {
    std::unordered_map<std::string, FuncEntry>::iterator it;
    for (it = table.begin(); it != table.end(); ++it){
        std::cout << "Function: " << it->first << std::endl;
        
        std::cout << "Return type: " << VarTable::typeToString(it->second.returnType) << std::endl;

        if (!it->second.parameters.empty()) {
            std::cout << "Parameters:" << std::endl;

            for (std::pair<std::string, VarType> p : it->second.parameters){
                std::cout << p.first << ", " << VarTable::typeToString(p.second) << std::endl;
            }
        }

        if (!it->second.localVars.empty()) {
            std::cout << "Local variables:" << std::endl;

            it->second.localVars.printAll();
        }
    }
}

