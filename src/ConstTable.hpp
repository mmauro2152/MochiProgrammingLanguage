#pragma once
#include "VarTable.hpp"
#include <unordered_map>

struct ConstEntry
{
    vartype type;
    std::string value;

    ConstEntry(): type(vartype::unknown), value("") {}
    ConstEntry(vartype t, std::string v): type(t), value(v) {}
};

class ConstTable {
    private:
        std::unordered_map<int, ConstEntry> table;

    public:
        bool exists(int addr) {
            return table.find(addr) != table.end();
        }

        ConstEntry* getConst(int addr) {
            if (exists(addr)) 
                return &table[addr];

            std::cerr << "Address '" << addr << "' holds no value" << std::endl;
            
            return nullptr;
        }

        bool setConst(int addr, ConstEntry entry) {
            if (exists(addr)) {
                std::cerr << "Addres '" << addr << "' already in use" << std::endl;
                return false;
            }

            table[addr] = entry;
            return true;
        }
};
