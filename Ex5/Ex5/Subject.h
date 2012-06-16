#ifndef SUBJECT_H
#define SUBJECT_H

class Observer;

class Subject{

public: 
	virtual void attach(Observer*) = 0;
    virtual void detach(Observer*) = 0;
};

#endif