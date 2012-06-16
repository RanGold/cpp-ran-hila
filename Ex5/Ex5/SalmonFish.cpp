#include "SalmonFish.h"

SalmonFish::SalmonFish() {}

void SalmonFish::feed(const Subject* subject) {
	_transparency += 1;
	_size += 2;
}