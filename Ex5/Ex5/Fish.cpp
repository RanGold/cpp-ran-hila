#include "Fish.h"
#include "FishImpl.h"
#include "FishFactory.h"
#include "Subject.h"

Fish::Fish(FishType fishType) {
	_fishImpl = FishFactory::create(fishType);
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