#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <string>
#include <list>
#include "Token.h"

class Tokenizer {
public:
	virtual int tokenize(const string& text, int line, list<Token*>& tokens) = 0;
};

#endif