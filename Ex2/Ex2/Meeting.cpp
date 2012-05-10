#include "Meeting.h"
#include <math.h>

void Meeting::printTime(const float& time) {
	cout << (int)(floor(time)) << ":" << (int)(floor((time - floor(time)) * 100));
}

float Meeting::epsilon = 0.0001;

Meeting::Meeting(){}

Meeting::Meeting(const float& startTime, const float& endTime, const string& subject) 
	:_subject(subject)
{
	_startTime = startTime;
	_endTime = endTime;
}

Meeting::Meeting(const Meeting& meeting)
	:_subject(meeting.getSubject())
{
	_startTime = meeting.getStartTime();
	_endTime = meeting.getEndTime();
}

const Meeting& Meeting::operator=(const Meeting& meeting){
	if (this != &meeting){
		_startTime = meeting.getStartTime();
		_endTime = meeting.getEndTime();
		_subject = meeting.getSubject();
	}

	return *this;
}

const bool& Meeting::operator==(const Meeting& meeting) {
	float startDelta = _startTime - meeting.getStartTime();
	float endDelta = _endTime - meeting.getEndTime();
	return (abs(startDelta) <= Meeting.epsilon &&
		abs(endDelta) <= Meeting.epsilon &&
		_subject.compare(meeting.getSubject()) == 0);
}

Meeting::~Meeting(){}

const float& Meeting::getStartTime() const{
	return _startTime;
}

const void Meeting::setStartTime(const float& startTime){
	_startTime = startTime;
}

const float& Meeting::getEndTime() const{
	return _endTime;
}

const void Meeting::setEndTime(const float& endTime){
	_endTime = endTime;
}

const string& Meeting::getSubject() const{
	return _subject;
}

void Meeting::setSubject(const string& subject){
	_subject = subject;
}

bool Meeting::doesOverlap(const Meeting& meeting) const{
	return _startTime <= meeting.getStartTime() && _endTime >= meeting.getStartTime() || 
		_startTime < meeting.getEndTime() && _endTime >= meeting.getStartTime();
}

void Meeting::print() const{
	cout << "Start time: " << _startTime << ", End time: " << _endTime << ", Subject: " << _subject << endl;
}

const bool& Meeting::isExtended() const {
	return false;
}