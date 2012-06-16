#include "Fish.h"
#include "FishImpl.h"
#include "FishFactory.h"

Fish::Fish(FishType fishType){
	_fishImpl = FishFactory::create(fishType);
}

Fish::~Fish() {
	delete _fishImpl;
}

void Fish::update(const Subject* changedSubject, Action action) {
	_fishImpl->update(changedSubject, action);
}

void Fish::printStatus() const{
	_fishImpl->printStatus();
}