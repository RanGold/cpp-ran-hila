#ifndef ANALIZER_H
#define ANALIZER_H

#include "SemanticAnalyzer.h"
#include "CompilationError.h"
#include <map>
#include <iostream>
#include <sstream>

class Analyzer : public SemanticAnalyzer {
public:
	Analyzer();

	virtual void analyzeLine(const list<Token*>& tokens);
	virtual void finalizeAnalysis();
	virtual void printSymbolTable() const;
	virtual void reset();

private:
	bool _isFirstCall;
	int _ifCounter;
	int _parenthesesCounter;
	int _bracketsCounter;
	int _curlyBracketsCounter;
	bool _previousTokenInitialized;
	Token _previousToken;
	list<string> _errorMessages;
	map<string,string> _symbolTable;

	static const string LP;
	static const string RP;
	static const string LB;
	static const string RB;
	static const string LCBR;
	static const string RCBR;
	static const string IF;
	static const string ELSE;
	
	void checkIdentifier(const Token* currentToken);
	void checkPreviousPredefinedType(const Token* currentToken);
	void checkIfElse(const string& keyword);
	void checkBrackets(const string& delimiter);
	bool checkMain(const list<Token*>& tokens);
	static bool isValidIdentifier(const string& str);
};

#endif