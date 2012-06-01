#include <string>
#include <list>
#include <iostream>
#include "Tokenizer.h"

class InputLine : public Tokenizer {
public:
	int tokenize(const string& text, int line, list<Token*>& tokens);

private:
	static const string delimiters;
	static const string delimiterOperators[];
	static const string delimiterWhiteSpaces;

	static bool isWhiteSpace(const string& text, int pos);
	static bool isOperator(const string& text, int pos);
	static bool addToken(const string& text, int start, int end, int line, list<Token*>& tokens);
};