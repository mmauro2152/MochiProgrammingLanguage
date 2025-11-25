%code requires {
    #include <string>
}

%{
// #include <iostream>
// #include <string>
// #include <cstdlib>
// #include <queue>
// #include "../FuncDir.hpp"
// #include "../QuadManager.hpp"
// #include "../SemanticCube.hpp"
#include "parserglobals.hpp"

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
std::stack<FuncEntry*> funcStack;
std::stack<std::vector<operand>> args;
bool hasReturnExpression = false;


QuadManager quadManager;


void printQuads(){
    for (int i = 0; i < quadManager.quads.size(); i++){
        quad* q = quadManager.quads[i];

        std::cout << i << ": ";         
        q->printQuad();
        std::cout << std::endl;
    }
}

%}

%union {
    int i;
    float f;
    char* s;
    bool b;
}

%token invalid_character
%token program_token main_token end_token print_token while_token do_token if_token else_token var_token void_token return_token
%token semicolon comma colon 
%token string_token int_token float_token bool_token
%token l_curly_brace r_curly_brace l_square_bracket r_square_bracket l_parenthesis r_parenthesis
%token plus minus asterisk slash equal_smaller_than l_angle_bracket equal_greater_than r_angle_bracket
%token equal assign not_equal not_ and_ or_
%token <s> id
%token <i> int_constant
%token <f> float_constant
%token <s> string_constant
%token <b> true_constant false_constant

%%

program_declaration:
    program_token id { 
        globalScope = $2;
        currScope = globalScope;
        funcDir.setGlobalScope(globalScope);
        if (!funcDir.insertFunction(currScope, vartype::void_type)) {
            semanticErrors++;
        }

        funcDir.getFunction(globalScope)->memManager->setAsGlobal();
        quad* q = new reserve(funcDir.getFunction(globalScope)->memManager);
        quadManager.push(q);

        q = new goto_(-1);
        quadManager.push(q);
        quadManager.jumps.push(quadManager.instructionPointer - 1);
    } 
    semicolon opt_vars opt_funcs main_token { 
        currScope = globalScope; 

        if (quadManager.jumps.empty()) {
            semanticErrors++;
            std::cerr << "Expected pointer to goto main quad" << std::endl;
        } else {
            int jump = quadManager.jumps.top();

            if (goto_* g = dynamic_cast<goto_*>(quadManager.quads[jump])) {
                g->jump = quadManager.instructionPointer;
            } else {
                semanticErrors++;
                std::cerr << "Incorrect jump to quad " << jump << " expected instruction" << std::endl;
            }
        }
    }
    body end_token {
        
        printQuads();

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
            int addr = 0;
            memorytype mem = (currScope == globalScope) ? memorytype::global : memorytype::local;
            if (currScope == globalScope) {
                addr = funcDir.getFunction(currScope)->memManager->getAddress(mem, currType);
            } else {
                addr = funcDir.getFunction(currScope)->memManager->getAddress(mem, currType);
            }

            if (!funcDir.getFunction(currScope)->localVars.insert(addr, currType, idQueue.front(), mem)) {
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
        } else {
            FuncEntry* globalContext = funcDir.getFunction(globalScope);

            int addr = globalContext->memManager->getAddress(memorytype::global, currType);
            globalContext->localVars.insert(addr, currType, currScope, memorytype::global);
        }
    } 
    l_parenthesis params r_parenthesis l_square_bracket opt_vars {
        funcDir.getFunction(currScope)->start = quadManager.instructionPointer;
    }
    body r_square_bracket semicolon {
        quadManager.push(new endfunc());
    }
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
    | return_statement 
;

return_statement:
    return_token opt_expression semicolon {
        FuncEntry* func = funcDir.getFunction(currScope);

        if (func->returnType == vartype::void_type) {
            if (hasReturnExpression) {
                semanticErrors++;
                std::cerr << "No return expression allowed for void function '" << func->name << "' " << std::endl;
            }
        } 
        else if (!hasReturnExpression) {
            semanticErrors++;
            std::cerr << "Expected return expression of type '" << vartype_string[func->returnType] << "'" << std::endl;
        } 
        else {
            FuncEntry* globalContext = funcDir.getFunction(globalScope);

            operand exp_result = quadManager.operands.top();
            quadManager.operands.pop();

            operand funcVarOper = globalContext->localVars.getVar(currScope);

            if (funcVarOper.type != exp_result.type) {
                semanticErrors++;
                std::cerr << "Expected expression of type '" << 
                vartype_string[funcVarOper.type] << "' instead of '" << 
                vartype_string[exp_result.type] << "'" << std::endl;
            } else {
                quad* q = new unaryOperation(operatortype::assign, exp_result, funcVarOper);
                quadManager.push(q);
                quadManager.push(new endfunc());
            }
        }
    }
;

