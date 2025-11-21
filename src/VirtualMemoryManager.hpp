#pragma once

#include "VarTable.hpp"
#include "operand.hpp"
#include <vector>

class VirtualMemoryManager
{
private:
    int globalPad = 0;
    int localPad = 5000;
    int tempPad = 10000;
    int constPad = 14000;
    int memSize = 15000;

    int dataTypes = 4;
    int** counters;

    std::string scope;

public:
    VirtualMemoryManager();

    int getGlobalAddress(vartype t);
    int getLocalAddress(vartype t);
    int getTempAddress(vartype t);
    int getConstAddress(vartype t);

    operand getTemp(vartype t);
    operand getConst(std::string strValue, vartype t);

    void setscope(std::string s) {
        scope = s;
    }

    std::string getscope() { return scope; }

    std::string getTempStr(int addr, vartype t);
};