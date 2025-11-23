#include "Memory.hpp"

Memory::Memory() {
    
}

Memory::Memory(VirtualMemoryManager* virtualMem) {
    mem = proxyarr<proxyarr<proxyarr<datatypes>>>(4);  // global local temps const = 4

    for (int i = 0; i < 4; i++){
        mem[i] = proxyarr<proxyarr<datatypes>>(virtualMem->dataTypes - 1);
    
        for (int j = 0; j < virtualMem->dataTypes - 1; j++){
            mem[i][j] = proxyarr<datatypes>(virtualMem->count[i][j]);
        }
    }

    this->virtualMem = virtualMem;

    if (virtualMem->global) {
        for (auto it = virtualMem->constTable.check.begin(); it != virtualMem->constTable.check.end(); ++it) {
            operand o = virtualMem->constTable.table[it->second];
            int index = virtualMem->getIndex(o);
            mem[memorytype::const_][o.type][index] = it->first;
        }
    }
}

