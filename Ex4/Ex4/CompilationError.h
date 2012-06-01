#include <string>
#include <iostream>
using namespace std;

class CompilationError{

public:
	CompilationError();
	CompilationError(const string& errorMessage, int lineNumber);
	CompilationError(const CompilationError& otherError);
	virtual ~CompilationError();

	int getLine() const;
	const string& getErrorMessage() const;
	virtual void print() const;

private:
	const int _lineNumber;
	const string _errorMessagae;
};