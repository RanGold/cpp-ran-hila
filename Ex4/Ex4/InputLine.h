#include <string>
#include <list>
#include <iostream>
#include "Token.h"

using namespace std;

class InputLine {
public:
	static void tokenize(const string& text, int line, const list<Token>& tokens);

private:
	static const string delimiters;
};