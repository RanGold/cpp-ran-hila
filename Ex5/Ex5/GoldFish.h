#ifndef GOLD_FISH_H
#define GOLD_FISH_H

#include "FishImpl.h"

class GoldFish : public FishImpl {
friend class FishFactory;

public:
	virtual string id() const;
	virtual void feed();

protected:
	GoldFish();

private:
	GoldFish(const GoldFish& salmonFish);
	GoldFish& operator=(const GoldFish& salmonFish);
};

#endif