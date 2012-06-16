#include "GoldFish.h"

GoldFish::GoldFish() {}

void GoldFish::feed(const Subject* subject) {
	_speed += 2;
	_size += 1;
}