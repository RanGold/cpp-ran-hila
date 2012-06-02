#include "AnalyzerImpl.h"

#define MAIN_FUNCTION_ERROR "File should begin with \"function main\""
#define LP "("
#define RP ")"
#define LB "["
#define RB "]"
#define LCBR "{"
#define RCBR "}"
#define IF "if"
#define ELSE "else"

void AnalyzerImpl::analyze(const list<Token*>& tokens, CompilationError* compilationError){

	//TODO questions
	//1. int short k - do we need to add k to the symbol table as short?
	//2. function is not a perdefined type for some reason - need to handle this is function declaration
	//3. what do we do for "int short float"? do we need to report multiple errors?
	
	if (tokens.size() == 1){
		if (compilationError->getLine() == 1){
			compilationError->addError(MAIN_FUNCTION_ERROR);
		}
		return; //Nothing more to do with a single token
	}

	list<Token*>::const_iterator iter = tokens.begin();
	Token* previousToken = *iter;
	Token* currentToken = *iter;

	if (compilationError->getLine() == 1){
		if (AnalyzerImpl::checkMain(previousToken, currentToken)){
			(iter++)++; // The first tokens are "function main"
		} else{
			compilationError->addError(MAIN_FUNCTION_ERROR);
		}
	}

	for (; iter != tokens.end(); iter++){
		currentToken = *iter;
		switch(currentToken->getType()){
		case IDENTIFIER:
			checkIdentifier(previousToken, currentToken, compilationError);
			break;
		case PREDEFINED_TYPE:
			if (previousToken->getType() == PREDEFINED_TYPE){
				compilationError->addError("Multiple type definition.");
			}
			break;
		case KEYWORD_GROUP1:
			checkPreviousPredefinedType(previousToken, currentToken, compilationError);
			checkIfElse(currentToken->getValue(), compilationError);
			break;
		case DELIMITER:
			checkBrackets(currentToken->getValue(), compilationError);
		case OPERATOR:
		case KEYWORD_GROUP2:
			checkPreviousPredefinedType(previousToken, currentToken, compilationError);
			break;
		}
		previousToken = *iter;
	}
}

void AnalyzerImpl::printSymbolTable() const{
	cout << "Symbol Table:" << endl;
	map<string, string>::const_iterator iter = _symbolTable.begin();
	for (; iter != _symbolTable.end(); iter++){
		cout << (*iter).second << "\t" << (*iter).second << endl;
	}
}

void AnalyzerImpl::checkIdentifier(const Token* previousToken, const Token* currentToken, CompilationError * compilationError){

	if (previousToken->getType() == PREDEFINED_TYPE){ //Declaration of an identifier
		if (_symbolTable.find(currentToken->getValue()) == _symbolTable.end()){
			if (isNumber(currentToken->getValue())){
				compilationError->addError(currentToken->getValue() + " cannot follow " + previousToken->getValue() + ". Only identifiers can follow predefined types.");
			}
			if (isValid(currentToken->getValue())){
				_symbolTable.insert(pair<string,string>(currentToken->getValue(), previousToken->getValue()));
			} else{
				compilationError->addError("Identifier name " + currentToken->getValue() + " is invalid. Identifiers names hvae to start with an alphabetic character.");
			}
		} else {
			compilationError->addError("Identifier \'" + currentToken->getValue() + "\' already declared.");
		}
	} else { //Use of an identifier
		if (_symbolTable.find(currentToken->getValue()) == _symbolTable.end()){
			compilationError->addError("Identifier \'" + currentToken->getValue() + "\' wasn't declared.");
		}
	}
}

void AnalyzerImpl::checkPreviousPredefinedType(const Token* previousToken, const Token* currentToken, CompilationError * compilationError) const{
	if (previousToken->getType() == PREDEFINED_TYPE){
		compilationError->addError(currentToken->getValue() + " cannot follow " + previousToken->getValue() + ". Only identifiers can follow predefined types.");
	}
}

void AnalyzerImpl::checkIfElse(const string& keyword, CompilationError * compilationError){
	if (keyword.compare(IF) == 0){
		_ifCounter++;
	} else if (keyword.compare(ELSE) == 0){
		if (_ifCounter == 0){
			compilationError->addError("\"else\" without \"if\"");
		} else{
			_ifCounter--;
		}
	}
}

void AnalyzerImpl::checkBrackets(const string& delimiter, CompilationError * compilationError){

	if (delimiter.compare(LB) == 0){
		_bracketsCounter++;
	} else if (delimiter.compare(LCBR) == 0){
		_curlyBracketsCounter++;
	} else if (delimiter.compare(LP) == 0){
		_parenthesesCounter++;
	} else if (delimiter.compare(RB) == 0){
		if (_bracketsCounter == 0){
			compilationError->addError("\"]\" without \"[\"");
		} else{
			_bracketsCounter--;
		}
	} else if (delimiter.compare(RCBR) == 0){
		if (_curlyBracketsCounter == 0){
			compilationError->addError("\"}\" without \"{\"");
		} else{
			_curlyBracketsCounter--;
		}
	} else if (delimiter.compare(RP) == 0){
		if (_parenthesesCounter == 0){
			compilationError->addError("\")\" without \"(\"");
		} else {
			_parenthesesCounter--;
		}
	}
}

bool AnalyzerImpl::checkMain(const Token* firstToken, const Token* secondToken){
	return ((firstToken->getValue().compare("function") == 0) &&
		(secondToken->getValue().compare("main") == 0));
}

bool AnalyzerImpl::isNumber(const string& str){
	//TODO
	return true;
}

bool AnalyzerImpl::isValid(const string& str){
	//TODO
	return true;
}