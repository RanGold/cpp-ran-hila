#include "Fish.h"
#include "FishImpl.h"
#include "FishFactory.h"
#include "Subject.h"
#include "Aquarium.h"
#include "UnimplementedHandleException.h"

Fish::Fish(FishType fishType, Subject* subject) 
	: Observer(subject)
{
	_fishImpl = FishFactory::create(fishType);
	_subject = subject;
	if (_subject != 0) {
		_subject->attach(this);
	}

	_actionFunctions[typeid(Aquarium).hash_code()][FEED] = &Fish::feed;
	_actionFunctions[typeid(Aquarium).hash_code()][PLAY] = &Fish::play;
	_actionFunctions[typeid(Aquarium).hash_code()][PAUSE] = &Fish::pause;
	_actionFunctions[typeid(Aquarium).hash_code()][DEBUG] = &Fish::debug;
}

Fish::~Fish() {
	if (_subject != 0) {
		_subject->detach(this);
	}

	if (_fishImpl != 0) {
		delete _fishImpl;
	}
}

void Fish::update(const Subject* changedSubject, Action action) {
	if (changedSubject == _subject) {
		size_t typeHashCode = typeid(*changedSubject).hash_code();

		if (_actionFunctions.find(typeHashCode) == _actionFunctions.end() ||
			_actionFunctions[typeHashCode].find(action) == _actionFunctions[typeHashCode].end()) {
				throw UnimplementedHandleException();
		}

		(this->*(_actionFunctions[typeHashCode][action]))();
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