#include "Day.h"

Day::Day() {
}

Day::Day(const WeekDay& weekDay) {
	_weekDay = weekDay;
}

Day::Day(const Day& day) 
	: _weekDay(day.getWeekDay()), _meetings(day._meetings)
{
}

const Day& Day::operator=(const Day& day) {
	if (this != &day){
		_weekDay = day.getWeekDay();
		_meetings = day._meetings;
	}

	return *this;
}

Day::~Day() {
}

const WeekDay& Day::getWeekDay() const {
	return _weekDay;
}

const bool& Day::addMeeting(const Meeting& meeting) {
	list <Meeting>::const_iterator iter;

	for (iter = _meetings.begin(); iter != _meetings.end( ); iter++) {
		if ((*iter).doesOverlap(meeting)) {
			return false;
		}
	}

	_meetings.push_back(meeting);
	return true;
}

const bool& Day::deleteMeeting(const Meeting& meeting) {
	int startSize = _meetings.size();
	// TODO: check if the operator == for meeting is called and add it also to extended meeting
	_meetings.remove(meeting);

	return (startSize - 1 == _meetings.size());
}

// TODO : change to pointer back to indicate not found meeting
Meeting& Day::findMeeting(const float& startTime) const {
	list <Meeting>::const_iterator iter;
	for (iter = _meetings.begin(); iter != _meetings.end( ); iter++) {
		if (Meeting.compareTimes((*iter).getStartTime(), startTime)) {
			return (*iter);
		}
	}
}

const void Day::print() const {
	// TODO : case on days to print right day

	list <Meeting>::const_iterator iter;
	for (iter = _meetings.begin(); iter != _meetings.end( ); iter++) {
		(*iter).print();
	}
}