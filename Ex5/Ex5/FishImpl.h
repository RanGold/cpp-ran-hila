#ifndef FISH_IMPL_H
#define FISH_IMPL_H

#include <map>

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
	
	virtual void update(const Subject* changedSubject, Action action);
	virtual void printStatus() const;

	virtual string id() const = 0;
	virtual void feed() = 0;
	void play();
	void pause();
	void debug();

protected:
	int _speed;
	int _size;
	int _transparency;
	long _location;
	bool _isPaused;
	time_t _timeStamp;

private:
	typedef void (FishImpl::*actionFunction)();
	map<size_t, map<Action, actionFunction>> _actionFunctions;
};

#endif