opt_expression:
    { hasReturnExpression = false; }
    | expression { hasReturnExpression = true; }
;

assign_statement:
    id {
        operand var = funcDir.getVar(currScope, $1);
        if (var.type == vartype::unknown) {
            semanticErrors++;
        } else {
            quadManager.operands.push(var);
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
                quad* q = new unaryOperation(op, rOperand, lOperand);
                quadManager.push(q);
            }
        }
    }
;

assign_statement_:
    expression
    | id {
        operand var = funcDir.getVar(currScope, $1);
        if (var.type == vartype::unknown) {
            semanticErrors++;
        } else {
            quadManager.operands.push(var);
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
                quad* q = new unaryOperation(op, rOperand, lOperand);
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
            std::cerr << "Expected bool expression instead of " << vartype_string[condition.type] << std::endl; 
        } else {
            quad* q = new condGoto(operatortype::gotof, condition, -1);

            quadManager.push(q);
            quadManager.jumps.push(quadManager.instructionPointer - 1);
        }
    }
    r_parenthesis body opt_else semicolon {
        int end = quadManager.jumps.top();
        quadManager.jumps.pop();

        if (goto_* g = dynamic_cast<goto_*>(quadManager.quads[end])) {
            g->jump = quadManager.instructionPointer;
        } else {
            semanticErrors++;
            std::cerr << "Incorrect jump to quad " << end << " expected instruction" << std::endl;
        }

        //quadManager.quads[end].rightOperand = jumpOperand;
    }
;

opt_else:

    | else_token {
        quad* q = new goto_(operatortype::goto_, -1);

        quadManager.push(q);

        int false_ = quadManager.jumps.top();
        quadManager.jumps.pop();

        quadManager.jumps.push(quadManager.instructionPointer - 1);

        if (goto_* g = dynamic_cast<goto_*>(quadManager.quads[false_])) {
            g->jump = quadManager.instructionPointer;
        } else {
            semanticErrors++;
            std::cerr << "Incorrect jump to quad " << false_ << " expected instruction" << std::endl;
        }

        //quadManager.quads[false_].rightOperand = jumpOperand;
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
            std::cerr << "Expected bool expression instead of " << vartype_string[condition.type] << std::endl; 
        } else {
            quad* q = new condGoto(operatortype::gotof, condition, -1);
            quadManager.push(q);
            quadManager.jumps.push(quadManager.instructionPointer - 1);
        }
    }
    do_token body semicolon {
        int end = quadManager.jumps.top();
        quadManager.jumps.pop();

        int return_ = quadManager.jumps.top();
        quadManager.jumps.pop();

        quad* q = new goto_(return_);
        quadManager.push(q);

        if (goto_* g = dynamic_cast<goto_*>(quadManager.quads[end])) {
            g->jump = quadManager.instructionPointer;
        } else {
            semanticErrors++;
            std::cerr << "Incorrect jump to quad " << end << " expected instruction" << std::endl;
        }
    }
;

print_statement:
    print_token l_parenthesis print_arg_loop r_parenthesis semicolon {
        print* p = dynamic_cast<print*>(quadManager.quads[quadManager.quads.size() - 1]);
        p->endl = true;
    }
;

print_arg_loop:
    expression {
        if (quadManager.operands.empty()) {
            semanticErrors++;
            std::cerr << "Error: Expected expression" << std::endl;
        }
        else {
            operand exp_result = quadManager.operands.top(); 
            quadManager.operands.pop();

            quad* q = new print(exp_result);
            quadManager.push(q);
        }
    }
    print_arg_loop_
;

print_arg_loop_:

    | comma print_arg_loop
;

