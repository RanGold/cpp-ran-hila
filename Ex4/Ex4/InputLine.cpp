#include "InputLine.h"
#include <sstream>

const string InputLine::delimiters = " \t()[]{};<>=+-*&";
const string InputLine::delimiterOperators[] = { "++", "--", "->", "<<", ">>" };
const string InputLine::delimiterWhiteSpaces = " \t";

int InputLine::tokenize(const string& text, int line, list<Token*>& tokens) {
	size_t prev = 0, pos, tempPrev = 0, tempPos;
	
	while ((pos = text.find_first_of(delimiters, prev)) != string::npos) {
		if (pos > prev) {
			addToken(text, prev, pos, line, tokens);
			prev = pos+1;
		} else if (isWhiteSpace(text, pos)) {
			prev = pos + 1;
		} else if (isOperator(text, pos)) {
			Token* token = new Token(text.substr(pos, 2), OPERATOR, line);
			if (token == 0) {
				cout << "Error allocating new token on line " << line << endl;
				return -1;
			}

			tokens.push_back(token);
			prev = pos + 2;
		} else {
			Token* token = new Token(text.substr(pos, 1), DELIMITER, line);
			if (token == 0) {
				cout << "Error allocating new token on line " << line << endl;
				return -1;
			}

			tokens.push_back(token);
			prev = pos + 1;
		}
	}

	if (prev < text.length()) {
	//	tokens.push_back(text.substr(prev, std::string::npos));
	}

	return 0;
}

bool InputLine::isWhiteSpace(const string& text, int pos) {
	return false;
}

bool InputLine::isOperator(const string& text, int pos) {
	return false;
}

bool InputLine::addToken(const string& text, int start, int end, int line, list<Token*>& tokens) {
	return false;
}