#include "Fish.h"
#include "FishImpl.h"
#include "FishFactory.h"
#include "Subject.h"

Fish::Fish(FishType fishType, Subject* subject) 
	: Observer(subject)
{
	_fishImpl = FishFactory::create(fishType);
	_subject = subject;
	if (_subject != 0) {
		_subject->attach(this);
	}
}

Fish::~Fish() {
	removeFromContainer();

	if (_fishImpl != 0) {
		delete _fishImpl;
	}
}

void Fish::addToContainer(Subject* subject) {
	removeFromContainer();

	_subject = subject;
	if (_subject != 0) {
		_subject->attach(this);
	}
}

void Fish::removeFromContainer() {
	if (_subject != 0) {
		_subject->detach(this);
	}

	_subject = 0;
}

void Fish::update(const Subject* changedSubject, Action action) {
	if (changedSubject == _subject) {
		size_t subjectHashCode = typeid(*changedSubject).hash_code();
		_fishImpl->update(subjectHashCode, action);
	}
}

void Fish::play() {
	_fishImpl->play();
}

void Fish::pause() {
	_fishImpl->pause();
}

void Fish::debug() {
	_fishImpl->debug();
}

void Fish::feed() {
	_fishImpl->feed();
}