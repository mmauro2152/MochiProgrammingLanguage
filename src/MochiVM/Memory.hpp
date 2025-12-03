#pragma once

#include "../VirtualAddressManager.hpp"
#include "datatypes.hpp"

struct cell {
    bool initialized = false;
    datatypes value;

    void setvalue(datatypes v) {
        value = v;
        initialized = true;
    }

    cell (): value(0) {}
    cell (datatypes v): initialized(true), value(v) {}
    cell (bool i, datatypes v): initialized(i), value(v) {}
};

class Memory {
    private:
        proxyarr<proxyarr<proxyarr<cell>>> mem;
        VirtualAddressManager* addrManager;

    public:
        Memory();
        Memory(VirtualAddressManager* virtualMem);

        proxyarr<proxyarr<cell>>& operator[](int i) {
            return mem[i];
        }

        proxyarr<proxyarr<cell>>& operator[](memorytype m) {
            return mem[static_cast<int>(m)];
        }
 };