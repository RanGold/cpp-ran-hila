#include "FishImpl.h"
#include <iostream>

using namespace std;

const int FishImpl::InitialSpeed = 5;

FishImpl::FishImpl() 
	: _speed(InitialSpeed), _size(0), _transparency(0), _location(0)
{}

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