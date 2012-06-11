#ifndef INPUT_LINE_H
#define INPUT_LINE_H

#include <string>
#include <list>
#include <set>
#include <iostream>
#include "Tokenizer.h"

class InputLine : public Tokenizer {
public:
	InputLine();
	virtual const Tokenizer& operator=(const Tokenizer& tokenizer);
	virtual bool tokenize(const string& text, int line, list<Token*>& tokens) const;

private:
	static bool isNumber(const string& text);
	static bool isWhiteSpace(const string& text);
	bool isOperator(const string& text, int& opLength) const;
	TokenType getTokenType(const string& value) const;
	static bool addToken(const string& value, int line, TokenType tokenType, list<Token*>& tokens);

	set<string> _operators;
	set<string> _predefinedTypes;
	set<string> _keywordsGroup1;
	set<string> _keywordsGroup2;
	unsigned int _maxLengthOperator;

	void initKeywordsSets();
};

#endif