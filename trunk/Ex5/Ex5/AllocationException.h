#ifndef ALLOCATION_EXCEPTION_H
#define ALLOCATION_EXCEPTION_H

#include "GeneralException.h"

using namespace std;

class AllocationException : public GeneralException {
public:
	AllocationException(const string& message = "Failed to allocate memory") : GeneralException(message) {}
};

#endif