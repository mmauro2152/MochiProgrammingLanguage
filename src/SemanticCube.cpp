#include "SemanticCube.hpp"

bool SemanticCube::populated = false;
std::unordered_map<CubeEntry, vartype, CubeEntryHash> SemanticCube::table = {};

operatortype SemanticCube::tokenToOperator(yytokentype token) {
    switch (token){
        case(yytokentype::plus):
            return operatortype::plus;

        case(yytokentype::minus):
            return operatortype::minus;

        case(yytokentype::asterisk):
            return operatortype::asterisk;

        case(yytokentype::slash):
            return operatortype::slash;

        case(yytokentype::equal_smaller_than):
            return operatortype::equal_smaller_than;

        case(yytokentype::l_angle_bracket):
            return operatortype::smaller_than;

        case(yytokentype::equal_greater_than):
            return operatortype::equal_greater_than;

        case(yytokentype::r_angle_bracket):
            return operatortype::greater_than;

        case(yytokentype::equal):
            return operatortype::equal;

        case(yytokentype::assign):
            return operatortype::assign;

        case(yytokentype::not_equal):
            return operatortype::not_equal;

        case(yytokentype::not_):
            return operatortype::not_;

        case(yytokentype::invalid_character):
            return operatortype::unknown;
        
        default:
            return operatortype::unknown;
    }
}

bool SemanticCube::possibleOperation(CubeEntry entry) {
    return table.find(entry) != table.end();
}

vartype SemanticCube::resultingType(CubeEntry entry) {
    if (!possibleOperation(entry)) {
        std::cerr << 
        "No valid operation for types '" << 
        vartype_string[static_cast<int>(entry.leftOperand)] << "' and '" <<
        vartype_string[static_cast<int>(entry.rightOperand)] << "' with operator '" <<
        operatortype_string[static_cast<int>(entry.op)] << "'" << 
        std::endl;

        return vartype::unknown;
    }

    return table[entry];
}

