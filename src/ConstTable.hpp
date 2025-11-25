#pragma once
#include "VarTable.hpp"
#include <unordered_map>
#include "MochiVM/datatypes.hpp"

class VirtualAddressManager;
class Memory;

class ConstTable {
    friend class VirtualAddressManager;
    friend class Memory;

    private:
        std::unordered_map<int, operand> table;
        std::unordered_map<datatypes, int> check;

    public:
        bool addrExists(int addr) {
            return table.find(addr) != table.end();
        }

        bool valueExists(datatypes value) {
            return check.find(value) != check.end();
        }
};
