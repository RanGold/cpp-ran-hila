#include "FishImpl.h"

class SalmonFish : public FishImpl {
friend class FishFactory;

public:
	virtual void feed(const Subject* subject);

protected:
	SalmonFish();
	SalmonFish(const SalmonFish& salmonFish);
	SalmonFish& operator=(const SalmonFish& salmonFish);
};