#include "SalmonFishImpl.h"
#include "Subject.h"

SalmonFishImpl::SalmonFishImpl() {}

SalmonFishImpl::SalmonFishImpl(Subject* subject) {
	_subject = subject;
	subject->attach(this); 
}

void SalmonFishImpl::feed() {
	_transparency += 1;
	_size += 2;
}