#include "Token.h"

Token::Token()
	: _type((TokenType) 0), _line(0)
{}

Token::Token(const string& value, TokenType tokenType, int line)
	: _value(value), _type(tokenType), _line(line)
{}

Token::Token(const Token& otherToken)
	: _value(otherToken.getValue()), _type(otherToken.getType()), _line(otherToken.getLine())
{}

const Token& Token::operator=(const Token& token) {
	if (this != &token) {
		_value = token.getValue();
		_type = token.getType();
		_line = token.getLine();
	}

	return *this;
}

bool Token::operator==(const Token& token) const {
	return this->getType() == token.getType() &&
		this->getValue().compare(token.getValue()) == 0;
}

Token::~Token() {}

const string& Token::getValue() const {
	return _value;
}

TokenType Token::getType() const {
	return _type;
}

int Token::getLine() const {
	return _line;
}