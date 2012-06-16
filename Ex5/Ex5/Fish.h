#ifndef FISH_H
#define FISH_H

#include <map>
#include "Observer.h"

using namespace std;

enum FishType {GOLD, SALMON};
class FishImpl;
enum Action;

class Fish : public Observer {
public:
	Fish(FishType fishType, Subject* subject = 0);
	virtual	~Fish();

    virtual void update(const Subject* changedSubject, Action action);
	void feed();
	void play();
	void pause();
	void debug();

protected:
	Fish();

private:
	FishImpl* _fishImpl;
	typedef void (Fish::*actionFunction)();
	map<size_t, map<Action, actionFunction>> _actionFunctions;

	Fish(const Fish& fish);
	Fish& operator=(const Fish& fish);
};

#endif