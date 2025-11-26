#include "VirtualAddressManager.hpp"

proxyarr<int> VirtualAddressManager::memOffset{};

VirtualAddressManager::VirtualAddressManager() {
    count = counter(4, dataTypes);
    
    if (memOffset.isnull()) {
        int* p = new int[5]{0, 5000, 10000, 14000, 15000};
        memOffset = proxyarr<int>(p);
    }
}

int VirtualAddressManager::getAddress(memorytype memtype, vartype datatype) {
    if (datatype == vartype::void_type) {
        std::cout << "error" << std::endl;
    }

    int memRange = getMemoryRange(memtype);
    int typeOffset = (memRange / dataTypes) * static_cast<int>(datatype);
    int address = count[memtype][datatype]++ + memOffset[memtype] + typeOffset;

    if (address >= memOffset[memtype] + memRange) {
        std::cerr << "Ran out of " << memtype_string[memtype] << "memory" << std::endl;
    }

    return address;
}

int VirtualAddressManager::getMemoryRange(memorytype memtype) {
    return memOffset[static_cast<int>(memtype) + 1] - memOffset[memtype];
}

operand VirtualAddressManager::getTemp(vartype t) {
    int addr = getAddress(memorytype::temp, t);
    
    return operand(t, scope, addr, memorytype::temp, getTempStr(addr, t));
}

operand VirtualAddressManager::getConst(std::string strValue, datatypes value, vartype t) {
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

std::string VirtualAddressManager::getTempStr(int addr, vartype t) {
    int typeOffset = (getMemoryRange(memorytype::temp) / dataTypes) * static_cast<int>(t);
    return "t" + std::string(1, vartype_string[t][0]) + std::to_string(addr - typeOffset - memOffset[memorytype::temp]);
}

int VirtualAddressManager::getIndex(operand o) {
    int memRange = getMemoryRange(o.mem);
    int typeOffset = (memRange / dataTypes) * static_cast<int>(o.type);

    return o.addr - memOffset[o.mem] - typeOffset;
}
