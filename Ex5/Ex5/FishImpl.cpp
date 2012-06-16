#include "FishImpl.h"
#include "Aquarium.h"
#include "UnimplementedHandleException.h"
#include <iostream>
#include <time.h>

using namespace std;

FishImpl::FishImpl() 
	: _speed(0), _size(0), _transparency(0), _location(0), _isPaused(false)
{
	_actionFunctions[typeid(Aquarium).hash_code()][FEED] = &FishImpl::feed;
	_actionFunctions[typeid(Aquarium).hash_code()][PLAY] = &FishImpl::play;
	_actionFunctions[typeid(Aquarium).hash_code()][PAUSE] = &FishImpl::pause;
	_actionFunctions[typeid(Aquarium).hash_code()][DEBUG] = &FishImpl::debug;
}

FishImpl::~FishImpl() {
}

void FishImpl::printStatus() const {
	cout << "Fish: " << id() << endl;
	cout << "\tSpeed: " << _speed << endl;
	cout << "\tSize: " << _size << endl;
	cout << "\tTransparency: " << _transparency << endl;
	cout << "\tLocation: " << _location << endl;
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

void FishImpl::play() {
	_isPaused = false;
}

void FishImpl::pause() {
	_isPaused = false;
}

void FishImpl::debug() {
	time_t now = time(NULL);

	if (!_isPaused){
		_location += (static_cast<unsigned int>(now - _timeStamp)) * _speed;
		_timeStamp = now;
	}

	printStatus();
}

void FishImpl::update(const Subject* changedSubject, Action action) {
	size_t typeHashCode = typeid(*changedSubject).hash_code();
	
	if (_actionFunctions.find(typeHashCode) == _actionFunctions.end() ||
		_actionFunctions[typeHashCode].find(action) == _actionFunctions[typeHashCode].end()) {
			throw UnimplementedHandleException();
	}
	
	(this->*(_actionFunctions[typeHashCode][action]))();
}