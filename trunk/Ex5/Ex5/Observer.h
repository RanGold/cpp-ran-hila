#ifndef OBSERVER_H
#define OBSERVER_H

class Subject;
enum Action;

class Observer {
public:
	virtual ~Observer() {}
    virtual void update(const Subject*, Action) = 0;

protected:
	Subject* _subject;
};

#endif