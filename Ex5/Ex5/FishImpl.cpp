#include "FishImpl.h"
#include "Aquarium.h"
#include <iostream>
#include <time.h>

using namespace std;

FishImpl::FishImpl() 
	: _speed(0), _size(0), _transparency(0), _location(0), _isPaused(false)
{}

FishImpl::~FishImpl() {
}

void FishImpl::printStatus() const {
	cout << id() << ":" << endl;
	cout << "\tSpeed: " << getSpeed() << endl;
	cout << "\tSize: " << getSize() << endl;
	cout << "\tTransparency: " << getTransparency() << endl;
	cout << "\tLocation: " << getLocation() << endl;
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
	_isPaused = true;
}

void FishImpl::debug() {
	time_t now = time(NULL);

	if (!_isPaused){
		_location += (static_cast<unsigned int>(now - _timeStamp)) * _speed;
		_timeStamp = now;
	}

	printStatus();
}