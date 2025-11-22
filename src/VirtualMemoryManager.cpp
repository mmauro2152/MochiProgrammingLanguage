#include "VirtualMemoryManager.hpp"

VirtualMemoryManager::VirtualMemoryManager() {
    count = counter(4, dataTypes);
    
    int* p = new int[5]{0, 5000, 10000, 14000, 15000};
    pads = proxyarr<int>(p);
}

int VirtualMemoryManager::getAddress(memorytype memtype, vartype datatype) {
    int memRange = getMemoryRange(memtype);
    int typePad = (memRange / dataTypes) * static_cast<int>(datatype);
    int address = count[memtype][datatype]++ + pads[memtype] + typePad;

    if (address >= pads[memtype] + memRange) {
        std::cerr << "Ran out of " << memtype_string[memtype] << "memory" << std::endl;
    }

    return address;
}

int VirtualMemoryManager::getMemoryRange(memorytype memtype) {
    return pads[static_cast<int>(memtype) + 1] - pads[memtype];
}

operand VirtualMemoryManager::getTemp(vartype t) {
    int addr = getAddress(memorytype::temp, t);
    
    return operand(t, scope, addr, memorytype::temp, getTempStr(addr, t));
}

operand VirtualMemoryManager::getConst(std::string strValue, vartype t) {
    return operand(t, scope, getAddress(memorytype::const_, t), memorytype::const_, strValue);
}

std::string VirtualMemoryManager::getTempStr(int addr, vartype t) {
    int typePad = (getMemoryRange(memorytype::temp) / dataTypes) * static_cast<int>(t);
    return "t" + std::string(1, vartype_string[t][0]) + std::to_string(addr - typePad - pads[memorytype::temp]);
}
