#include <iostream>
#include <cstdio>
#include "MochiParser/MochiParser.tab.hpp"
#include <vector>
#include <string>
#include <unistd.h>

extern FILE *yyin;
extern int yyparse();

bool check_case(std::string c) 
{
    FILE *f = fmemopen((void *)c.c_str(), c.size(), "r");
    yyin = f;

    int result = yyparse();
    fclose(f);    

    return !result;
}

int main(int argc, char **argv)
{
    std::vector<std::string> correct_cases = {
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

    std::vector<std::string> incorrect_cases = {

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

    int result = 1;

    if (argc > 1)
    {
        // Read from file
        yyin = fopen(argv[1], "r");
        if (!yyin)
        {
            std::cerr << "Error: Cannot open file: " << argv[1] << std::endl;
            return 1;
        }
        std::cout << "Parsing file: " << argv[1] << std::endl;
        
        result = yyparse();

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
            if (check_case(c))
                correct++;
        }

        std::cout << correct / correct_cases.size() << " precision for correct cases" << std::endl;

        for (std::string c : incorrect_cases)
        {
            if (!check_case(c))
                incorrect++;
        }

        std::cout << incorrect / incorrect_cases.size() << " precision for incorrect cases" << std::endl;
    }

    return 0;
}