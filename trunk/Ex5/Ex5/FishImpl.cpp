#include "FishImpl.h"
#include "Subject.h"
#include "Aquarium.h"
#include <iostream>
using namespace std;

FishImpl::~FishImpl() {}

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

void FishImpl::setSubject(Subject* subject) {
	if (_subject != 0){
		_subject->detach(this);
	}

	_subject = subject;
	_subject->attach(this);
}

Subject* FishImpl::getSubject() const {
	return _subject;
}

void FishImpl::update(const Subject* changedSubject, Action action) {

	if (changedSubject != _subject) {
		// TODO maybe print error message;
		return;	
	}

	/* Not to use RTTI, use action instead
	Aquarium* aquarium = (Aquarium*) changedSubject;
	switch (aquarium->getPressedButton()){
	case FEED: feed();
	case PLAY: play();
	case PAUSE: pause();
	case DEBUG: debug();
	}
	*/
}