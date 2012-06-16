#ifndef FISH_FACTORY_H
#define FISH_FACTORY_H

enum FishType;
class FishImpl;

class FishFactory {
public:
	static FishImpl* create(FishType fishType);

private:
	FishFactory();
};

#endif