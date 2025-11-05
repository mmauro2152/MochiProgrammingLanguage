%code requires {
    #include <string>
}

%{
#include <iostream>
#include <string>
#include <cstdlib>
#include <queue>
#include "../FuncDir.hpp"

void yyerror(const char* errorMsg) {
    std::cout << errorMsg << std::endl;
};
extern int yylex(void);


FuncDir funcDir;
std::string globalScope;
std::string currScope;
std::queue<char*> idQueue;
vartype currType;
int semanticErrors = 0;

%}

%union {
    int i;
    float f;
    char* s;
}

%token invalid_character
%token program_token main_token end_token print_token while_token do_token if_token else_token var_token void_token
%token semicolon comma colon 
%token string_token int_token float_token
%token l_curly_brace r_curly_brace l_square_bracket r_square_bracket l_parenthesis r_parenthesis
%token plus minus asterisk slash equal_smaller_than l_angle_bracket equal_greater_than r_angle_bracket
%token equal assign not_equal not_
%token <s> id
%token <i> int_constant
%token <f> float_constant
%token <s> string_constant

%%

program_declaration:
    program_token id { 
        globalScope = $2;
        currScope = globalScope;
        if (!funcDir.insertFunction(currScope, vartype::VOID)) {
            semanticErrors++;
        }
    } 
    semicolon opt_vars opt_funcs main_token body end_token {
        funcDir.printAll();
        if (semanticErrors > 0) {
            std::cerr << "Found " << semanticErrors << " semantic errors" << std::endl;
            exit(EXIT_FAILURE);
        }
    }
;

opt_funcs:

    | funcs opt_funcs_
;

opt_funcs_:
    opt_funcs
;

opt_vars:
    
    | vars
;

vars:
    var_token var_loop
;

var_loop:
    id_loop colon type semicolon {
        while (!idQueue.empty()) {
            if (!funcDir.getFunction(currScope)->localVars.insert(idQueue.front(), currType)) {
                semanticErrors++;
            }
                 
            idQueue.pop();
        }
    }  var_loop_
;

var_loop_:
    
    | var_loop
;

id_loop:
    id { idQueue.push($1); } 
    id_loop_
;

id_loop_:

    | comma id_loop
;

type:
    int_token { currType = vartype::int_type; }
    | float_token { currType = vartype::float_type; }
    | string_token { currType = vartype::string_type; }
;

func_type:
    void_token { currType = vartype::void_type; }
    | type
;

funcs:
    func_type id { 
        currScope = $2;
        if (!funcDir.insertFunction(currScope, currType)){
            semanticErrors++;
        }
    } 
    l_parenthesis params r_parenthesis l_square_bracket opt_vars body r_square_bracket semicolon
;

params:

    | param_loop
;

param_loop:
    id colon type { 
        funcDir.addParameter(currScope, $1, currType);
    } 
    param_loop_
;

param_loop_:

    | comma param_loop
;

body:
    l_curly_brace statement_loop r_curly_brace
;

statement_loop:
    
    | statement statement_loop
;

statement:
    assign_statement
    | condition_statement
    | cycle_statement 
    | print_statement
    | func_call_statement
;

assign_statement:
    id assign expression semicolon
;

condition_statement:
    if_token l_parenthesis expression r_parenthesis body opt_else semicolon
;

opt_else:

    | else_token body
;

cycle_statement:
    while_token l_parenthesis expression r_parenthesis do_token body semicolon
;

print_statement:
    print_token l_parenthesis print_loop r_parenthesis semicolon 
;

print_loop:
    print_element print_loop_
;

print_loop_:

    | comma print_loop
;

print_element:
    expression
    | string_constant
;

func_call_statement:
    id l_parenthesis opt_expression_loop r_parenthesis semicolon
;

opt_expression_loop:

    | expression_loop
;

expression_loop:
    expression expression_loop_
    | string_constant expression_loop_
;

expression_loop_:

    | comma expression_loop
;

expression:
    exp exp_
;

exp_:

    | conditional_operator exp
;

conditional_operator:
    equal_greater_than
    | r_angle_bracket
    | equal_smaller_than
    | l_angle_bracket
    | not_equal
    | equal
;

exp:
    term term_
;

term_:
    
    | term_operator exp
;

term_operator:
    plus
    | minus
;

term:
    factor factor_
;

factor_:

    | factor_operator term
;

factor_operator:
    asterisk
    | slash
;

factor:
    l_parenthesis expression r_parenthesis
    | opt_operator factor_element
;

opt_operator:

    | plus
    | minus
;

factor_element:
    id
    | num_constant
;

num_constant:
    int_constant
    | float_constant
;

%%