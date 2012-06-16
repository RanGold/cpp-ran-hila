#include "Fish.h"
#include "FishImpl.h"
#include "FishFactory.h"

Fish::Fish(FishType fishType){
	_fishImpl = FishFactory::create(fishType);
}

Fish::~Fish() {
	delete _fishImpl;
}

void Fish::update(const Subject* changedSubject) {
	_fishImpl->update(changedSubject);
}

void Fish::printStatus() const{
	_fishImpl->printStatus();
}