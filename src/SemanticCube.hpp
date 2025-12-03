#pragma once 
#include "VarTable.hpp"
#include "MochiParser/MochiParser.tab.hpp"
#include "proxyarr.hpp"

enum class operatortype {
    plusplus,
    minusminus,
    plus,
    minus,
    asterisk,
    slash,
    equal_smaller_than,
    smaller_than,
    equal_greater_than,
    greater_than,
    equal,
    assign,
    not_equal,
    not_,
    and_,
    or_,
    subscript,
    len,
    upper,
    lower,
    unknown,
    call,
    arg,
    fake_bottom,
    gotof,
    gotot,
    goto_,
    print,
    input,
    reserve,
    endfunc
};

struct CubeEntry {
    vartype leftOperand;
    vartype rightOperand;
    operatortype op;

    CubeEntry(): leftOperand(vartype::unknown), rightOperand(vartype::unknown), op(operatortype::unknown) {}
    CubeEntry(vartype opA, vartype opB, operatortype o): leftOperand(opA), rightOperand(opB), op(o) {}

    bool operator==(const CubeEntry& other) const {
        return leftOperand == other.leftOperand && rightOperand == other.rightOperand && op == other.op;  
    }
};

struct CubeEntryHash {
    std::size_t operator()(const CubeEntry& c) const noexcept {
        int a = static_cast<int>(c.leftOperand);
        int b = static_cast<int>(c.rightOperand);
        int o = static_cast<int>(c.op);

        return ((std::hash<int>()(a) << 1) ^
                (std::hash<int>()(b) << 2) ^
                (std::hash<int>()(o) << 3));
    }
};

static std::string* oper_s = new std::string[31] {
    "++", "--", "+", "-", "*", "/", "<=", "<", ">=", ">",
    "==", "=", "!=", "!", "&&", "||", "[]", "len", "upper", 
    "lower", "unknown", "call", "arg", "fake_bottom",
    "gotof", "gotot", "goto", "print", "input", "reserve", "endfunc"
};

static proxyarr<std::string> operatortype_string = proxyarr(oper_s);

class SemanticCube {
private:
    static std::unordered_map<CubeEntry, vartype, CubeEntryHash> table;
    
    static bool populated;

public:
    static operatortype tokenToOperator(yytokentype token);

    static bool possibleOperation(CubeEntry entry);

    static vartype resultingType(CubeEntry entry);

    static void populate();
};