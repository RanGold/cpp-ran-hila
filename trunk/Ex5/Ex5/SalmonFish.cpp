#include "SalmonFish.h"

SalmonFish::SalmonFish() {}

string SalmonFish::id() const {
	return "Salmon Fish";
}

void SalmonFish::feed() {
	_transparency += 1;
	_size += 2;
}