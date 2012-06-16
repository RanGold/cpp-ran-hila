#include "Observer.h"

enum FishType;
class FishImpl;

class Fish : public Observer {
public:
	Fish(FishType fishType);
	virtual	~Fish();

    virtual void update(const Subject* changedSubject, Action action);

private:
	FishImpl* _fishImpl;
};