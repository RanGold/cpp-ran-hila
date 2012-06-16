#include "FishImpl.h"

class GoldFishImpl : public FishImpl {
	friend class FishFactory;

public:
	virtual ~GoldFishImpl(); //TODO maybe hide the dtor also?
	virtual void feed();

protected:
	GoldFishImpl();
	GoldFishImpl(Subject* subject);
	GoldFishImpl(const GoldFishImpl& salmonFish);
	GoldFishImpl& operator=(const GoldFishImpl& salmonFish);
};