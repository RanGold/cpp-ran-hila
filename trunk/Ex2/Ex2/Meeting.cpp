#include "Meeting.h"
#include <math.h>

void Meeting::printTime(const float& time) {
	cout << (int)(floor(time)) << ":" << (int)(floor((time - floor(time)) * 100));
}

float Meeting::epsilon = 0.0001;

Meeting::Meeting(){}

Meeting::Meeting(const float& startTime, const float& endTime, const string& subject) 
	:_startTime(startTime), _endTime(endTime), _subject(subject) {}

Meeting::Meeting(const Meeting& meeting)
	:_id(meeting.getId()), _startTime(meeting.getStartTime()), _endTime(meeting.getEndTime()), _subject(meeting.getSubject()) {}

const Meeting& Meeting::operator=(const Meeting& meeting){
	if (this != &meeting){
		_startTime = meeting.getStartTime();
		_endTime = meeting.getEndTime();
		_subject = meeting.getSubject();
		_id = meeting.getId();
	}

	return *this;
}

const bool& Meeting::operator==(const Meeting& meeting) {
	return (_id == meeting.getId() &&
		compareTimes(_startTime, meeting.getStartTime()) &&
		compareTimes(_endTime, meeting.getEndTime()) &&
		_subject.compare(meeting.getSubject()) == 0);
}

Meeting::~Meeting(){}


const int& Meeting::getId() const{
	return _id;
}

void Meeting::setId(const int& id){
	_id =  id;
}

const float& Meeting::getStartTime() const{
	return _startTime;
}

void Meeting::setStartTime(const float& startTime){
	_startTime = startTime;
}

const float& Meeting::getEndTime() const{
	return _endTime;
}

void Meeting::setEndTime(const float& endTime){
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
	cout << "ID: " << _id << "Start time: " << _startTime << ", End time: " << _endTime << ", Subject: " << _subject << endl;
}

const bool& Meeting::isExtended() const {
	return false;
}