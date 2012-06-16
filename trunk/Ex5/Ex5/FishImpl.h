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

	virtual void feed(const Subject* subject) = 0;
	void play(const Subject* subject);
	void pause(const Subject* subject);
	void debug(const Subject* subject);

protected:
	int _speed;
	int _size;
	int _transparency;
	int _location;

private:
	typedef void (FishImpl::*actionFunction)(const Subject*);
	map<size_t, map<Action, actionFunction>> _actionFunctions;
};

#endif