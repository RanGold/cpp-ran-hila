#include <string>
#include <list>
#include <iostream>
#include "Tokenizer.h"

class InputLine : public Tokenizer {
public:
	bool tokenize(const string& text, int line, list<Token*>& tokens);

private:
	static const string Delimiters;
	static const string Operators[];
	static const int OperatorsNum;
	static const string DelimiterWhiteSpaces;
	static const string PredefinedTypes[];
	static const int PredefinedTypesNum;
	static const string KeywordsGroup1[];
	static const int KeywordsGroup1Num;
	static const string KeywordsGroup2[];
	static const int KeywordsGroup2Num;

	static bool isWithinArray(const string& text, const string* arr, int arrSize);
	static bool isWhiteSpace(const string& text);
	static bool isOperator(const string& text, int pos, int& opLength);
	static TokenType getTokenType(const string& value);
	static bool addToken(const string& value, int line, TokenType tokenType, list<Token*>& tokens);
};