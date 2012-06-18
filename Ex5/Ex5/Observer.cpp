#include "Observer.h"
#include "Subject.h"

Observer::Observer(Subject* subject) 
	: _subject(subject)
{}