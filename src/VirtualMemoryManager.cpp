#include "VirtualMemoryManager.hpp"

proxyarr<int> VirtualMemoryManager::pads{};

VirtualMemoryManager::VirtualMemoryManager() {
    count = counter(4, dataTypes);
    
    if (VirtualMemoryManager::pads.isnull()) {
        int* p = new int[5]{0, 5000, 10000, 14000, 15000};
        VirtualMemoryManager::pads = proxyarr<int>(p);
    }
}

int VirtualMemoryManager::getAddress(memorytype memtype, vartype datatype) {
    int memRange = getMemoryRange(memtype);
    int typePad = (memRange / dataTypes) * static_cast<int>(datatype);
    int address = count[memtype][datatype]++ + VirtualMemoryManager::pads[memtype] + typePad;

    if (address >= VirtualMemoryManager::pads[memtype] + memRange) {
        std::cerr << "Ran out of " << memtype_string[memtype] << "memory" << std::endl;
    }

    return address;
}

int VirtualMemoryManager::getMemoryRange(memorytype memtype) {
    return VirtualMemoryManager::pads[static_cast<int>(memtype) + 1] - VirtualMemoryManager::pads[memtype];
}

operand VirtualMemoryManager::getTemp(vartype t) {
    int addr = getAddress(memorytype::temp, t);
    
    return operand(t, scope, addr, memorytype::temp, getTempStr(addr, t));
}

operand VirtualMemoryManager::getConst(std::string strValue, datatypes value, vartype t) {
    if (constTable.valueExists(value)) {
        return constTable.table[constTable.check[value]];
    } else {
        int addr = getAddress(memorytype::const_, t);
        operand o(t, scope, addr, memorytype::const_, strValue);
        constTable.table[addr] = o;
        constTable.check[value] = addr;

        return o;
    }
}

std::string VirtualMemoryManager::getTempStr(int addr, vartype t) {
    int typePad = (getMemoryRange(memorytype::temp) / dataTypes) * static_cast<int>(t);
    return "t" + std::string(1, vartype_string[t][0]) + std::to_string(addr - typePad - VirtualMemoryManager::pads[memorytype::temp]);
}

int VirtualMemoryManager::getIndex(operand o) {
    int memRange = getMemoryRange(o.mem);
    int typePad = (memRange / dataTypes) * static_cast<int>(o.type);

    return o.addr - VirtualMemoryManager::pads[o.mem] - typePad;
}
