#include "GoldFishImpl.h"
#include "Subject.h"


GoldFishImpl::GoldFishImpl() {}

GoldFishImpl::GoldFishImpl(Subject* subject) {
	_subject = subject;
	subject->attach(this); 
}

void GoldFishImpl::feed() {
	_speed += 2;
	_size += 1;
}