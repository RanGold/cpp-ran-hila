#ifndef FISH_IMPL_H
#define FISH_IMPL_H

#include "Observer.h"

class FishImpl: public Observer {

public:
	virtual	~FishImpl();
    virtual void update(const Subject* changedSubject);
	virtual void printStatus() const;

	void setSpeed(int speed);
	int getSpeed() const;
	void setSize(int size);
	int getSize() const;
	void setTransparency(int transparency);
	int getTransparency() const;
	void setLocation(int Location);
	int getLocation() const;
	void setSubject(Subject* subject);
	Subject* getSubject() const;
	
	virtual void feed()=0;
	void play();
	void pause();
	void debug() const;
protected:
	int _speed;
	int _size;
	int _transparency;
	int _location;
};

#endif