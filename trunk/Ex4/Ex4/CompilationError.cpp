#include "CompilationError.h"

CompilationError::CompilationError():_lineNumber(0){}

CompilationError::CompilationError(int lineNumber):_lineNumber(lineNumber){}

CompilationError::CompilationError(const CompilationError& otherError):_lineNumber(otherError.getLine()){
	copyErrorMessages(otherError.getErrorMessages());
}

const CompilationError& CompilationError::operator=(const CompilationError& otherError){

	if (this != &otherError){
		_lineNumber = otherError.getLine();
		copyErrorMessages(otherError.getErrorMessages());
	}

	return *this;
}

CompilationError::~CompilationError(){}


bool CompilationError::isPassed() const{
	return _errorMessages.size() == 0;
}

void CompilationError::setLine(int lineNumber){
	_lineNumber = lineNumber;
}

int CompilationError::getLine() const{
	return _lineNumber;
}

const list<string>& CompilationError::getErrorMessages() const{
	return _errorMessages;
}

void CompilationError::addError(const string& errorMessage){
	_errorMessages.push_back(errorMessage);
}

void CompilationError::print() const{
	cout << "Compilation error/s in line " << _lineNumber << ": " << endl;
	list<string>::const_iterator iter = _errorMessages.begin();
	for(; iter != _errorMessages.end(); iter++){
		cout << *iter << endl;
	}
}

void CompilationError::reset(){
	_lineNumber = 0; //TODO is it necessary?
	_errorMessages.clear();
}

void CompilationError::copyErrorMessages(const list<string>& errorMessages){

	list<string>::const_iterator iter = errorMessages.begin();
	for(; iter != errorMessages.end(); iter++){
		_errorMessages.push_back(*iter);
	}
}