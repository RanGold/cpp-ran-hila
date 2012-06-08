#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <map>
#include "Tokenizer.h"
#include "SemanticAnalyzer.h"
using namespace std;

class Parser {
public:
	static bool parse(const string& path, Tokenizer* tokenizer, SemanticAnalyzer* semanticAnalyzer);

private:

	Parser();
	
	static void print(const string& path, const map<int, int>& tokensPerLine);
	static void clearAndDeleteTokens(list<Token*>& tokens);
};

#endif