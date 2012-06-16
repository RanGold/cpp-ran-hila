#include "GoldFish.h"

GoldFish::GoldFish() {}

string GoldFish::id() const {
	return "Gold Fish";
}

void GoldFish::feed() {
	_speed += 2;
	_size += 1;
}