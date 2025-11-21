#include "VirtualMemoryManager.hpp"

VirtualMemoryManager::VirtualMemoryManager() {
    counters = new int*[4];

    for (int i = 0; i < 4; i++){
        counters[i] = new int[dataTypes];
        for (int j = 0; j < dataTypes; ++j) {
            counters[i][j] = 0;
        }
    }   
}

int VirtualMemoryManager::getGlobalAddress(vartype t) {
    int typePad = (5000 / dataTypes) * static_cast<int>(t);

    int address = counters[0][static_cast<int>(t)]++ + globalPad + typePad;

    if (address > globalPad + 5000)
        std::cerr << "Ran out of global memory" << std::endl;

    return address;
}

int VirtualMemoryManager::getLocalAddress(vartype t) {
    int typePad = (5000 / dataTypes) * static_cast<int>(t);
    int address = counters[1][static_cast<int>(t)]++ + localPad + typePad;

    if (address > localPad + 5000)
        std::cerr << "Ran out of local memory" << std::endl;

    return address;
}

int VirtualMemoryManager::getTempAddress(vartype t) {
    int typePad = (5000 / dataTypes) * static_cast<int>(t);
    int address = counters[2][static_cast<int>(t)]++ + tempPad + typePad;

    if (address > tempPad + 4000)
        std::cerr << "Ran out of temp memory" << std::endl;

    return address;
}

int VirtualMemoryManager::getConstAddress(vartype t) {
    int typePad = (100 / dataTypes) * static_cast<int>(t);
    int address = counters[3][static_cast<int>(t)]++ + constPad + typePad;

    if (address > constPad + 1000)
        std::cerr << "Ran out of const memory" << std::endl;

    return address;
}

operand VirtualMemoryManager::getTemp(vartype t) {
    int addr = getTempAddress(t);
    return operand(t, scope, addr, operandcat::temp, getTempStr(addr, t));
}

operand VirtualMemoryManager::getConst(std::string strValue, vartype t) {
    return operand(t, scope, getConstAddress(t), operandcat::const_, strValue);
}

std::string VirtualMemoryManager::getTempStr(int addr, vartype t) {
    int typePad = (5000 / dataTypes) * static_cast<int>(t);
    return "t" + std::string(1, vartype_string[static_cast<int>(t)][0]) + std::to_string(addr - typePad - tempPad);
}
