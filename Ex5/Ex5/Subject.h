#ifndef SUBJECT_H
#define SUBJECT_H

#include  <vector>

using namespace std;

class Observer;
enum Action;

class Subject {
public: 
	virtual void attach(const Observer*);
    virtual void detach(const Observer*);
	virtual void clear();
	virtual void notify(Action) const;

protected:
	Subject();
	virtual ~Subject();

private:
    vector<Observer*> _observers; 
};

#endif