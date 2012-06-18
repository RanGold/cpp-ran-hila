#include "Observer.h"

Observer::Observer(Subject* subject) 
	: _subject(subject)
{}

void Observer::clearSubject() {
	_subject = 0;
}