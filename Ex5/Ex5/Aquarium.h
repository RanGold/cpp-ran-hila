#ifndef AQUARIUM_H
#define AQUARIUM_H

#include "Subject.h"
#include <list>

using namespace std;

enum Action {FEED, PLAY, PAUSE, DEBUG};

class Aquarium : public Subject {
public:
	static Aquarium& instance();
	
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
	Aquarium& operator=(const Aquarium&);
};

#endif