#include "QuadManager.hpp"

operand QuadManager::getTemp(vartype type) {
    return operand(type, tempScope, "t" + std::to_string(++tempCount));
}

void QuadManager::push(quad q) {
    quads.push(q);
}