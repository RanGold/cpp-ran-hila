#ifndef SEMANTIC_ANALYZER_H
#define SEMANTIC_ANALYZER_H

#include <list>
#include "Token.h"

using namespace std;

class SemanticAnalyzer {
public:
	virtual void analyzeLine(const list<Token*>& tokens) = 0;
	virtual void printSymbolTable() const = 0;
	virtual void reset() = 0;
};

#endif