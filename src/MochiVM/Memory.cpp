#include "Memory.hpp"

Memory::Memory() {
    
}

Memory::Memory(VirtualAddressManager* virtualMem) {
    // global local temps const = 4 segmentos de memoria
    mem = proxyarr<proxyarr<proxyarr<cell*>>>(4);  

    for (int i = 0; i < 4; i++){
        // int, float, string, bool = 4 tipos de datos
        mem[i] = proxyarr<proxyarr<cell*>>(virtualMem->dataTypes);
        
        for (int j = 0; j < virtualMem->dataTypes; j++){
            mem[i][j] = proxyarr<cell*>(virtualMem->count[i][j]);

            for (int k = 0; k < virtualMem->count[i][j]; k++) {
                switch (j) {
                    case 0:
                        mem[i][j][k] = new cell(false, 0);
                        break;

                    case 1:
                        mem[i][j][k] = new cell(false, 0.0f);
                        break;

                    case 2:
                        mem[i][j][k] = new cell(false, "");
                        break;

                    case 3:
                        mem[i][j][k] = new cell(false, false);
                        break;

                    default:
                        break;
                }
            }
        }
    }

    this->addrManager = virtualMem;

    if (virtualMem->global) {
        for (auto it = virtualMem->constTable.check.begin(); it != virtualMem->constTable.check.end(); ++it) {
            operand o = virtualMem->constTable.table[it->second];
            int index = virtualMem->getIndex(o);
            mem[memorytype::const_][o.type][index] = new cell(it->first);
        }
    }
}

