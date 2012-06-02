#include "InputLine.h"

const string InputLine::Delimiters = " \t()[]{};<>=+-*&";
const string InputLine::Operators[] = { "++", "--", "==", "->", "=", "+", "-", "*", "&", "<<", ">>" };
const int InputLine::OperatorsNum = 11;
const string InputLine::DelimiterWhiteSpaces = " \t";
const string InputLine::PredefinedTypes[] = { "char", "short", "int", "long", "float", "double", "void", "function" };
const int InputLine::PredefinedTypesNum = 8;
const string InputLine::KeywordsGroup1[] = { "if", "else", "for", "while" };
const int InputLine::KeywordsGroup1Num = 4;
const string InputLine::KeywordsGroup2[] = { "class", "private", "public", "const", "virtual" };
const int InputLine::KeywordsGroup2Num = 5;

bool InputLine::tokenize(const string& text, int line, list<Token*>& tokens) {
	size_t prev = 0, pos;
	int opLength = 0;
	bool res;
	
	while ((pos = text.find_first_of(Delimiters, prev)) != string::npos) {
		if (pos > prev) {
			string temp(text.substr(prev, pos - prev));
			res = addToken(temp, line, getTokenType(temp), tokens);
			prev = pos;
		} else if (isWhiteSpace(text.substr(pos, 1))) {
			prev = pos + 1;
		} else if (isOperator(text, pos, opLength)) {
			res = addToken(text.substr(pos, opLength), line, OPERATOR, tokens);
			prev = pos + opLength;
		} else {
			res = addToken(text.substr(pos, 1), line, DELIMITER, tokens);
			prev = pos + 1;
		}

		if (!res) {
			return false;
		}
	}

	if (prev < text.length()) {
		string temp(text.substr(prev));
		if (!addToken(temp, line, getTokenType(temp), tokens)) {
			return false;
		}
	}

	return true;
}

bool InputLine::isWhiteSpace(const string& text) {
	size_t pos = text.find_first_of(DelimiterWhiteSpaces);
	return pos != string::npos;
}

bool InputLine::isOperator(const string& text, int pos, int& opLength) {
	for (int i = 0; i < OperatorsNum; i++) {
		if (text.length() - pos >= Operators[i].length()) {
			string temp = text.substr(pos, Operators[i].length());
			if (temp.compare(Operators[i]) == 0) {
				opLength = Operators[i].length();
				return true;
			}
		}
	}

	return false;
}

bool InputLine::isWithinArray(const string& text, const string* arr, int arrSize) {
	for (int i = 0; i < arrSize; i++) {
		if (text.compare(arr[i]) == 0) {
			return true;
		}
	}

	return false;
}

bool InputLine::isNumber(const string& text) {
	for (string::const_iterator i = text.begin(); i != text.end(); i++) {
		if (!isdigit(*i)) {
			return false;
		}
	}

	return true;
}

TokenType InputLine::getTokenType(const string& value) {
	if (isWithinArray(value, PredefinedTypes, PredefinedTypesNum)) {
		return PREDEFINED_TYPE;
	} else if (isWithinArray(value, KeywordsGroup1, KeywordsGroup1Num)) {
		return KEYWORD_GROUP1;
	} else if (isWithinArray(value, KeywordsGroup2, KeywordsGroup2Num)) {
		return KEYWORD_GROUP2;
	} else if (isWithinArray(value, Operators, OperatorsNum)) {
		return OPERATOR;
	} else if (isNumber(value)) {
		return NUMBER;
	} else {
		return IDENTIFIER;
	}
}

bool InputLine::addToken(const string& value, int line, TokenType tokenType, list<Token*>& tokens) {
	Token* token = new Token(value, tokenType, line);
	if (token == 0) {
		cout << "Error allocating new token on line " << line << endl;
		return false;
	}

	tokens.push_back(token);
	return true;
}