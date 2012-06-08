#include "Analyzer.h"

const string Analyzer::LP = "(";
const string Analyzer::RP = ")";
const string Analyzer::LB = "[";
const string Analyzer::RB = "]";
const string Analyzer::LCBR = "{";
const string Analyzer::RCBR = "}";
const string Analyzer::IF = "if";
const string Analyzer::ELSE = "else";

Analyzer::Analyzer() 
	: _isFirstCall(true), _ifCounter(0), _parenthesesCounter(0),
	_bracketsCounter(0), _curlyBracketsCounter(0), _previousTokenInitialized(false)
{}

void Analyzer::analyzeLine(const list<Token*>& tokens) {

	// TODO questions
	// 1. int short k - do we need to add k to the symbol table as short?
	// 2. what do we do for "int short float"? do we need to report multiple errors?
	
	_errorMessages.clear();

	if (!checkMain(tokens)) {
		_errorMessages.push_back("File should begin with 'function main'");
	}

	list<Token*>::const_iterator& iter = tokens.begin();
	if (!_previousTokenInitialized && tokens.size() > 0) {
		_previousToken = *tokens.front();
		_previousTokenInitialized = true;
		iter++; 
	}

	Token* currentToken;
	for (; iter != tokens.end(); iter++) {
		currentToken = *iter;
		switch(currentToken->getType()) {
		case IDENTIFIER:
			checkIdentifier(currentToken);
			break;
		case PREDEFINED_TYPE:
			if (_previousToken.getType() == PREDEFINED_TYPE) {
				stringstream message;
				message << "Multiple type definition - '" << _previousToken.getValue() << " " << currentToken->getValue() << "'.";
				_errorMessages.push_back(message.str());
			}
			break;
		case KEYWORD_GROUP1:
			checkPreviousPredefinedType(currentToken);
			checkIfElse(currentToken->getValue());
			break;
		case DELIMITER:
			checkBrackets(currentToken->getValue());
		case KEYWORD_GROUP2:
		case NUMBER:
		case OPERATOR:
			checkPreviousPredefinedType(currentToken);
			break;
		default:
			break;
		}
		
		_previousToken = **iter;
	}

	if (_errorMessages.size() > 0) {
		throw CompilationError(_errorMessages);
	}
}

void Analyzer::finalizeAnalysis() {
	_errorMessages.clear();

	if (_parenthesesCounter > 0) {
		stringstream message;
		message << _parenthesesCounter << " parentheses are not closed.";
		_errorMessages.push_back(message.str());
	}

	if (_bracketsCounter > 0) {
		stringstream message;
		message << _bracketsCounter << " brackets are not closed.";
		_errorMessages.push_back(message.str());
		message.ignore();
	}

	if (_curlyBracketsCounter > 0) {
		stringstream message;
		message << _curlyBracketsCounter << " curly brackets are not closed.";
		_errorMessages.push_back(message.str());
		message.ignore();
	}

	if (_errorMessages.size() > 0) {
		throw CompilationError(_errorMessages);
	}
}

void Analyzer::printSymbolTable() const{
	cout << "Symbol Table:" << endl;
	map<string, string>::const_iterator iter = _symbolTable.begin();
	for (; iter != _symbolTable.end(); iter++){
		cout << (*iter).second << '\t' << (*iter).first << endl;
	}
}

void Analyzer::reset() {
	_isFirstCall = true;
	_ifCounter = 0;
	_parenthesesCounter = 0;
	_bracketsCounter = 0;
	_curlyBracketsCounter = 0;
	_previousTokenInitialized = false;
	_errorMessages.clear();
	_symbolTable.clear();
}

void Analyzer::checkIdentifier(const Token* currentToken) {

	stringstream message;

	// Check for declaration of an identifier
	if (_previousToken.getType() == PREDEFINED_TYPE) {
		if (_symbolTable.find(currentToken->getValue()) == _symbolTable.end()) {
			if (isValidIdentifier(currentToken->getValue())) {
				_symbolTable[currentToken->getValue()] = _previousToken.getValue();
			} else {
				message << "Identifier name '" <<
					currentToken->getValue() <<
					"' is invalid. Identifiers names have to start with an alphabetic character.";
				_errorMessages.push_back(message.str());
			}
		} else {
			message << "Identifier '" << currentToken->getValue() << "' already declared.";
			_errorMessages.push_back(message.str());
		}
	} 
	// Use of an identifier
	else { 
		if (_symbolTable.find(currentToken->getValue()) == _symbolTable.end()) {
			message << "Identifier '" << currentToken->getValue() << "' wasn't declared.";
			_errorMessages.push_back(message.str());
		}
	}
}

void Analyzer::checkPreviousPredefinedType(const Token* currentToken) {
	if (_previousToken.getType() == PREDEFINED_TYPE) {
		stringstream message;
		message << '\'' << currentToken->getValue() <<
			"' cannot follow '" <<
			_previousToken.getValue() << 
			"'. Only identifiers can follow predefined types.";
		_errorMessages.push_back(message.str());
	}
}

void Analyzer::checkIfElse(const string& keyword) {
	if (keyword.compare(IF) == 0) {
		_ifCounter++;
	} else if (keyword.compare(ELSE) == 0) {
		if (_ifCounter == 0) {
			_errorMessages.push_back("'else' without 'if'");
		} else {
			_ifCounter--;
		}
	}
}

void Analyzer::checkBrackets(const string& delimiter) {

	if (delimiter.compare(LB) == 0) {
		_bracketsCounter++;
	} else if (delimiter.compare(LCBR) == 0) {
		_curlyBracketsCounter++;
	} else if (delimiter.compare(LP) == 0) {
		_parenthesesCounter++;
	} else if (delimiter.compare(RB) == 0) {
		if (_bracketsCounter == 0) {
			_errorMessages.push_back("']' without '['");
		} else{
			_bracketsCounter--;
		}
	} else if (delimiter.compare(RCBR) == 0) {
		if (_curlyBracketsCounter == 0) {
			_errorMessages.push_back("'}' without '{'");
		} else{
			_curlyBracketsCounter--;
		}
	} else if (delimiter.compare(RP) == 0) {
		if (_parenthesesCounter == 0){
			_errorMessages.push_back("')' without '('");
		} else {
			_parenthesesCounter--;
		}
	}
}

bool Analyzer::checkMain(const list<Token*>& tokens) {
	if (!_isFirstCall) {
		return true;
	}

	_isFirstCall = false;
	return tokens.size() >= 2 && 
		*(tokens.front()) == Token("function", PREDEFINED_TYPE, 0) &&
		**(++tokens.begin()) == Token("main", IDENTIFIER, 0);
}

bool Analyzer::isValidIdentifier(const string& str) {
	return str.size() > 0 && !isdigit(str.at(0));
}