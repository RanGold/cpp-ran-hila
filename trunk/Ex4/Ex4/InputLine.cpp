#include "InputLine.h"

InputLine::InputLine() {
	initKeywordsSets();
}

const Tokenizer& InputLine::operator=(const Tokenizer& tokenizer) {
	if (this != &tokenizer && typeid(tokenizer) == typeid(InputLine)) {
		*this = (InputLine&)tokenizer;
	}
	
	return *this;
}

bool InputLine::tokenize(const string& text, int line, list<Token*>& tokens) const {
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
		} else if (isOperator(text.substr(pos), opLength)) {
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

bool InputLine::isOperator(const string& text, int& opLength) const {
	// Trying to find the longest operator match
	for (int i = min(_maxLengthOperator, text.length()); i >= 1; i--) {
		string temp = text.substr(0, i);
		if (_operators.find(temp) != _operators.end()) {
			opLength = i;
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

TokenType InputLine::getTokenType(const string& value) const {
	if (isNumber(value)) {
		return NUMBER;
	} else if (_predefinedTypes.find(value) != _predefinedTypes.end()) {
		return PREDEFINED_TYPE;
	} else if (_keywordsGroup1.find(value) != _keywordsGroup1.end()) {
		return KEYWORD_GROUP1;
	} else if (_keywordsGroup2.find(value) != _keywordsGroup2.end()) {
		return KEYWORD_GROUP2;
	} else if (_operators.find(value) != _operators.end()) {
		return OPERATOR;
	} else if (Delimiters.find_first_of(value, 0) != string::npos) {
		return DELIMITER;
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

void InputLine::initKeywordsSets() {
	_maxLengthOperator = 0;
	for (int i = 0; i < OperatorsNum; i++) {
		_operators.insert(OperatorsArr[i]);
		if (OperatorsArr[i].length() > _maxLengthOperator) {
			_maxLengthOperator = OperatorsArr[i].length();
		}
	}
	
	for (int i = 0; i < PredefinedTypesNum; i++) {
		_predefinedTypes.insert(PredefinedTypesArr[i]);
	}

	for (int i = 0; i < KeywordsGroup1Num; i++) {
		_keywordsGroup1.insert(KeywordsGroup1Arr[i]);
	}

	for (int i = 0; i < KeywordsGroup2Num; i++) {
		_keywordsGroup2.insert(KeywordsGroup2Arr[i]);
	}
}