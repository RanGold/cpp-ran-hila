#include "Day.h"

Day::Day() {
}

Day::Day(const WeekDay& weekDay) 
	: _weekDay(weekDay), _meetingIdCounter(0) {}

Day::Day(const Day& day) 
	: _weekDay(day.getWeekDay()), _meetings(day._meetings) {}

const Day& Day::operator=(const Day& day) {
	if (this != &day){
		_weekDay = day.getWeekDay();
		_meetings = day._meetings;
	}

	return *this;
}

Day::~Day() {
	/*for (int i = 0; i < _meetings.size(); i++ ){
		delete _meetings[i];
	}*/

	//TODO make sure that _meetings (and its meetings) are deleted
}

const WeekDay& Day::getWeekDay() const {
	return _weekDay;
}

bool Day::addMeeting(Meeting& meeting) {
	vector <Meeting>::const_iterator iter;

	for (iter = _meetings.begin(); iter != _meetings.end( ); iter++) {
		if ((*iter).doesOverlap(meeting)) {
			return false;
		}
	}

	meeting.setId(_meetingIdCounter++);
	_meetings.push_back(meeting);
	return true;
}

bool Day::deleteMeeting(const int& id) {
	vector <Meeting>::const_iterator iter;

	for (iter = _meetings.begin(); iter != _meetings.end(); iter++) {
		if (iter->getId() == id) {
			break;
		}
	}

	if (iter == _meetings.end()) {
		return false;
	}
	else {
		_meetings.erase(iter);
		return true;
	}
}

const Meeting* Day::findMeeting(const float& startTime) const {
	for (int i = 0; i < _meetings.size(); i++) {
		if (Meeting::compareTimes(_meetings[i].getStartTime(), startTime)) {
			return &(_meetings[i]);
		}
	}

	return NULL;
}

const void Day::print() const {
	switch (_weekDay) {
	case Sunday:
		cout << "Sunday: " << endl;
		break;
	case Monday:
		cout << "Monday: " << endl;
		break;
	case Tuesday:
		cout << "Tuesday: " << endl;
		break;
	case Wednesday:
		cout << "Wednesday: " << endl;
		break;
	case Thursday:
		cout << "Thursday: " << endl;
		break;
	case Friday:
		cout << "Friday: " << endl;
		break;
	case Saturday:
		cout << "Saturday: " << endl;
		break;
	}

	vector <Meeting>::const_iterator iter;
	for (iter = _meetings.begin(); iter != _meetings.end( ); iter++) {
		(*iter).print();
	}
}