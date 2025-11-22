#include "Memory.hpp"

Memory::Memory() {
    
}

Memory::Memory(VirtualMemoryManager* virtualMem) {
    mem = proxyarr<proxyarr<arraytypes>>(4); // global local temps const = 4

    for (int i = 0; i < 4; i++){
        mem[i] = proxyarr<arraytypes>(virtualMem->dataTypes);

        mem[i][0] = proxyarr<int>(virtualMem->count[i][0]);
        mem[i][1] = proxyarr<float>(virtualMem->count[i][1]);
        mem[i][2] = proxyarr<std::string>(virtualMem->count[i][2]);
        mem[i][3] = proxyarr<bool>(virtualMem->count[i][3]);
    }
}

