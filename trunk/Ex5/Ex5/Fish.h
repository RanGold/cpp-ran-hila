#ifndef FISH_H
#define FISH_H

#include "Observer.h"

enum FishType {GOLD, SALMON};
class FishImpl;

class Fish : public Observer {
public:
	Fish(FishType fishType, Subject* subject = 0);
	virtual	~Fish();

    virtual void update(const Subject* changedSubject, Action action);

private:
	FishImpl* _fishImpl;
};

#endif