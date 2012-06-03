#include "CompilationError.h"

CompilationError::CompilationError() {}

CompilationError::CompilationError(const list<string>& errorMessages) 
	: _errorMessages(errorMessages)
{
}

CompilationError::CompilationError(const CompilationError& otherError)
	: _errorMessages(otherError.getErrorMessages())
{}

const CompilationError& CompilationError::operator=(const CompilationError& otherError) {
	if (this != &otherError) {
		_errorMessages = otherError.getErrorMessages();
	}

	return *this;
}

CompilationError::~CompilationError() {}

const list<string>& CompilationError::getErrorMessages() const {
	return _errorMessages;
}

void CompilationError::addError(const string& errorMessage) {
	// TODO: check string scope of liveliness
	_errorMessages.push_back(string(errorMessage));
}