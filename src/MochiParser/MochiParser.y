%code requires {
    #include <string>
}

%{
#include <iostream>
#include <string>
#include <cstdlib>
#include <queue>
#include "../FuncDir.hpp"
#include "../QuadManager.hpp"
#include "../SemanticCube.hpp"

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

std::stack<int> argCounters;
std::stack<std::vector<operand>> args;
std::stack<FuncEntry*> funcStack;

QuadManager quadManager;

%}

%union {
    int i;
    float f;
    char* s;
}

%token invalid_character
%token program_token main_token end_token print_token while_token do_token if_token else_token var_token void_token
%token semicolon comma colon 
%token string_token int_token float_token bool_token
%token l_curly_brace r_curly_brace l_square_bracket r_square_bracket l_parenthesis r_parenthesis
%token plus minus asterisk slash equal_smaller_than l_angle_bracket equal_greater_than r_angle_bracket
%token equal assign not_equal not_ and_ or_
%token <s> id
%token <i> int_constant
%token <f> float_constant
%token <s> string_constant

%%

program_declaration:
    program_token id { 
        globalScope = $2;
        currScope = globalScope;
        funcDir.setGlobalScope(globalScope);
        if (!funcDir.insertFunction(currScope, vartype::void_type)) {
            semanticErrors++;
        }
    } 
    semicolon opt_vars opt_funcs main_token { currScope = globalScope; } body end_token {
        quadManager.debug();
        //funcDir.printAll();
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
    | bool_token { currType = vartype::bool_type; }
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
    id {
        VarEntry* var = funcDir.getVar(currScope, $1);
        if (var == nullptr) {
            semanticErrors++;
        } else {
            operand op = operand(var->type, currScope, $1);
            quadManager.operands.push(op);
        }
    }
    assign { quadManager.operators.push(operatortype::assign); }
    assign_statement_ semicolon {
        if (!quadManager.operators.empty() && !quadManager.operands.empty() && quadManager.operators.top() == operatortype::assign) {
            operand rOperand = quadManager.operands.top();
            quadManager.operands.pop();
            operand lOperand = quadManager.operands.top();
            quadManager.operands.pop();
            operatortype op = quadManager.operators.top();
            quadManager.operators.pop();

            CubeEntry entry = CubeEntry(lOperand.type, rOperand.type, op);
            vartype restype = SemanticCube::resultingType(entry);

            if (restype == vartype::unknown) {
                semanticErrors++;
            }else {
                quad q = quad(op, operand(vartype::none, currScope, "none"), rOperand, lOperand);
                quadManager.push(q);
            }
        }
    }
;

assign_statement_:
    expression
    | id {
        VarEntry* var = funcDir.getVar(currScope, $1);
        if (var == nullptr) {
            semanticErrors++;
        } else {
            operand op = operand(var->type, currScope, $1);
            quadManager.operands.push(op);
        }
    }
    assign { quadManager.operators.push(operatortype::assign); }
    assign_statement_ {
        if (!quadManager.operators.empty() && !quadManager.operands.empty() && quadManager.operators.top() == operatortype::assign) {
            operand rOperand = quadManager.operands.top();
            quadManager.operands.pop();
            operand lOperand = quadManager.operands.top();
            quadManager.operands.pop();
            operatortype op = quadManager.operators.top();
            quadManager.operators.pop();

            CubeEntry entry = CubeEntry(lOperand.type, rOperand.type, op);
            vartype restype = SemanticCube::resultingType(entry);

            if (restype == vartype::unknown) {
                semanticErrors++;
            }else {
                quad q = quad(op, operand(vartype::none, currScope, "none"), rOperand, lOperand);
                quadManager.push(q);
                quadManager.operands.push(lOperand);
            }
        }
    }
;

condition_statement:
    if_token l_parenthesis expression {
        operand condition = quadManager.operands.top();
        quadManager.operands.pop();
        if (condition.type != vartype::bool_type){
            semanticErrors++;
            std::cerr << "Expected bool expression instead of " << vartype_string[static_cast<int>(condition.type)] << std::endl; 
        } else {
            operand none_operand =  operand(vartype::none, currScope, "none");
            quad q = quad(operatortype::gotof, condition, none_operand, none_operand);

            quadManager.push(q);
            quadManager.jumps.push(quadManager.instructionPointer - 1);
        }
    }
    r_parenthesis body opt_else semicolon {
        int end = quadManager.jumps.top();
        quadManager.jumps.pop();

        operand jumpOperand = operand(vartype::int_type, quadManager.constScope, std::to_string(quadManager.instructionPointer));
        quadManager.quads[end].rightOperand = jumpOperand;
    }
;

opt_else:

    | else_token {
        operand none_operand = operand(vartype::none, currScope, "none");
        quad q = quad(operatortype::goto_, none_operand, none_operand, none_operand);

        quadManager.push(q);

        int false_ = quadManager.jumps.top();
        quadManager.jumps.pop();

        quadManager.jumps.push(quadManager.instructionPointer - 1);

        operand jumpOperand = operand(vartype::int_type, quadManager.constScope, std::to_string(quadManager.instructionPointer));
        quadManager.quads[false_].rightOperand = jumpOperand;
    } 
    body
;

cycle_statement:
    while_token {
        quadManager.jumps.push(quadManager.instructionPointer);
    }
    l_parenthesis expression r_parenthesis {
        operand condition = quadManager.operands.top();
        quadManager.operands.pop();

        if (condition.type != vartype::bool_type){
            semanticErrors++;
            std::cerr << "Expected bool expression instead of " << vartype_string[static_cast<int>(condition.type)] << std::endl; 
        } else {
            operand none_operand = operand(vartype::none, currScope, "none");
            quad q = quad(operatortype::gotof, condition, none_operand, none_operand);
            quadManager.push(q);
            quadManager.jumps.push(quadManager.instructionPointer - 1);
        }
    }
    do_token body semicolon {
        int end = quadManager.jumps.top();
        quadManager.jumps.pop();

        int return_ = quadManager.jumps.top();
        quadManager.jumps.pop();

        operand returnOperand = operand(vartype::int_type, quadManager.constScope, std::to_string(return_));
        operand noneOperand = operand(vartype::none, currScope, "none");
        quad q = quad(operatortype::goto_, noneOperand, returnOperand, noneOperand);
        quadManager.push(q);


        operand jumpOperand = operand(vartype::int_type, quadManager.constScope, std::to_string(quadManager.instructionPointer));
        quadManager.quads[end].rightOperand = jumpOperand;
    }
;

print_statement:
    print_token { args.push(std::vector<operand>()); }
    l_parenthesis arg_loop r_parenthesis {
        std::vector<operand> funcArgs = args.top();
        args.pop();

        operand o = operand(vartype::func, "", "print");
        operand temp = quadManager.getTemp(vartype::void_type);
        quad q = quad(operatortype::call, operand(vartype::int_type, currScope, std::to_string(funcArgs.size())), o, temp);

        quadManager.push(q);
    }
    semicolon 
;

func_call: 
    id { 
        FuncEntry* func = funcDir.getFunction($1);
        
        if (func == nullptr) {
            semanticErrors++;
        }
        else {
            funcStack.push(func);
            args.push(std::vector<operand>());
        } 
    } 
    l_parenthesis opt_arg_loop r_parenthesis {
        std::vector<operand> funcArgs = args.top();
        args.pop();

        FuncEntry* func = funcStack.top();
        funcStack.pop();

        int err = semanticErrors;
        if (func->parameters.size() != funcArgs.size()) {
            semanticErrors++;

            std::cerr << "Error: Argument count mismatch for function '" << $1 << "'" << std::endl;
        } 
        else {

            for (int i = 0; i < func->parameters.size(); i++){
                if (func->parameters[i].second != funcArgs[i].type) {
                    semanticErrors++;
                    std::cerr << "Error: Argument type mismatch, expected '" << vartype_string[static_cast<int>(func->parameters[i].second)] << "'" << std::endl;
                }
            }
        }

        if (semanticErrors == err) {
            operand o = operand(vartype::func, "", $1);
            operand temp = quadManager.getTemp(func->returnType);
            quad q = quad(operatortype::call, operand(vartype::int_type, currScope, std::to_string(func->parameters.size())), o, temp);

            quadManager.push(q);
            quadManager.operands.push(temp);
        }
    }
;

func_call_statement:
    func_call semicolon
;

opt_arg_loop:

    | arg_loop
;

arg_loop:
    expression {
        if (quadManager.operands.empty()) {
            semanticErrors++;
            std::cerr << "Error: Expected expression" << std::endl;
        }
        else {
            operand exp_result = quadManager.operands.top(); 
            quadManager.operands.pop();

            quad q = quad(operatortype::arg, operand(vartype::none, currScope, "none"), exp_result, operand(vartype::none, currScope, "none"));
            quadManager.push(q);
            args.top().push_back(exp_result);
        }
    }
    arg_loop_

    | string_constant arg_loop_
;

arg_loop_:

    | comma arg_loop
;

expression:
    or_exp {
        if (!quadManager.operators.empty() && !quadManager.operands.empty() && (quadManager.operators.top() == operatortype::or_)) {
            operand rOperand = quadManager.operands.top();
            quadManager.operands.pop();
            operand lOperand = quadManager.operands.top();
            quadManager.operands.pop();
            operatortype op = quadManager.operators.top();
            quadManager.operators.pop();

            CubeEntry entry = CubeEntry(lOperand.type, rOperand.type, op);
            vartype restype = SemanticCube::resultingType(entry);

            if (restype == vartype::unknown) {
                semanticErrors++;
            }else {
                operand temp = quadManager.getTemp(restype);
                quad q = quad(op, lOperand, rOperand, temp);

                quadManager.push(q);
                quadManager.operands.push(temp);
            }
        }
    }
    or_exp_
;

or_exp_:

    | or_ { quadManager.operators.push(operatortype::or_); } expression
;

or_exp:
    and_exp {
        if (!quadManager.operators.empty() && !quadManager.operands.empty() && (quadManager.operators.top() == operatortype::and_)) {
            operand rOperand = quadManager.operands.top();
            quadManager.operands.pop();
            operand lOperand = quadManager.operands.top();
            quadManager.operands.pop();
            operatortype op = quadManager.operators.top();
            quadManager.operators.pop();

            CubeEntry entry = CubeEntry(lOperand.type, rOperand.type, op);
            vartype restype = SemanticCube::resultingType(entry);

            if (restype == vartype::unknown) {
                semanticErrors++;
            }else {
                operand temp = quadManager.getTemp(restype);
                quad q = quad(op, lOperand, rOperand, temp);

                quadManager.push(q);
                quadManager.operands.push(temp);
            }
        }
    }
    and_exp_
;

and_exp_:

    | and_ { quadManager.operators.push(operatortype::and_); } or_exp
;

and_exp:
    eq_exp {
        if (!quadManager.operators.empty() && !quadManager.operands.empty() && (quadManager.operators.top() == operatortype::equal || quadManager.operators.top() == operatortype::not_equal)) {
            operand rOperand = quadManager.operands.top();
            quadManager.operands.pop();
            operand lOperand = quadManager.operands.top();
            quadManager.operands.pop();
            operatortype op = quadManager.operators.top();
            quadManager.operators.pop();

            CubeEntry entry = CubeEntry(lOperand.type, rOperand.type, op);
            vartype restype = SemanticCube::resultingType(entry);

            if (restype == vartype::unknown) {
                semanticErrors++;
            }else {
                operand temp = quadManager.getTemp(restype);
                quad q = quad(op, lOperand, rOperand, temp);

                quadManager.push(q);
                quadManager.operands.push(temp);
            }
        }
    }
    eq_exp_
;

eq_oper:
    equal { quadManager.operators.push(operatortype::equal); }
    | not_equal { quadManager.operators.push(operatortype::not_equal); }
;

eq_exp_: 

    | eq_oper and_exp
;

eq_exp:
    rel_exp {
        if (!quadManager.operators.empty() && !quadManager.operands.empty() && (quadManager.operators.top() == operatortype::equal_greater_than || quadManager.operators.top() == operatortype::greater_than || quadManager.operators.top() == operatortype::equal_smaller_than || quadManager.operators.top() == operatortype::smaller_than)) {
            operand rOperand = quadManager.operands.top();
            quadManager.operands.pop();
            operand lOperand = quadManager.operands.top();
            quadManager.operands.pop();
            operatortype op = quadManager.operators.top();
            quadManager.operators.pop();

            CubeEntry entry = CubeEntry(lOperand.type, rOperand.type, op);
            vartype restype = SemanticCube::resultingType(entry);

            if (restype == vartype::unknown) {
                semanticErrors++;
            }else {
                operand temp = quadManager.getTemp(restype);
                quad q = quad(op, lOperand, rOperand, temp);

                quadManager.push(q);
                quadManager.operands.push(temp);
            }
        }
    }
    rel_exp_
;

rel_exp_:

    | rel_oper eq_exp
;

rel_oper:
    equal_greater_than { quadManager.operators.push(operatortype::equal_greater_than); }
    | r_angle_bracket { quadManager.operators.push(operatortype::greater_than); }
    | equal_smaller_than { quadManager.operators.push(operatortype::equal_smaller_than); }
    | l_angle_bracket { quadManager.operators.push(operatortype::smaller_than); }
;

rel_exp:
    term {
        if (!quadManager.operators.empty() && !quadManager.operands.empty() && (quadManager.operators.top() == operatortype::plus || quadManager.operators.top() == operatortype::minus)) {
            operand rOperand = quadManager.operands.top();
            quadManager.operands.pop();
            operand lOperand = quadManager.operands.top();
            quadManager.operands.pop();
            operatortype op = quadManager.operators.top();
            quadManager.operators.pop();

            CubeEntry entry = CubeEntry(lOperand.type, rOperand.type, op);
            vartype restype = SemanticCube::resultingType(entry);

            if (restype == vartype::unknown) {
                semanticErrors++;
            }else {
                operand temp = quadManager.getTemp(restype);
                quad q = quad(op, lOperand, rOperand, temp);

                quadManager.push(q);
                quadManager.operands.push(temp);
            }
        }
    }
    term_
;

term_:
    
    | term_operator rel_exp
;

term_operator:
    plus { quadManager.operators.push(operatortype::plus); }
    | minus { quadManager.operators.push(operatortype::minus); }
;

term:
    factor {
        if (!quadManager.operators.empty() && !quadManager.operands.empty() && (quadManager.operators.top() == operatortype::asterisk || quadManager.operators.top() == operatortype::slash)) {
            operand rOperand = quadManager.operands.top();
            quadManager.operands.pop();
            operand lOperand = quadManager.operands.top();
            quadManager.operands.pop();
            operatortype op = quadManager.operators.top();
            quadManager.operators.pop();

            CubeEntry entry = CubeEntry(lOperand.type, rOperand.type, op);
            vartype restype = SemanticCube::resultingType(entry);

            if (restype == vartype::unknown) {
                semanticErrors++;
            }else {
                operand temp = quadManager.getTemp(restype);
                quad q = quad(op, lOperand, rOperand, temp);

                quadManager.push(q);
                quadManager.operands.push(temp);
            }
        }
    }
    factor_
;

factor_:

    | factor_operator term
;

factor_operator:
    asterisk { quadManager.operators.push(operatortype::asterisk); }
    | slash { quadManager.operators.push(operatortype::slash); }
;

factor:
    l_parenthesis {
        quadManager.operators.push(operatortype::fake_bottom);
    } 
    expression r_parenthesis {
        if (quadManager.operators.top() != operatortype::fake_bottom) {
            semanticErrors++;
            std::cerr << "Error: Unexpected operator '" << operatortype_string[static_cast<int>(quadManager.operators.top())] << "'" << std::endl;  
        } else {
            // discard fake bottom
            quadManager.operators.pop();
        }
    }

    | opt_operator l_parenthesis {
        quadManager.operators.push(operatortype::fake_bottom);
    } 
    expression r_parenthesis {
        if (quadManager.operators.top() != operatortype::fake_bottom) {
            semanticErrors++;
            std::cerr << "Error: Unexpected operator '" << operatortype_string[static_cast<int>(quadManager.operators.top())] << "'" << std::endl;  
        } else {
            // discard fake bottom
            quadManager.operators.pop();

            operand rOperand = quadManager.operands.top();
            quadManager.operands.pop();
            operatortype op = quadManager.operators.top();
            quadManager.operators.pop();
    
            CubeEntry entry = CubeEntry(vartype::none, rOperand.type, op);
            vartype restype = SemanticCube::resultingType(entry);
    
            if (restype == vartype::unknown) {
                semanticErrors++;
            }else {
                operand temp = quadManager.getTemp(restype);
                quad q = quad(op, operand(vartype::none, currScope, "none"), rOperand, temp);
    
                quadManager.push(q);
                quadManager.operands.push(temp);
            }
        }
    }

    | factor_element
    
    | opt_operator factor_element {
        operand rOperand = quadManager.operands.top();
        quadManager.operands.pop();
        operatortype op = quadManager.operators.top();
        quadManager.operators.pop();

        CubeEntry entry = CubeEntry(vartype::none, rOperand.type, op);
        vartype restype = SemanticCube::resultingType(entry);

        if (restype == vartype::unknown) {
            semanticErrors++;
        }else {
            operand temp = quadManager.getTemp(restype);
            quad q = quad(op, operand(vartype::none, currScope, "none"), rOperand, temp);

            quadManager.push(q);
            quadManager.operands.push(temp);
        }
    }
;

opt_operator:
    plus { quadManager.operators.push(operatortype::plus); }
    | minus { quadManager.operators.push(operatortype::minus); }
    | not_ { quadManager.operators.push(operatortype::not_); }
;

factor_element:
    id { 
        VarEntry* var = funcDir.getVar(currScope, $1);
        if (var == nullptr) {
            semanticErrors++;
        } else {
            operand op = operand(var->type, currScope, $1);
            quadManager.operands.push(op);
        }
    }
    | num_constant
    | func_call
;

num_constant:
    int_constant {
        operand op = operand(vartype::int_type, currScope, std::to_string($1));
        quadManager.operands.push(op);
    }
    | float_constant {
        operand op = operand(vartype::float_type, currScope, std::to_string($1));
        quadManager.operands.push(op);
    }
;

%%