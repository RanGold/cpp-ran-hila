#include "Observer.h"

enum FishType;
class FishImpl;

class Fish : public Observer{

public:
	Fish(FishType fishType);
	virtual	~Fish();

    virtual void update(const Subject* changedSubject);
	void printStatus() const;

private:
	FishImpl* _fishImpl;
};