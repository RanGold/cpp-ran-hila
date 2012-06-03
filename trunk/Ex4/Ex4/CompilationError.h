#include <string>
#include <iostream>
#include <list>
using namespace std;

class CompilationError {

public:
	CompilationError();
	CompilationError(const list<string>& errorMessages);
	CompilationError(const CompilationError& compilationError);
	const CompilationError& operator=(const CompilationError& compilationError);
	virtual ~CompilationError();

	const list<string>& getErrorMessages() const;
	void addError(const string& errorMessage);

private:
	list<string> _errorMessages;
};