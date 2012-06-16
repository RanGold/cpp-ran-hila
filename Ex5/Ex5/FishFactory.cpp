#include "FishFactory.h"
#include "FishImpl.h"
#include "GoldFishImpl.h"
#include "SalmonFishImpl.h"

FishImpl* FishFactory::create(FishType fishType) {

	switch(fishType) {
	case GOLD:
		return new GoldFishImpl();
	case SALMON:
		return new SalmonFishImpl();
	}

	return 0;
}

FishImpl* FishFactory::create(Subject* subject, FishType fishType){

	switch(fishType){
	case GOLD:
		return new GoldFishImpl(subject);
	case SALMON:
		return new SalmonFishImpl(subject);
	}

	return 0;
}

