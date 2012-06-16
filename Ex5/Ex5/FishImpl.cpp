#include "FishImpl.h"
#include "Aquarium.h"
#include "UnimplementedHandleException.h"
#include <iostream>

using namespace std;

FishImpl::FishImpl() {
	// TODO : maybe feed won't work
	_actionFunctions[typeid(Aquarium).hash_code()][FEED] = &FishImpl::feed;
	_actionFunctions[typeid(Aquarium).hash_code()][PLAY] = &FishImpl::play;
	_actionFunctions[typeid(Aquarium).hash_code()][PLAY] = &FishImpl::pause;
	_actionFunctions[typeid(Aquarium).hash_code()][PLAY] = &FishImpl::debug;
}

FishImpl::~FishImpl() {
}

void FishImpl::printStatus() const {
	cout << "Speed: " << _speed << ", Size: " << _size 
		<< ", Transparency: " << _transparency << ", Location: " << _location << endl;
}

void FishImpl::setSpeed(int speed) {
	_speed = speed;
}

int FishImpl::getSpeed() const {
	return _speed;
}

void FishImpl::setSize(int size) {
	_size = size;
}

int FishImpl::getSize() const {
	return _size;
}

void FishImpl::setTransparency(int transparency) {
	_transparency = transparency;
}

int FishImpl::getTransparency() const {
	return _transparency;
}

void FishImpl::setLocation(int location) {
	_location = location;
}

int FishImpl::getLocation() const {
	return _location;
}

void FishImpl::play(const Subject* subject) {
	// TODO
}

void FishImpl::pause(const Subject* subject) {
	// TODO
}

void FishImpl::debug(const Subject* subject) {
	// TODO
}

void FishImpl::update(const Subject* changedSubject, Action action) {
	size_t typeHashCode = typeid(*changedSubject).hash_code();
	
	if (_actionFunctions.find(typeHashCode) == _actionFunctions.end() ||
		_actionFunctions[typeHashCode].find(action) == _actionFunctions[typeHashCode].end()) {
			throw UnimplementedHandleException();
	}
	
	(this->*(_actionFunctions[typeHashCode][action]))(changedSubject);
}