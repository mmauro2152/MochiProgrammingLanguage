#pragma once

#include "../VirtualMemoryManager.hpp"
#include "datatypes.hpp"


class Memory {
    private:
        proxyarr<proxyarr<proxyarr<datatypes>>> mem;
        VirtualMemoryManager* virtualMem;

    public:
        Memory();
        Memory(VirtualMemoryManager* virtualMem);

        proxyarr<proxyarr<datatypes>>& operator[](int i) {
            return mem[i];
        }

        proxyarr<proxyarr<datatypes>>& operator[](memorytype m) {
            return mem[static_cast<int>(m)];
        }
 };