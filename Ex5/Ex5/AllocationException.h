#ifndef ALLOCATION_EXCEPTION_H
#define ALLOCATION_EXCEPTION_H

#include <string>

using namespace std;

class AllocationException {
public:
	AllocationException(const string& message = "Failed to allocate memory") : _message(message) {}
	virtual ~AllocationException() {};

	const string& getMessage() const { return _message; }
private:
	string _message;
};

#endif