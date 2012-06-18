#include <iostream>
#include "FishImpl.h"
#include "Aquarium.h"
#include "UnimplementedHandleException.h"

using namespace std;

const int FishImpl::InitialSpeed = 5;

FishImpl::FishImpl() 
	: _speed(InitialSpeed), _size(0), _transparency(0), _location(0)
{
	size_t aquariumHashCode = typeid(Aquarium).hash_code();
	_actionFunctions[aquariumHashCode][FEED] = &FishImpl::feed;
	_actionFunctions[aquariumHashCode][PLAY] = &FishImpl::play;
	_actionFunctions[aquariumHashCode][PAUSE] = &FishImpl::pause;
	_actionFunctions[aquariumHashCode][DEBUG] = &FishImpl::debug;
}

FishImpl::~FishImpl() {}

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

void FishImpl::update(size_t subjectHashCode, Action action) {
	if (_actionFunctions.find(subjectHashCode) == _actionFunctions.end() ||
		_actionFunctions[subjectHashCode].find(action) == _actionFunctions[subjectHashCode].end()) {
			throw UnimplementedHandleException();
	}

	(this->*(_actionFunctions[subjectHashCode][action]))();
}

void FishImpl::play() {
	setSpeed(InitialSpeed);
}

void FishImpl::pause() {
	setSpeed(0);
}

void FishImpl::debug() {
	_location += getSpeed();

	cout << id() << ":" << endl;
	cout << "\tSpeed: " << getSpeed() << endl;
	cout << "\tSize: " << getSize() << endl;
	cout << "\tTransparency: " << getTransparency() << endl;
	cout << "\tLocation: " << getLocation() << endl;
}