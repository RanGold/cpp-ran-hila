#ifndef SALMON_FISH_H
#define SALMON_FISH_H

#include "FishImpl.h"

class SalmonFish : public FishImpl {
friend class FishFactory;

public:
	virtual string id() const;
	virtual void feed();

protected:
	SalmonFish();

private:
	SalmonFish(const SalmonFish& salmonFish);
	SalmonFish& operator=(const SalmonFish& salmonFish);
};

#endif