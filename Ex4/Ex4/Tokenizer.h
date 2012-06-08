#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <string>
#include <list>
#include "Token.h"

class Tokenizer {
public:
	virtual bool tokenize(const string& text, int line, list<Token*>& tokens) const = 0;
	virtual ~Tokenizer() {};

protected:
	static const string Delimiters;
	static const string DelimiterWhiteSpaces;
	static const string OperatorsArr[];
	static const int OperatorsNum;
	static const string PredefinedTypesArr[];
	static const int PredefinedTypesNum;
	static const string KeywordsGroup1Arr[];
	static const int KeywordsGroup1Num;
	static const string KeywordsGroup2Arr[];
	static const int KeywordsGroup2Num;
};

#endif