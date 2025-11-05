alias compile='g++ -fdiagnostics-color=always -g SemanticCube.cpp VarTable.cpp FuncDir.cpp MochiLexer/MochiLexer.yy.cpp MochiParser/MochiParser.tab.cpp main.cpp -o mochi.exe'
alias parser='bison -H -o MochiParser/MochiParser.tab.cpp MochiParser/MochiParser.y'
alias lexer='flex --header-file=MochiLexer/MochiLexer.yy.hh -o MochiLexer/MochiLexer.yy.cpp MochiLexer/MochiLexer.l'