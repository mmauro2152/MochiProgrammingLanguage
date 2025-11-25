#pragma once

#include "VarTable.hpp"
#include "operand.hpp"
#include "proxyarr.hpp"
#include <vector>
#include "memorytype.hpp"
#include "ConstTable.hpp"

class Memory;
struct reserve;

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

class VirtualAddressManager
{
private:
    static proxyarr<int> pads;
    const static int memSize = 15000;

    const static int dataTypes = 5;
    counter count;

    std::string scope;
    
    static int getMemoryRange(memorytype memtype);

    bool global = false;

    ConstTable constTable;

    friend class Memory;
    friend struct reserve;

public:
    VirtualAddressManager();

    int getAddress(memorytype memytype, vartype datatype);

    operand getTemp(vartype t);
    operand getConst(std::string strValue, datatypes value, vartype t);

    void setscope(std::string s) {
        scope = s;
    }

    std::string getscope() { return scope; }

    std::string getTempStr(int addr, vartype t);

    void setAsGlobal() { global = true; }

    static int getIndex(operand o);
};