#ifndef SEMANTIC_ANALYZER_H
#define SEMANTIC_ANALYZER_H

#include <list>
#include "Token.h"

using namespace std;

class SemanticAnalyzer {
public:
	virtual const SemanticAnalyzer& operator=(const SemanticAnalyzer& semanticAnalyzer) { return *this; };
	virtual ~SemanticAnalyzer() {};

	virtual void analyzeLine(const list<Token*>& tokens) = 0;
	virtual void finalizeAnalysis() = 0;
	virtual void printSymbolTable() const = 0;
	virtual void reset() = 0;
};

#endif