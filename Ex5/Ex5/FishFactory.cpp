#include "FishFactory.h"
#include "FishImpl.h"
#include "GoldFish.h"
#include "SalmonFish.h"

FishImpl* FishFactory::create(FishType fishType) {

	switch(fishType) {
	case GOLD:
		return new GoldFish();
	case SALMON:
		return new SalmonFish();
	}

	return 0;
}

