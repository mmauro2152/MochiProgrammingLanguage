#pragma once 

#include "../SemanticCube.hpp"
#include "Memory.hpp"
#include "datatypes.hpp"

datatypes applyUnaryOperator(int i, operatortype o) {
    std::string temp;

    switch(o) {
        case operatortype::minus:
            return -i;

        case operatortype::plus:
        case operatortype::assign:
            return i;

        case operatortype::plusplus:
            return i + 1;

        case operatortype::minusminus:
            return i - 1;

        case operatortype::input:
            std::getline(std::cin, temp);
            return std::stoi(temp); 

        default:
            throw std::runtime_error("Invalid operation");
            return i;
    }
}

datatypes applyUnaryOperator(bool b, operatortype o) {
    std::string temp;

    switch(o) {
        case operatortype::not_:
            return !b;
        
        case operatortype::assign:
            return b;

        case operatortype::input:
            std::getline(std::cin, temp);
            return temp == "true";

        default:
            throw std::runtime_error("Invalid operation");
            return b;
    }
}

datatypes applyUnaryOperator(float f, operatortype o) {
    std::string temp;

    switch(o) {
        case operatortype::minus:
            return -f;

        case operatortype::plus:
        case operatortype::assign:
            return f;

        case operatortype::input:
            std::getline(std::cin, temp);
            return std::stof(temp);

        default:
            throw std::runtime_error("Invalid operation");
            return f;
    }
}

datatypes applyUnaryOperator(std::string s, operatortype o) {
    std::string temp;

    switch (o) {
        case operatortype::assign:
            return s;

        case operatortype::len:
            return static_cast<int>(s.size());

        case operatortype::upper:
            temp.reserve(s.size());

            for (char c : s) {
                temp.push_back(std::toupper(static_cast<unsigned char>(c)));
            }

            return temp;

        case operatortype::lower:
            temp.reserve(s.size());

            for (char c : s) {
                temp.push_back(std::tolower(static_cast<unsigned char>(c)));
            }

            return temp;

        case operatortype::input:
            std::getline(std::cin, s);
            return s;

        default:
            throw std::runtime_error("Invalid operation");
            return s;
    }
}

struct unaryFunctor {
    operatortype operator_;
    
    template <typename T>
    datatypes operator()(T& item) { return applyUnaryOperator(item, operator_); }

    unaryFunctor(): operator_(operatortype::unknown) {}
    unaryFunctor(operatortype o): operator_(o) {}
};


datatypes applyBinaryOperator(int left, int right, operatortype o) {
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

datatypes applyBinaryOperator(float left, float right, operatortype o) {
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

datatypes applyBinaryOperator(int left, float right, operatortype o) {
    return applyBinaryOperator((float)left, right, o);
}

datatypes applyBinaryOperator(float left, int right, operatortype o) {
    return applyBinaryOperator(left, (float)right, o);
}

datatypes applyBinaryOperator(bool left, bool right, operatortype o) {
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

datatypes applyBinaryOperator(std::string left, std::string right, operatortype o) {
    switch (o)
    {
        case operatortype::equal:
            return left == right;
        
        case operatortype::not_equal:
            return left != right;

        case operatortype::plus:
            return left + right;
    
        default:
            throw std::runtime_error("Invalid operation");
            return "";
    }
}

datatypes applyBinaryOperator(std::string left, int right, operatortype o) {
    switch (o)
    {
        case operatortype::subscript:
            return std::string(1, left[right]);
        
        default:
            throw std::runtime_error("Invalid operation");
            return "";
    }
}

template <typename A, typename B>
datatypes applyBinaryOperator(A left, B right, operatortype o) {
    throw std::runtime_error("Invalid operation");
}

struct binaryFunctor {
    operatortype operator_;
    
    template <typename Tl, typename Tr>
    datatypes operator()(Tl& left, Tr& right) { 
        return applyBinaryOperator(left, right, operator_); 
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