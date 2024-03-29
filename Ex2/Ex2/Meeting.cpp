#include "Meeting.h"
#include <math.h>
#include <iostream>
#include <iomanip>

const float Meeting::epsilon = 0.00001f;

void Meeting::printTime(float time) {
	float impartialHour = time - floor(time);
	int minutes = (int)(floor(impartialHour * 60));
	int seconds = (int)(floor((impartialHour * 60 - minutes) * 60));
	cout << setfill('0') << setw(2) << floor(time) << ":" <<
		setfill('0') << setw(2) << minutes << ":" <<
		setfill('0') << setw(2) << seconds;
}

Meeting::Meeting() {}

Meeting::Meeting(float startTime, float endTime, const string& subject) 
	:_startTime(startTime), _endTime(endTime), _subject(subject) {}

Meeting::Meeting(const Meeting& meeting)
	:_id(meeting.getId()), _startTime(meeting.getStartTime()), _endTime(meeting.getEndTime()), _subject(meeting.getSubject()) {}

const Meeting& Meeting::operator=(const Meeting& meeting) {
	if (this != &meeting) {
		_id = meeting.getId();
		_startTime = meeting.getStartTime();
		_endTime = meeting.getEndTime();
		_subject = meeting.getSubject();
	}

	return *this;
}

Meeting::~Meeting() {}

int Meeting::getId() const {
	return _id;
}

void Meeting::setId(int id) {
	_id =  id;
}

float Meeting::getStartTime() const {
	return _startTime;
}

void Meeting::setStartTime(float startTime) {
	_startTime = startTime;
}

float Meeting::getEndTime() const {
	return _endTime;
}

void Meeting::setEndTime(float endTime) {
	_endTime = endTime;
}

const string& Meeting::getSubject() const {
	return _subject;
}

void Meeting::setSubject(const string& subject) {
	_subject = subject;
}

bool Meeting::doesOverlap(const Meeting& meeting) const {
	return  
		(compareTimes(_startTime, meeting.getStartTime()) || compareTimes(_endTime, meeting.getEndTime())) ||
		(_startTime < meeting.getStartTime() && _endTime > meeting.getStartTime()) || 
		(_startTime < meeting.getEndTime() && _endTime > meeting.getStartTime());
}

void Meeting::print() const {
	printNoNL();
	cout << endl;
}

void Meeting::printNoNL() const {
	cout << "ID: " << _id << ", Start time: ";
	printTime(_startTime);
	cout << ", End time: ";
	printTime(_endTime);
	cout << ", Subject: " << _subject;
}

bool Meeting::isExtended() const {
	return false;
}

bool Meeting::isValid() const {
	return 
		(_startTime > 0 || compareTimes(_startTime, 0)) && 
		(_endTime < 24 || compareTimes(_endTime, 24)) &&
		(_startTime < _endTime || compareTimes(_startTime, _endTime));
}