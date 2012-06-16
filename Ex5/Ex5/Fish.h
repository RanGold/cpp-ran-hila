#include "Observer.h"

enum FishType;
class FishImpl;

class Fish : public Observer {
public:
	Fish(FishType fishType, Subject* subject = 0);
	virtual	~Fish();

    virtual void update(const Subject* changedSubject, Action action);

private:
	FishImpl* _fishImpl;
};