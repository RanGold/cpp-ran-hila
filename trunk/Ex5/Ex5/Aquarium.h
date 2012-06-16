#ifndef AQUARIUM_H
#define AQUARIUM_H

#include "Fish.h"
#include "Subject.h"
#include <list>

using namespace std;

enum Action {FEED, PLAY, PAUSE, DEBUG};

class Aquarium : public Subject {
public:
	static Aquarium& instance();

	void addFish(const Fish* fish);
	void remove(const Fish* fish);
	
	void feed() const;
	void play() const;
	void pause() const;
	void debug() const;
	
	void emptyAquarium();

protected: 
	virtual ~Aquarium();
	static Aquarium _instance; 

private: 
	Aquarium();
	Aquarium(const Aquarium&);
	void operator=(Aquarium&);
};

#endif