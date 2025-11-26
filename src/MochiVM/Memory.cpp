#include "Memory.hpp"

Memory::Memory() {
    
}

Memory::Memory(VirtualAddressManager* virtualMem) {
    // global local temps const = 4 segmentos de memoria
    mem = proxyarr<proxyarr<proxyarr<datatypes>>>(4);  

    for (int i = 0; i < 4; i++){
        // int, float, string, bool = 4 tipos de datos
        mem[i] = proxyarr<proxyarr<datatypes>>(virtualMem->dataTypes);
        
        for (int j = 0; j < virtualMem->dataTypes; j++){
            mem[i][j] = proxyarr<datatypes>(virtualMem->count[i][j]);
        }
    }

    this->addrManager = virtualMem;

    if (virtualMem->global) {
        for (auto it = virtualMem->constTable.check.begin(); it != virtualMem->constTable.check.end(); ++it) {
            operand o = virtualMem->constTable.table[it->second];
            int index = virtualMem->getIndex(o);
            mem[memorytype::const_][o.type][index] = it->first;
        }
    }
}

