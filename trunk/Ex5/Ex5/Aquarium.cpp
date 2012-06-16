#include "Aquarium.h"
#include "Observer.h"

//static Aquarium::Aquarium _instance;

Aquarium& Aquarium::instance() { 
	return _instance;
}

void Aquarium::addFish(const Fish* fish) {
	attach(fish);
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

void Aquarium::remove(const Fish* fish) {
	detach(fish);
}

void Aquarium::emptyAquarium() {
	// TODO : delete fishes? make it a part of the factory?
	detachAll();
}

Aquarium::~Aquarium() {
}

Aquarium::Aquarium() {
}