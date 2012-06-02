#ifndef ANALYZER_H
#define ANALYZER_H

#include <list>
#include "Token.h"
#include "CompilationError.h"
using namespace std;

class Analyzer{
	
public:
	virtual void analyze(const list<Token*>& tokens, CompilationError* compilationError) = 0;
};

#endif