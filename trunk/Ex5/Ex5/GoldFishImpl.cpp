#include "GoldFishImpl.h"
#include "Subject.h"

GoldFishImpl::GoldFishImpl(Subject* subject) {
	_subject = subject;
	subject->attach(this); 
}

GoldFishImpl::GoldFishImpl(const GoldFishImpl& goldFish){
	_speed = goldFish._speed;
	_size = goldFish._size;
	_transparency = goldFish._transparency;
	_location = goldFish._location;
	_subject = goldFish._subject;
	_subject->attach(this); 
}

GoldFishImpl& GoldFishImpl::operator=(const GoldFishImpl& goldFish){
	if (this != &goldFish){
		_speed = goldFish.getSpeed();
		_size = goldFish.getSize();
		_transparency = goldFish.getTransparency();
		_location = goldFish.getLocation();
		
		if (_subject != 0){
			_subject->detach(this);
		}
		_subject = goldFish.getSubject();
		_subject->attach(this);
	}

	return *this;
}