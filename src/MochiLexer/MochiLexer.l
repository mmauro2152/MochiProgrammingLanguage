%{
#include "../MochiParser/MochiParser.tab.hpp"
#include <cstdlib>
#include <string>

#define NAMEOF(x) #x

std::string token_name;

extern int yylex();
%}

%option noyywrap

%%
"program"                   { token_name = NAMEOF(program_token); return program_token; }
"main"                      { token_name = NAMEOF(main_token); return main_token; }
"return"                    { token_name = NAMEOF(return_token); return return_token; }
"end"                       { token_name = NAMEOF(end_token); return end_token; }
"print"                     { token_name = NAMEOF(print_token); return print_token; }
"while"                     { token_name = NAMEOF(while_token); return while_token; }
"do"                        { token_name = NAMEOF(do_token); return do_token; }
"if"                        { token_name = NAMEOF(if_token); return if_token; }
"else"                      { token_name = NAMEOF(else_token); return else_token; }
"var"                       { token_name = NAMEOF(var_token); return var_token; }
"void"                      { token_name = NAMEOF(void_token); return void_token; }
";"                         { token_name = NAMEOF(semicolon); return semicolon; }
","                         { token_name = NAMEOF(comma); return comma; }
":"                         { token_name = NAMEOF(colon); return colon; }
"string"                    { token_name = NAMEOF(string_token); return string_token; }
"int"                       { token_name = NAMEOF(int_token); return int_token; }
"float"                     { token_name = NAMEOF(float_token); return float_token; }
"bool"                      { token_name = NAMEOF(bool_token); return bool_token; }
"true"                      { token_name = NAMEOF(true_constant); return true_constant; }
"false"                     { token_name = NAMEOF(false_constant); return false_constant; }
"{"                         { token_name = NAMEOF(l_curly_brace); return l_curly_brace; }
"}"                         { token_name = NAMEOF(r_curly_brace); return r_curly_brace; }
"["                         { token_name = NAMEOF(l_square_bracket); return l_square_bracket; }
"]"                         { token_name = NAMEOF(r_square_bracket); return r_square_bracket; }
"("                         { token_name = NAMEOF(l_parenthesis); return l_parenthesis; }
")"                         { token_name = NAMEOF(r_parenthesis); return r_parenthesis; }
"++"                        { token_name = NAMEOF(plusplus); return plusplus; }
"--"                        { token_name = NAMEOF(minusminus); return minusminus; }
"+"                         { token_name = NAMEOF(plus); return plus; }
"-"                         { token_name = NAMEOF(minus); return minus; }
"*"                         { token_name = NAMEOF(asterisk); return asterisk; }
"/"                         { token_name = NAMEOF(slash); return slash; }
"<="                        { token_name = NAMEOF(equal_smaller_than); return equal_smaller_than; }
"<"                         { token_name = NAMEOF(l_angle_bracket); return l_angle_bracket; }
">="                        { token_name = NAMEOF(equal_greater_than); return equal_greater_than; }
">"                         { token_name = NAMEOF(r_angle_bracket); return r_angle_bracket; }
"=="                        { token_name = NAMEOF(equal); return equal; }
"="                         { token_name = NAMEOF(assign); return assign; }
"!="                        { token_name = NAMEOF(not_equal); return not_equal; }
"!"                         { token_name = NAMEOF(not_); return not_; }
"&&"                        { token_name = NAMEOF(and_); return and_; }
"||"                        { token_name = NAMEOF(or_); return or_; }
[a-zA-Z_][A-Za-z0-9_]*      { token_name = NAMEOF(id); yylval.s = strdup(yytext); return id; }
[0-9]+\.[0-9]+              { token_name = NAMEOF(float_constant); yylval.f = atof(yytext); return float_constant; }
[0-9]+                      { token_name = NAMEOF(int_constant); yylval.i = atoi(yytext); return int_constant; }
\"(\\.|[^"\\])*\"           {
                                token_name = NAMEOF(string_constant);
                                // Remove the surrounding quotes and process escaped quotes
                                char* result = (char*)malloc(yyleng - 1);
                                int j = 0;
                                
                                // Process characters between quotes (skip first and last character)
                                for (int i = 1; i < yyleng - 1; i++) {
                                    if (yytext[i] == '\\' && yytext[i+1] == '"') {
                                        // Handle escaped quote: \"
                                        result[j++] = '"';
                                        i++; // Skip the next character since we processed it
                                    } else {
                                        result[j++] = yytext[i];
                                    }
                                }
                                result[j] = '\0'; // Null terminate
                                
                                yylval.s = strdup(result);
                                return string_constant;
                            }
[ \t\n]+                    {} // ignore whitespace
.                           { token_name = NAMEOF(invalid_character); return invalid_character; } // invalid characters
%%
