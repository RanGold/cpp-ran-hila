#ifndef OBSERVER_H
#define OBSERVER_H

class Subject;
enum Action;

class Observer {
public:
	Observer(Subject* subject);
	virtual ~Observer() {}

    virtual void update(const Subject*, Action) = 0;
	void setSubject(Subject* subject);

protected:
	Subject* _subject;
};

#endif