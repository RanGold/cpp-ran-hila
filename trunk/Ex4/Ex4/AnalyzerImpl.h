#include "Analyzer.h"
#include <map>

class AnalyzerImpl : public Analyzer {

public:
	virtual void analyze(const list<Token*>& tokens, CompilationError* compilationError);
	void printSymbolTable() const;

private:
	int _ifCounter;
	int _parenthesesCounter;
	int _bracketsCounter;
	int _curlyBracketsCounter;
	map<string,string> _symbolTable;

	void checkIdentifier(const Token* previousToken, const Token* currentToken, CompilationError * compilationError);
	void checkPreviousPredefinedType(const Token* previousToken, const Token* currentToken, CompilationError * compilationError) const;
	void checkIfElse(const string& keyword, CompilationError * compilationError);
	void checkBrackets(const string& delimiter, CompilationError * compilationError);
	static bool checkMain(const Token* firstToken, const Token* secondToken);
	static bool isNumber(const string& str);
	static bool isValid(const string& str);
};