func_call: 
    id { 
        FuncEntry* func = funcDir.getFunction($1);
        
        if (func == nullptr) {
            semanticErrors++;
        }
        else {
            funcStack.push(func);
            argCounters.push(0);

            quadManager.operators.push(operatortype::fake_bottom);

            quad* q = new reserve(func->memManager);
            quadManager.push(q);
        }
    } 
    l_parenthesis opt_arg_loop r_parenthesis {
        if (funcStack.empty()) {
            semanticErrors++;
        } else {
            FuncEntry* func = funcStack.top();
            funcStack.pop();
            int argCount = argCounters.top();
            argCounters.pop();
    
            if (func->parameters.size() != argCount) {
                semanticErrors++;
                std::cout << "Argument count mismatch" << std::endl;
                
            }
            else if (quadManager.operators.top() != operatortype::fake_bottom) {
                semanticErrors++;
                std::cerr << "Unexpected operator '" << operatortype_string[quadManager.operators.top()] << "'" << std::endl;
            }
            else {
                // discard fake bottom
                quadManager.operators.pop();

                quad* q = new call(func->name, func->start);
                quadManager.push(q);

                if (func->returnType != vartype::void_type) {
                    FuncEntry* globalContext = funcDir.getFunction(globalScope);
                    operand funcVarOper = globalContext->localVars.getVar(func->name);
                    operand t = globalContext->memManager->getTemp(func->returnType);
    
                    quad* aq = new unaryOperation(operatortype::assign, funcVarOper, t);
                    quadManager.push(aq);
                    quadManager.operands.push(t);
                }
            }
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
            operand arg_ = quadManager.operands.top(); 
            quadManager.operands.pop();

            std::vector<operand> params = funcStack.top()->parameters;

            if (params.size() == 0 || argCounters.top() > params.size() - 1) {
                semanticErrors++;
                std::cerr << "Argument count mismatch for function '" << funcStack.top()->name << "'" << std::endl;
            }

            CubeEntry entry = CubeEntry(params[argCounters.top()].type, arg_.type, operatortype::assign);
            vartype restype = SemanticCube::resultingType(entry);

            if (!SemanticCube::possibleOperation(entry)) {
                semanticErrors++;

                std::cerr << "Argument type mismatch, expected '" << 
                vartype_string[params[argCounters.top()].type] <<
                "' and received '" <<
                vartype_string[arg_.type] << 
                "'" << std::endl;
            }

            quad* q = new arg(arg_, argCounters.top(), params[argCounters.top()]);
            quadManager.push(q);

            argCounters.top() = argCounters.top() + 1;
        }
    }
    arg_loop_
;

arg_loop_:

    | comma arg_loop
;

expression:
    or_exp {
        if (!quadManager.operators.empty() && !quadManager.operands.empty() && (quadManager.operators.top() == operatortype::or_)) {
            if (!quadManager.generateBinaryQuad(funcDir.getFunction(currScope)->memManager)){
                semanticErrors++;
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
            if (!quadManager.generateBinaryQuad(funcDir.getFunction(currScope)->memManager)){
                semanticErrors++;
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
            if (!quadManager.generateBinaryQuad(funcDir.getFunction(currScope)->memManager)){
                semanticErrors++;
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
            if (!quadManager.generateBinaryQuad(funcDir.getFunction(currScope)->memManager)){
                semanticErrors++;
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
            if (!quadManager.generateBinaryQuad(funcDir.getFunction(currScope)->memManager)){
                semanticErrors++;
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
            if (!quadManager.generateBinaryQuad(funcDir.getFunction(currScope)->memManager)){
                semanticErrors++;
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
            std::cerr << "Error: Unexpected operator '" << operatortype_string[quadManager.operators.top()] << "'" << std::endl;  
        } else {
            // discard fake bottom
            quadManager.operators.pop();
        }
    }

    | unary_oper l_parenthesis {
        quadManager.operators.push(operatortype::fake_bottom);
    } 
    expression r_parenthesis {
        if (quadManager.operators.top() != operatortype::fake_bottom) {
            semanticErrors++;
            std::cerr << "Error: Unexpected operator '" << operatortype_string[quadManager.operators.top()] << "'" << std::endl;  
        } else {
            // discard fake bottom
            quadManager.operators.pop();

            if (!quadManager.generateUnaryQuad(funcDir.getFunction(currScope)->memManager)){
                semanticErrors++;
            }
        }
    }

    | factor_element
    
    | unary_oper factor_element {
        if (!quadManager.generateUnaryQuad(funcDir.getFunction(currScope)->memManager)){
            semanticErrors++;
        }
    }
;

unary_oper:
    plus { quadManager.operators.push(operatortype::plus); }
    | minus { quadManager.operators.push(operatortype::minus); }
    | not_ { quadManager.operators.push(operatortype::not_); }
;

factor_element:
    id { 
        operand var = funcDir.getVar(currScope, $1);
        if (var.type == vartype::unknown) {
            semanticErrors++;
        } else {
            quadManager.operands.push(var);
        }
    }
    | constants
    | func_call
;

constants: 
    string_constant {
        operand op = funcDir.getFunction(globalScope)->memManager->getConst($1, $1, vartype::string_type);
        quadManager.operands.push(op);
    }
    | num_constant
    | bool_constant
;

num_constant:
    int_constant {
        operand op = funcDir.getFunction(globalScope)->memManager->getConst(std::to_string($1), $1, vartype::int_type);
        quadManager.operands.push(op);
    }
    | float_constant {
        operand op = funcDir.getFunction(globalScope)->memManager->getConst(std::to_string($1), $1, vartype::float_type);
        quadManager.operands.push(op);
    }
;

bool_constant:
    true_constant {
        operand op = funcDir.getFunction(globalScope)->memManager->getConst("true", true, vartype::bool_type);
        quadManager.operands.push(op);
    }

    | false_constant {
        operand op = funcDir.getFunction(globalScope)->memManager->getConst("false", false, vartype::bool_type);
        quadManager.operands.push(op);
    }
;

%%