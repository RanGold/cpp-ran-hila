#include <iostream>
#include "FishFactory.h"
#include "FishImpl.h"
#include "GoldFish.h"
#include "SalmonFish.h"
#include "Fish.h"
#include "AllocationException.h"

FishImpl* FishFactory::create(FishType fishType) {
	FishImpl* newFish;
	switch(fishType) {
	case GOLD:
		newFish = new GoldFish();
	case SALMON:
		newFish = new SalmonFish();
	}

	if (newFish == 0) {
		cout << "Error allocating new fish" << endl;
		throw AllocationException();
	}

	return newFish;
}

