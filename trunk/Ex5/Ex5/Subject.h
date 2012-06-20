#ifndef SUBJECT_H
#define SUBJECT_H

#include  <vector>

using namespace std;

class Observer;

class Subject {
public: 
	virtual void attach(const Observer*);
    virtual void detach(const Observer*);
	virtual void clear();
	virtual void notify(int) const;

protected:
	Subject();
	virtual ~Subject();

private:
    vector<Observer*> _observers;

	Subject(const Subject&);
	Subject& operator=(const Subject&);
};

#endif