#pragma once

#include "../VirtualMemoryManager.hpp"
#include <variant>

class Memory {
    public:
        using arraytypes = std::variant<
            proxyarr<int>,
            proxyarr<float>,
            proxyarr<std::string>,
            proxyarr<bool>
        >;

    private:
        proxyarr<proxyarr<arraytypes>> mem;

    public:
        Memory();
        Memory(VirtualMemoryManager* virtualMem);

        proxyarr<arraytypes>& operator[](int i) {
            return mem[i];
        }

        proxyarr<arraytypes>& operator[](memorytype m) {
            return mem[static_cast<int>(m)];
        }
 };