%{
#include "../MochiParser/MochiParser.tab.hpp"
#include <cstdlib>
#include <string>
extern int yylex();
%}

%option noyywrap

%%
"program"                   { return program_token; }
"main"                      { return main_token; }
"end"                       { return end_token; }
"print"                     { return print_token; }
"while"                     { return while_token; }
"do"                        { return do_token; }
"if"                        { return if_token; }
"else"                      { return else_token; }
"var"                       { return var_token; }
"void"                      { return void_token; }
";"                         { return semicolon; }
","                         { return comma; }
":"                         { return colon; }
"string"                    { return string_token; }
"int"                       { return int_token; }
"float"                     { return float_token; }
"{"                         { return l_curly_brace; }
"}"                         { return r_curly_brace; }
"["                         { return l_square_bracket; }
"]"                         { return r_square_bracket; }
"("                         { return l_parenthesis; }
")"                         { return r_parenthesis; }
"+"                         { return plus; }
"-"                         { return minus; }
"*"                         { return asterisk; }
"/"                         { return slash; }
"<="                        { return equal_smaller_than; }
"<"                         { return l_angle_bracket; }
">="                        { return equal_greater_than; }
">"                         { return r_angle_bracket; }
"=="                        { return equal; }
"="                         { return assign; }
"!="                        { return not_equal; }
"!"                         { return not_; }
[a-zA-Z_][A-Za-z0-9_]*      { return id; }
[0-9]+\.[0-9]+              { yylval.f = atof(yytext); return float_constant; }
[0-9]+                      { yylval.i = atoi(yytext); return int_constant; }
\"(\\.|[^"\\])*\"           {
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
                                
                                yylval.s = result;
                                return string_constant;
                            }
[ \t\n]+                    ; // ignore whitespace
.                           ; // invalid characters
%%