void SemanticCube::populate() {
    if (populated){
        return;
    }

    table.insert({CubeEntry(vartype::int_type, vartype::int_type, operatortype::plus), vartype::int_type});
    table.insert({CubeEntry(vartype::int_type, vartype::int_type, operatortype::minus), vartype::int_type});
    table.insert({CubeEntry(vartype::none, vartype::int_type, operatortype::plus), vartype::int_type});
    table.insert({CubeEntry(vartype::none, vartype::int_type, operatortype::minus), vartype::int_type});
    table.insert({CubeEntry(vartype::int_type, vartype::int_type, operatortype::asterisk), vartype::int_type});
    table.insert({CubeEntry(vartype::int_type, vartype::int_type, operatortype::slash), vartype::float_type});
    table.insert({CubeEntry(vartype::int_type, vartype::int_type, operatortype::equal_smaller_than), vartype::bool_type});
    table.insert({CubeEntry(vartype::int_type, vartype::int_type, operatortype::smaller_than), vartype::bool_type});
    table.insert({CubeEntry(vartype::int_type, vartype::int_type, operatortype::equal_greater_than), vartype::bool_type});
    table.insert({CubeEntry(vartype::int_type, vartype::int_type, operatortype::greater_than), vartype::bool_type});
    table.insert({CubeEntry(vartype::int_type, vartype::int_type, operatortype::equal), vartype::bool_type});
    table.insert({CubeEntry(vartype::int_type, vartype::int_type, operatortype::assign), vartype::int_type});
    table.insert({CubeEntry(vartype::int_type, vartype::int_type, operatortype::not_equal), vartype::bool_type});
    table.insert({CubeEntry(vartype::int_type, vartype::float_type, operatortype::plus), vartype::float_type});
    table.insert({CubeEntry(vartype::int_type, vartype::float_type, operatortype::minus), vartype::float_type});
    table.insert({CubeEntry(vartype::int_type, vartype::float_type, operatortype::asterisk), vartype::float_type});
    table.insert({CubeEntry(vartype::int_type, vartype::float_type, operatortype::slash), vartype::float_type});
    table.insert({CubeEntry(vartype::int_type, vartype::float_type, operatortype::equal_smaller_than), vartype::bool_type});
    table.insert({CubeEntry(vartype::int_type, vartype::float_type, operatortype::smaller_than), vartype::bool_type});
    table.insert({CubeEntry(vartype::int_type, vartype::float_type, operatortype::equal_greater_than), vartype::bool_type});
    table.insert({CubeEntry(vartype::int_type, vartype::float_type, operatortype::greater_than), vartype::bool_type});
    table.insert({CubeEntry(vartype::int_type, vartype::float_type, operatortype::equal), vartype::bool_type});
    table.insert({CubeEntry(vartype::int_type, vartype::float_type, operatortype::not_equal), vartype::bool_type});
    table.insert({CubeEntry(vartype::float_type, vartype::int_type, operatortype::plus), vartype::float_type});
    table.insert({CubeEntry(vartype::float_type, vartype::int_type, operatortype::minus), vartype::float_type});
    table.insert({CubeEntry(vartype::float_type, vartype::int_type, operatortype::asterisk), vartype::float_type});
    table.insert({CubeEntry(vartype::float_type, vartype::int_type, operatortype::slash), vartype::float_type});
    table.insert({CubeEntry(vartype::float_type, vartype::int_type, operatortype::equal_smaller_than), vartype::bool_type});
    table.insert({CubeEntry(vartype::float_type, vartype::int_type, operatortype::smaller_than), vartype::bool_type});
    table.insert({CubeEntry(vartype::float_type, vartype::int_type, operatortype::equal_greater_than), vartype::bool_type});
    table.insert({CubeEntry(vartype::float_type, vartype::int_type, operatortype::greater_than), vartype::bool_type});
    table.insert({CubeEntry(vartype::float_type, vartype::int_type, operatortype::equal), vartype::bool_type});
    table.insert({CubeEntry(vartype::float_type, vartype::int_type, operatortype::assign), vartype::float_type});
    table.insert({CubeEntry(vartype::float_type, vartype::int_type, operatortype::not_equal), vartype::bool_type});
    table.insert({CubeEntry(vartype::float_type, vartype::float_type, operatortype::plus), vartype::float_type});
    table.insert({CubeEntry(vartype::float_type, vartype::float_type, operatortype::minus), vartype::float_type});
    table.insert({CubeEntry(vartype::none, vartype::float_type, operatortype::plus), vartype::float_type});
    table.insert({CubeEntry(vartype::none, vartype::float_type, operatortype::minus), vartype::float_type});
    table.insert({CubeEntry(vartype::float_type, vartype::float_type, operatortype::asterisk), vartype::float_type});
    table.insert({CubeEntry(vartype::float_type, vartype::float_type, operatortype::slash), vartype::float_type});
    table.insert({CubeEntry(vartype::float_type, vartype::float_type, operatortype::equal_smaller_than), vartype::bool_type});
    table.insert({CubeEntry(vartype::float_type, vartype::float_type, operatortype::smaller_than), vartype::bool_type});
    table.insert({CubeEntry(vartype::float_type, vartype::float_type, operatortype::equal_greater_than), vartype::bool_type});
    table.insert({CubeEntry(vartype::float_type, vartype::float_type, operatortype::greater_than), vartype::bool_type});
    table.insert({CubeEntry(vartype::float_type, vartype::float_type, operatortype::equal), vartype::bool_type});
    table.insert({CubeEntry(vartype::float_type, vartype::float_type, operatortype::assign), vartype::float_type});
    table.insert({CubeEntry(vartype::float_type, vartype::float_type, operatortype::not_equal), vartype::bool_type});
    table.insert({CubeEntry(vartype::bool_type, vartype::bool_type, operatortype::equal), vartype::bool_type});
    table.insert({CubeEntry(vartype::bool_type, vartype::bool_type, operatortype::assign), vartype::bool_type});
    table.insert({CubeEntry(vartype::bool_type, vartype::bool_type, operatortype::not_equal), vartype::bool_type});
    table.insert({CubeEntry(vartype::none, vartype::bool_type, operatortype::not_), vartype::bool_type});
    table.insert({CubeEntry(vartype::bool_type, vartype::bool_type, operatortype::and_), vartype::bool_type});
    table.insert({CubeEntry(vartype::bool_type, vartype::bool_type, operatortype::or_), vartype::bool_type});
    table.insert({CubeEntry(vartype::string_type, vartype::string_type, operatortype::plus), vartype::string_type});
    table.insert({CubeEntry(vartype::string_type, vartype::string_type, operatortype::equal), vartype::bool_type});
    table.insert({CubeEntry(vartype::string_type, vartype::string_type, operatortype::assign), vartype::string_type});
    table.insert({CubeEntry(vartype::string_type, vartype::string_type, operatortype::not_equal), vartype::bool_type});
    table.insert({CubeEntry(vartype::none, vartype::string_type, operatortype::arg), vartype::void_type}),
    table.insert({CubeEntry(vartype::none, vartype::int_type, operatortype::arg), vartype::void_type}),
    table.insert({CubeEntry(vartype::none, vartype::float_type, operatortype::arg), vartype::void_type}),
    table.insert({CubeEntry(vartype::none, vartype::bool_type, operatortype::arg), vartype::void_type}),

    populated = true;
    return;
}