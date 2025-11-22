alias compile='g++ -fdiagnostics-color=always -g src/*.cpp src/Mochi*/*.*.cpp src/MochiVM/*.cpp -o mochi.exe'
alias parser='bison -H -o src/MochiParser/MochiParser.tab.cpp src/MochiParser/MochiParser.y'
alias lexer='flex --header-file=src/MochiLexer/MochiLexer.yy.hh -o src/MochiLexer/MochiLexer.yy.cpp src/MochiLexer/MochiLexer.l'
