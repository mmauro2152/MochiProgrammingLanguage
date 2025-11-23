#pragma once

#include <variant>
#include <string>

using datatypes = std::variant<
    int,
    float,
    std::string,
    bool
>;