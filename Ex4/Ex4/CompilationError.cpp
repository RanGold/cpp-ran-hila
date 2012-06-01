#include "CompilationError.h"

CompilationError::CompilationError():_errorMessagae(0), _lineNumber(0){}

CompilationError::CompilationError(const string& errorMessage, int lineNumber)
	:_errorMessagae(errorMessage), _lineNumber(lineNumber){}

CompilationError::CompilationError(const CompilationError& otherError)
	:_errorMessagae(otherError.getErrorMessage()), _lineNumber(otherError.getLine()){}

CompilationError::~CompilationError(){}

int CompilationError::getLine() const{
	return _lineNumber;
}

const string& CompilationError::getErrorMessage() const{
	return _errorMessagae;
}
	
void CompilationError::print() const{
	cout << "Line " << _lineNumber << ": " << _errorMessagae << endl;
}