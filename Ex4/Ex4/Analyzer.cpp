#include "Analyzer.h"

const string Analyzer::MainFunctionError = "File should begin with \"function main\"";
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
	_bracketsCounter(0), _curlyBracketsCounter(0)
{}
	
Analyzer::Analyzer(const Analyzer& analyzer) 
	: _isFirstCall(analyzer._isFirstCall), _ifCounter(analyzer._ifCounter), _parenthesesCounter(analyzer._parenthesesCounter),
	_bracketsCounter(analyzer._bracketsCounter), _curlyBracketsCounter(analyzer._curlyBracketsCounter),
	_errorMessages(analyzer._errorMessages), _previousToken(analyzer._previousToken), _symbolTable(analyzer._symbolTable)
{}

const Analyzer& Analyzer::operator=(const Analyzer& analyzer) {
	if (this != &analyzer) {
		_isFirstCall = analyzer._isFirstCall;
		_ifCounter = analyzer._ifCounter;
		_parenthesesCounter = analyzer._parenthesesCounter;
		_bracketsCounter = analyzer._bracketsCounter;
		_curlyBracketsCounter = analyzer._curlyBracketsCounter;
		_previousToken = analyzer._previousToken;
		_errorMessages = analyzer._errorMessages;
		_symbolTable = analyzer._symbolTable;
	}

	return *this;
}
	
Analyzer::~Analyzer() {}

void Analyzer::analyzeLine(const list<Token*>& tokens) {

	// TODO questions
	// 1. int short k - do we need to add k to the symbol table as short?
	// 2. function is not a perdefined type for some reason - need to handle this is function declaration
	// 3. what do we do for "int short float"? do we need to report multiple errors?
	
	_errorMessages.clear();

	if (!checkMain(tokens)) {
		_errorMessages.push_back(MainFunctionError);
	}

	list<Token*>::const_iterator& iter = tokens.begin();
	Token* currentToken;

	// TODO : all verifications need to check if _previousToken isn't null
	for (; iter != tokens.end(); iter++) {
		currentToken = *iter;
		switch(currentToken->getType()) {
		case IDENTIFIER:
			checkIdentifier(_previousToken, currentToken);
			break;
		case PREDEFINED_TYPE:
			if (_previousToken->getType() == PREDEFINED_TYPE) {
				_errorMessages.push_back("Multiple type definition.");
			}
			break;
		case KEYWORD_GROUP1:
			checkPreviousPredefinedType(_previousToken, currentToken);
			checkIfElse(currentToken->getValue());
			break;
		case DELIMITER:
			checkBrackets(currentToken->getValue());
		case KEYWORD_GROUP2:
			checkPreviousPredefinedType(_previousToken, currentToken);
			break;
		default:
			break;
		}
		
		_previousToken = *iter;
	}

	if (_errorMessages.size() > 0) {
		throw CompilationError(_errorMessages);
	}
}

void Analyzer::printSymbolTable() const{
	cout << "Symbol Table:" << endl;
	map<string, string>::const_iterator iter = _symbolTable.begin();
	for (; iter != _symbolTable.end(); iter++){
		cout << (*iter).second << "\t" << (*iter).second << endl;
	}
}

void Analyzer::reset() {
	_isFirstCall = true;
	_ifCounter = 0;
	_parenthesesCounter = 0;
	_bracketsCounter = 0;
	_curlyBracketsCounter = 0;
	_previousToken = 0;
	_errorMessages.clear();
	_symbolTable.clear();
}

void Analyzer::checkIdentifier(const Token* previousToken, const Token* currentToken) {

	if (previousToken->getType() == PREDEFINED_TYPE) { //Declaration of an identifier
		if (_symbolTable.find(currentToken->getValue()) == _symbolTable.end()) {
			if (currentToken->getType() != IDENTIFIER) {
				_errorMessages.push_back(currentToken->getValue() + " cannot follow " + previousToken->getValue() + ". Only identifiers can follow predefined types.");
			}
			if (isValidIdentifier(currentToken->getValue())) {
				_symbolTable.insert(pair<string,string>(currentToken->getValue(), previousToken->getValue()));
			} else {
				_errorMessages.push_back("Identifier name " + currentToken->getValue() + " is invalid. Identifiers names hvae to start with an alphabetic character.");
			}
		} else {
			_errorMessages.push_back("Identifier \'" + currentToken->getValue() + "\' already declared.");
		}
	} else { //Use of an identifier
		if (_symbolTable.find(currentToken->getValue()) == _symbolTable.end()) {
			_errorMessages.push_back("Identifier \'" + currentToken->getValue() + "\' wasn't declared.");
		}
	}
}

void Analyzer::checkPreviousPredefinedType(const Token* previousToken, const Token* currentToken) {
	if (previousToken->getType() == PREDEFINED_TYPE){
		_errorMessages.push_back(currentToken->getValue() + " cannot follow " + previousToken->getValue() + ". Only identifiers can follow predefined types.");
	}
}

void Analyzer::checkIfElse(const string& keyword) {
	if (keyword.compare(IF) == 0){
		_ifCounter++;
	} else if (keyword.compare(ELSE) == 0){
		if (_ifCounter == 0){
			_errorMessages.push_back("\"else\" without \"if\"");
		} else{
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
		if (_bracketsCounter == 0){
			_errorMessages.push_back("\"]\" without \"[\"");
		} else{
			_bracketsCounter--;
		}
	} else if (delimiter.compare(RCBR) == 0) {
		if (_curlyBracketsCounter == 0) {
			_errorMessages.push_back("\"}\" without \"{\"");
		} else{
			_curlyBracketsCounter--;
		}
	} else if (delimiter.compare(RP) == 0) {
		if (_parenthesesCounter == 0){
			_errorMessages.push_back("\")\" without \"(\"");
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
		**(tokens.begin()++) == Token("main", IDENTIFIER, 0);
}

bool Analyzer::isValidIdentifier(const string& str) {
	return str.size() > 0 && !isdigit(str.at(0));
}