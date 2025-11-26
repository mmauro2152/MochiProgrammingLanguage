#pragma once 

#include "../SemanticCube.hpp"
#include "Memory.hpp"
#include "datatypes.hpp"

datatypes applyUnaryOperator(int i, operatortype o) {
    switch(o) {
        case operatortype::minus:
            return -i;

        case operatortype::plus:
        case operatortype::assign:
            return i;

        default:
            throw std::runtime_error("Invalid operation");
            return i;
    }
}

datatypes applyUnaryOperator(bool b, operatortype o) {
    switch(o) {
        case operatortype::not_:
            return !b;

        case operatortype::assign:
            return b;

        default:
            throw std::runtime_error("Invalid operation");
            return b;
    }
}

datatypes applyUnaryOperator(float f, operatortype o) {
    switch(o) {
        case operatortype::minus:
            return -f;

        case operatortype::plus:
        case operatortype::assign:
            return f;

        default:
            throw std::runtime_error("Invalid operation");
            return f;
    }
}

datatypes applyUnaryOperator(std::string s, operatortype o) {
    if (o == operatortype::assign)
        return s;

    throw std::runtime_error("Invalid operation");
    return s;
}

struct unaryFunctor {
    operatortype operator_;
    
    template <typename T>
    datatypes operator()(T& item) { return applyUnaryOperator(item, operator_); }

    unaryFunctor(): operator_(operatortype::unknown) {}
    unaryFunctor(operatortype o): operator_(o) {}
};

// template <typename Tl, typename Tr>
// datatypes applyBinaryOperator(Tl& left, Tr& right, operatortype o) {
//     return applyBinaryOperator_(left, right, o);
// }

datatypes applyBinaryOperator_(int left, int right, operatortype o) {
    switch(o) {
        case operatortype::plus:
            return left + right;

        case operatortype::minus:
            return left - right;

        case operatortype::asterisk:
            return left * right;

        case operatortype::slash:
            return left / right;

        case operatortype::equal_smaller_than:
            return left <= right;

        case operatortype::smaller_than:
            return left < right;

        case operatortype::equal_greater_than:
            return left >= right;

        case operatortype::greater_than:
            return left > right;

        case operatortype::equal:
            return left == right;
        
        case operatortype::not_equal:
            return left != right;

        default:
            throw std::runtime_error("Invalid operation");
            return 0;
    }
}

datatypes applyBinaryOperator_(float left, float right, operatortype o) {
    switch(o) {
        case operatortype::plus:
            return left + right;

        case operatortype::minus:
            return left - right;

        case operatortype::asterisk:
            return left * right;

        case operatortype::slash:
            return left / right;

        case operatortype::equal:
            return left == right;
        
        case operatortype::not_equal:
            return left != right;

        case operatortype::equal_smaller_than:
            return left <= right;

        case operatortype::smaller_than:
            return left < right;

        case operatortype::equal_greater_than:
            return left >= right;

        case operatortype::greater_than:
            return left > right;

        default:
            throw std::runtime_error("Invalid operation");
            return 0;
    }
}

datatypes applyBinaryOperator_(int left, float right, operatortype o) {
    return applyBinaryOperator_((float)left, right, o);
}

datatypes applyBinaryOperator_(float left, int right, operatortype o) {
    return applyBinaryOperator_(left, (float)right, o);
}

datatypes applyBinaryOperator_(bool left, bool right, operatortype o) {
    switch (o) {
        case operatortype::equal:
            return left == right;
        
        case operatortype::not_equal:
            return left != right;

        case operatortype::and_:
            return left && right;

        case operatortype::or_:
            return left || right;

        default:
            throw std::runtime_error("Invalid operation");
            return false;
    }
}

datatypes applyBinaryOperator_(std::string left, std::string right, operatortype o) {
    switch (o)
    {
        case operatortype::equal:
            return left == right;
        
        case operatortype::not_equal:
            return left != right;
    
        default:
            throw std::runtime_error("Invalid operation");
            return "";
    }
}

template <typename A, typename B>
datatypes applyBinaryOperator_(A left, B right, operatortype o) {
    throw std::runtime_error("Invalid operation");
}

struct binaryFunctor {
    operatortype operator_;
    
    template <typename Tl, typename Tr>
    datatypes operator()(Tl& left, Tr& right) { 
        return applyBinaryOperator_(left, right, operator_); 
    }

    binaryFunctor(): operator_(operatortype::unknown) {}
    binaryFunctor(operatortype o): operator_(o) {}
};


void applyPrintOperator(int i, bool e) { 
    std::cout << i; 

    if (e)
        std::cout << std::endl;
}

void applyPrintOperator(float f, bool e) { 
    std::cout << f; 

    if (e)
        std::cout << std::endl;
}

void applyPrintOperator(std::string s, bool e) { 
    std::cout << s; 

    if (e)
        std::cout << std::endl;
}

void applyPrintOperator(bool b, bool e) { 
    std::cout << ((b) ? "true" : "false"); 

    if (e)
        std::cout << std::endl;
}

struct printFunctor {
    bool endl;

    template<typename T>
    void operator()(T& item) { applyPrintOperator(item, endl); }

    printFunctor(bool e): endl(e) {}
};