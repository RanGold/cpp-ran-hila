#include "Fish.h"
#include "FishImpl.h"
#include "FishFactory.h"
#include "Subject.h"

Fish::Fish(FishType fishType, Subject* subject = 0) {
	_fishImpl = FishFactory::create(fishType);
	_subject = subject;
	if (_subject != 0) {
		_subject->attach(this);
	}
}

Fish::~Fish() {
	_subject->detach(this);
	delete _fishImpl;
}

void Fish::update(const Subject* changedSubject, Action action) {
	if (changedSubject == _subject) {
		_fishImpl->update(changedSubject, action);
	}
}