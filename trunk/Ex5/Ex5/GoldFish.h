#include "FishImpl.h"

class GoldFish : public FishImpl {
friend class FishFactory;

public:
	virtual void feed(const Subject* subject);

protected:
	GoldFish();
	GoldFish(const GoldFish& salmonFish);
	GoldFish& operator=(const GoldFish& salmonFish);
};