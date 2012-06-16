#include "Subject.h"
#include "Observer.h"

void Subject::attach(const Observer* ob) { 
	_observers.push_back((Observer*)ob); 
} 

void Subject::detach(const Observer* ob) {
	vector<Observer*>::const_iterator iter = _observers.begin();
	for (; iter != _observers.end(); iter++) { 
		if (*iter == ob) {
			break; 
		}
	}
	
	_observers.erase(iter);
}

void Subject::detachAll() {
	_observers.clear();
}

void Subject::notify(Action action) const {
	vector<Observer*>::const_iterator iter = _observers.begin();
	for (; iter != _observers.end(); iter++) {
		(*iter)->update(this, action);
	}
}

Subject::Subject() {
}

Subject::~Subject() {
	detachAll();
}