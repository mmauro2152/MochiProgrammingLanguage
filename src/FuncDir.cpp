#include "FuncDir.hpp"

bool FuncDir::insertFunction(const std::string& name, vartype returnType) {
    if (exists(name)) {
        std::cerr << "Error: Function '" << name << "' already declared.\n";
        return false;
    }

    table[name] = FuncEntry(name, returnType);
    table[name].memManager->setscope(name);
    return true;
}

bool FuncDir::exists(const std::string& name) {
    return table.find(name) != table.end();
}

bool FuncDir::addParameter(const std::string& name, const std::string& paramName, vartype paramType){
    if (!exists(name)) {
        std::cerr << "Error: Function '" << name << "' does not exist" << std::endl;
        return false;
    }


    table[name].parameters.push_back({paramName, paramType});
    table[name].localVars.insert(table[name].memManager->getLocalAddress(paramType), paramType, paramName);
    return true;
}

FuncEntry* FuncDir::getFunction(const std::string& name) {
    if (exists(name)) {
        return &table[name];
    }

    return nullptr;
}

void FuncDir::setGlobalScope(const std::string& scope){
    globalScope = scope;
}

void FuncDir::printAll() {
    std::unordered_map<std::string, FuncEntry>::iterator it;
    for (it = table.begin(); it != table.end(); ++it){
        std::cout << "Function: " << it->first << std::endl;
        
        std::cout << "Return type: " << VarTable::typeToString(it->second.returnType) << std::endl;

        if (!it->second.parameters.empty()) {
            std::cout << "Parameters:" << std::endl;

            for (std::pair<std::string, vartype> p : it->second.parameters){
                std::cout << p.first << ", " << VarTable::typeToString(p.second) << std::endl;
            }
        }

        if (!it->second.localVars.empty()) {
            std::cout << "Local variables:" << std::endl;

            it->second.localVars.printAll();
        }
    }
}

VarEntry* FuncDir::getVar(const std::string& scope, const std::string& varName) {
    FuncEntry* func = getFunction(scope);

    if (func == nullptr){
        std::cerr << "Error: scope '" << scope << "' does not exist" << std::endl;
        return nullptr;
    }
    else if (!func->localVars.exists(varName)) {
        // try global scope
        func = getFunction(globalScope);

        if (func == nullptr) {
            std::cerr << "Scope '" << scope << "' does not exist" << std::endl;
            return nullptr;
        }
        else {
            return func->localVars.getVar(varName);
        }
    }

    return func->localVars.getVar(varName);
}
