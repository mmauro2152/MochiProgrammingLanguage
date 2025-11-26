#pragma once

#include "../VirtualAddressManager.hpp"
#include "datatypes.hpp"


class Memory {
    private:
        proxyarr<proxyarr<proxyarr<datatypes>>> mem;
        VirtualAddressManager* addrManager;

    public:
        Memory();
        Memory(VirtualAddressManager* virtualMem);

        proxyarr<proxyarr<datatypes>>& operator[](int i) {
            return mem[i];
        }

        proxyarr<proxyarr<datatypes>>& operator[](memorytype m) {
            return mem[static_cast<int>(m)];
        }
 };