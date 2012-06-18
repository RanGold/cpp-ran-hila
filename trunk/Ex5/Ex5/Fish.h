#ifndef FISH_H
#define FISH_H

#include "Observer.h"

using namespace std;

enum FishType {GOLD, SALMON};
class FishImpl;
enum Action;
class Subject;

class Fish : public Observer {
public:
	Fish(FishType fishType, Subject* subject = 0);
	virtual	~Fish();

	void addToContainer(Subject* subject);
	void removeFromContainer();

    virtual void update(const Subject* changedSubject, Action action);
	void feed();
	void play();
	void pause();
	void debug();

private:
	FishImpl* _fishImpl;

	Fish(const Fish& fish);
	Fish& operator=(const Fish& fish);
};

#endif