alias compile='g++ -fdiagnostics-color=always -g SemanticCube.cpp src/VarTable.cpp src/FuncDir.cpp src/MochiLexer/MochiLexer.yy.cpp src/MochiParser/MochiParser.tab.cpp src/main.cpp -o mochi.exe'
alias parser='bison -H -o src/MochiParser/MochiParser.tab.cpp src/MochiParser/MochiParser.y'
alias lexer='flex --header-file=src/MochiLexer/MochiLexer.yy.hh -o src/MochiLexer/MochiLexer.yy.cpp src/MochiLexer/MochiLexer.l'
