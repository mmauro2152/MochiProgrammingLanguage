#pragma once

#include <iostream>
#include <string>
#include <cstdlib>
#include <queue>
#include "../FuncDir.hpp"
#include "../QuadManager.hpp"
#include "../SemanticCube.hpp"

extern FuncDir funcDir;
extern std::string globalScope;
extern std::string currScope;
extern std::queue<char*> idQueue;
extern vartype currType;
extern int semanticErrors;

extern std::stack<int> argCounters;
extern std::stack<FuncEntry*> funcStack;
extern std::stack<std::vector<operand>> args;

extern QuadManager quadManager;