#ifndef GENERAL_EXCEPTION_H
#define GENERAL_EXCEPTION_H

#include <string>

using namespace std;

class GeneralException {
public:
	const string& getMessage() const { return _message; };

protected:
	GeneralException() {}
	GeneralException(const string& message) : _message(message) {}
	virtual ~GeneralException() {}

private:
	string _message;
};

#endif