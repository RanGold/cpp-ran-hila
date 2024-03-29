#include "Aquarium.h"

Aquarium Aquarium::_instance;

Aquarium& Aquarium::instance() { 
	return _instance;
}

void Aquarium::feed() const {
	notify(FEED);
}

void Aquarium::play() const {
	notify(PLAY);
}

void Aquarium::pause() const {
	notify(PAUSE);
}

void Aquarium::debug() const {
	notify(DEBUG);
}

void Aquarium::emptyAquarium() {
	clear();
}

Aquarium::~Aquarium() {}

Aquarium::Aquarium() {}