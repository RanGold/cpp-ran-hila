#ifndef UNIMPLEMENT_HANDLE_EXCEPTION_H
#define UNIMPLEMENT_HANDLE_EXCEPTION_H

#include "GeneralException.h"

using namespace std;

class UnimplementedHandleException : public GeneralException {
public:
	UnimplementedHandleException(const string& message = "Unimplemented handle was called") : GeneralException(message) {}
};

#endif