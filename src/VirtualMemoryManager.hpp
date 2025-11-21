#pragma once

#include "VarTable.hpp"
#include "operand.hpp"
#include "proxyarr.hpp"
#include <vector>

enum class memorytype {
    global,
    local,
    temp,
    const_
};

static std::string* s = new std::string[4]{"global", "local", "temp", "const"};
static proxyarr<std::string> memtype_string = proxyarr<std::string>(s);

struct counter {
    proxyarr<int>* counters;

    template <typename enum_>
    proxyarr<int> operator[](enum_ e) {
        return counters[static_cast<int>(e)];
    }

    proxyarr<int> operator[](int i) {
        return counters[i];
    }

    counter(): counters(nullptr) {}
    counter(int r, int c): counters(new proxyarr<int>[r]) {
        for (int i = 0; i < r; i++) {
            counters[i] = proxyarr<int>(c);
            for (int j = 0; j < c; j++){
                counters[i][j] = 0;
            }
        }
    }
};

class VirtualMemoryManager
{
private:
    int globalPad = 0;
    int localPad = 5000;
    int tempPad = 10000;
    int constPad = 14000;

    proxyarr<int> pads;
    int memSize = 15000;

    int dataTypes = 4;
    int** counters;
    counter count;

    std::string scope;
    
    int getMemoryRange(memorytype memtype);

public:
    VirtualMemoryManager();

    int getAddress(memorytype memytype, vartype datatype);

    operand getTemp(vartype t);
    operand getConst(std::string strValue, vartype t);

    void setscope(std::string s) {
        scope = s;
    }

    std::string getscope() { return scope; }

    std::string getTempStr(int addr, vartype t);
};