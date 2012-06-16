#include "FishImpl.h"

class SalmonFishImpl : public FishImpl {
	friend class FishFactory;

public:
	virtual ~SalmonFishImpl(); //TODO maybe hide the dtor also?
	virtual void feed();

protected:
	SalmonFishImpl();
	SalmonFishImpl(Subject* subject);
	SalmonFishImpl(const SalmonFishImpl& salmonFish);
	SalmonFishImpl& operator=(const SalmonFishImpl& salmonFish);
};