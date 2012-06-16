#include "Observer.h"
#include "Subject.h"

Observer::Observer(Subject* subject) 
	: _subject(subject)
{}

void Observer::setSubject(Subject* subject) {
	if (_subject != 0) {
		_subject->detach(this);
	}

	_subject = subject;
}