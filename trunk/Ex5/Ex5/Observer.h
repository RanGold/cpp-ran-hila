#ifndef OBSERVER_H
#define OBSERVER_H

class Subject;

class Observer {

public:
	virtual ~Observer() {}
    virtual void update(const Subject* changedSubject) = 0;

protected:
	Subject* _subject;
};

#endif