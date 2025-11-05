#include <iostream>
#include "MochiParser/MochiParser.tab.hpp"
#include "MochiLexer/MochiLexer.yy.hh"
#include "SemanticCube.hpp"
#include <vector>
#include <string>
#include <stdexcept>

extern FILE *yyin;
extern int yyparse();
extern int yylex();
extern std::string token_name;
extern char* yytext;

std::vector<std::string> correct_cases;
std::vector<std::string> incorrect_cases;

bool check_parsing_case(std::string c) 
{
    FILE *f = fmemopen((void *)c.c_str(), c.size(), "r");
    yyin = f;

    int result = yyparse();
    fclose(f);    

    return !result;
}

void test_parser(int argc, char** argv){
    if (argc > 2)
    {
        // Read from file
        yyin = fopen(argv[2], "r");
        if (!yyin)
        {
            std::cerr << "Error: Cannot open file: " << argv[2] << std::endl;
            return;
        }
        std::cout << "Parsing file: " << argv[2] << std::endl;
        
        int result = yyparse();

        if (result == 0)
        {
            std::cout << "Parse successful!" << std::endl;
        }
        else
        {
            std::cout << "Parse failed" << std::endl;
        }

        fclose(yyin);
    }
    else
    {
        int correct = 0;
        int incorrect = 0;

        for (std::string c : correct_cases)
        {
            if (check_parsing_case(c))
                correct++;
        }

        std::cout << correct / correct_cases.size() << " precision for correct cases" << std::endl;

        for (std::string c : incorrect_cases)
        {
            if (!check_parsing_case(c))
                incorrect++;
        }

        std::cout << incorrect / incorrect_cases.size() << " precision for incorrect cases" << std::endl;
    }
}

void test_lexer(int argc, char** argv) {
    
    if (argc > 2) {
        yyin = fopen(argv[2], "r");
        if (!yyin)
        {
            std::cerr << "Error: Cannot open file: " << argv[1] << std::endl;
            return;
        }
        std::cout << "Scanning file: " << argv[2] << std::endl;

        int token;
        while ((token = yylex()) != 0) {
            std::cout << token_name << ": " << yytext << std::endl;
        }

        fclose(yyin);
    }
    
    else {
        std::cerr << "Error: Missing input file" << std::endl;
    }
}

void test_semantic_cube(){
    SemanticCube::populate();

    CubeEntry entry = CubeEntry(vartype::string_type, vartype::bool_type, operatortype::not_equal);
    vartype res = SemanticCube::resultingType(entry);

    entry.rightOperand= vartype::string_type;
    res = SemanticCube::resultingType(entry);

    return;
}

int main(int argc, char **argv)
{
    correct_cases = {
        // empty
        R"_(

        program myProgram;
        main {}
        end

        )_",

        // assing statement
        R"_(

        program myProgram;
        var x: int;
        main {
            x = 10;
        }
        end

        )_",

        // print statement
        R"_(

        program myProgram;
        var x: int;
        main {
            x = 10;
            print(x);
        }
        end

        )_",

        // condition statement
        R"_(

        program myProgram;
        var x: int;
        main {
            x = 10;
            print(x);
            if (x > 4) {
                print("x is bigger than 4");
            };
        }
        end

        )_",

        // cycle statement
        R"_(

        program myProgram;
        var x: int;
        main {
            x = 10;
            print(x);
            if (x > 4) {
                print("x is bigger than 4");
            };

            while (x > 0) do {
                x = x - 1;
            };
        }
        end

        )_",

        // simple function
        R"_(

        program myProgram;
        var x: int;

        void myFunc() [{
            print("this is my func");
        }];

        main {
            x = 10;
            print(x);
            if (x > 4) {
                print("x is bigger than 4");
            };

            while (x > 0) do {
                x = x - 1;
            };

            myFunc();
        }
        end

        )_",

        // function with params
        R"_(

        program myProgram;
        var x: int;

        void myFunc(y: int, z: float, s: string) [{
            print("this is my func");
            print("these are the params: ", y, ", ", z);
        }];

        main {
            x = 10;
            print(x);
            if (x > 4) {
                print("x is bigger than 4");
            };

            while (x > 0) do {
                x = x - 1;
            };

            myFunc(x, 3.0, "hola");
        }
        end

        )_",

        // math function with params
        R"_(

        program myProgram;
        var x: int;

        void myFunc(y: int, z: float, s: string) [{
            print("this is my func");
            print("these are the params: ", y, ", ", z);
        }];

        void myMathFunc(n: float) [{
            n = n * 3 + 2 / 3 + (n * 24 / 3.5);
            n = -n;
            print(n);
        }];

        main {
            x = 10;
            print(x);
            if (x > 4) {
                print("x is bigger than 4");
            };

            while (x > 0) do {
                x = x - 1;
            };

            myFunc(x, 3.0, "hola");
            myMathFunc(5.3);
        }
        end

        )_",

    };

    incorrect_cases = {

        // Missing 'end' before EOF
        R"_(
        program test;
        main {
            x = 5;
        }
        )_",

        // Missing semicolon after 'program test'
        R"_(
        program test
        var x: int;
        main {
            x = 5;
        } end
        )_",

        // Missing ':' in variable declaration
        R"_(
        program test;
        var x int;
        main {
            x = 5;
        } end
        )_",

        // Missing semicolon after var declaration
        R"_(
        program test;
        var x: int
        main {
            x = 5;
        } end
        )_",

        // Missing closing ']' in function body
        R"_(
        program test;
        void func() [
            var y: int;
            {
                print("ok");
            }
        ; 
        main {
        } end
        )_",

        // Missing braces for if body
        R"_(
        program test;
        main {
            if (x > 5) 
                print("Hi");
            ;
        } end
        )_",

        // Missing parentheses around while condition
        R"_(
        program test;
        main {
            while x < 10 do {
                x = x + 1;
            };
        } end
        )_",

        // Trailing comma in print arguments
        R"_(
        program test;
        main {
            print("ok", ); 
        } end
        )_",

        // Invalid expression: operator missing operand
                R"_(
        program test;
        main {
            x = (5 + ) * 3;
        } end
        )_",

        // Missing closing parenthesis and semicolon in function call
        R"_(
        program test;
        main {
            unknownFunction(1, 2
        } end
        )_",

        // Missing colon in function parameter declaration
        R"_(
        program test;
        void f(a int) [
            { print("oops") };
        ]; 
        main {
        } end
        )_",

        // Missing braces for else body
        R"_(
        program test;
        main {
            if (x > 5) { print("ok"); } else print("fail");
        } end
        )_",

        // Missing semicolon inside while body
        R"_(
        program test;
        main {
            while (x < 5) do {
                print("hi")
            }; 
        } end
        )_",

        // Invalid expression: trailing operator
        R"_(
        program test;
        main {
            x = 5 + ;
        } end
        )_",

        // Missing semicolon after assignment inside function
        R"_(
        program test;
        var x: float;
        void f() [
            { x = 10 }
        ]; 
        main {
        } 
        end
        )_"
    };

    if (argc == 1){
        throw std::runtime_error("missing argument parser/lexer/semantic_cube");
    }

    std::string test_case = argv[1]; // parser/lexer

    if (test_case == "parser") {
        test_parser(argc, argv);
    }

    else if (test_case == "lexer"){
        test_lexer(argc, argv);
    }

    else if (test_case == "semantic_cube") {
        test_semantic_cube();
    }

    else {
        throw std::runtime_error("invalid argument");
    }

    return 0;
}