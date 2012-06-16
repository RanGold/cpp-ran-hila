#ifndef UNIMPLEMENT_HANDLE_EXCEPTION_H
#define UNIMPLEMENT_HANDLE_EXCEPTION_H

#include <string>

using namespace std;

class UnimplementedHandleException {
public:
	UnimplementedHandleException(const string& message = "Unimplemented handle was called") : _message(message) {}
	virtual ~UnimplementedHandleException() {};

	const string& getMessage() const { return _message; }
private:
	string _message;
};

#endif