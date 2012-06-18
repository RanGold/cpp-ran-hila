#ifndef FISH_IMPL_H
#define FISH_IMPL_H

#include<string>

using namespace std;

enum Action;
class Subject;

class FishImpl {
public:
	FishImpl();
	virtual	~FishImpl();

	void setSpeed(int speed);
	int getSpeed() const;
	void setSize(int size);
	int getSize() const;
	void setTransparency(int transparency);
	int getTransparency() const;
	void setLocation(int Location);
	int getLocation() const;

	virtual string id() const = 0;
	virtual void feed() = 0;
	void play();
	void pause();
	virtual void debug();

protected:
	int _speed;
	int _size;
	int _transparency;
	long _location;

	static const int InitialSpeed;
};

#endif