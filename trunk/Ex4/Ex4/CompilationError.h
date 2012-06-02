#include <string>
#include <iostream>
#include <list>
using namespace std;

class CompilationError{

public:
	CompilationError();
	CompilationError(int lineNumber);
	CompilationError(const CompilationError& otherError);
	const CompilationError& operator=(const CompilationError& token);
	virtual ~CompilationError();

	bool isPassed() const;
	void setLine(int lineNumber);
	int getLine() const;
	const list<string>& getErrorMessages() const;
	void addError(const string& errorMessage);
	virtual void print() const;
	void reset();

private:
	int _lineNumber;
	list<string> _errorMessages;

	void copyErrorMessages(const list<string>& errorMessages);
};