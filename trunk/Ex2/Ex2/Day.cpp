#include "Day.h"

Day::Day() 
	: _meetingIdCounter(0) {}

Day::Day(const WeekDay& weekDay) 
	: _weekDay(weekDay), _meetingIdCounter(0) {}

Day::Day(const Day& day) 
	: _weekDay(day.getWeekDay()), _meetingIdCounter(0)
{
	for (unsigned int i = 0; i < day._meetings.size(); i++) {
		Meeting* newMeeting = new Meeting(*day._meetings[i]);
		if (newMeeting == NULL) {
			cleanDay();
			break;
		}

		_meetings.push_back(newMeeting);
	}
}

const Day& Day::operator=(const Day& day) {
	if (this != &day){
		_weekDay = day.getWeekDay();
		cleanDay();
		for (unsigned int i = 0; i < day._meetings.size(); i++) {
			Meeting* newMeeting = new Meeting(*day._meetings[i]);
			if (newMeeting == NULL) {
				cleanDay();
				break;
			}

			_meetings.push_back(newMeeting);
		}
	}

	return *this;
}

Day::~Day() {
	cleanDay();
}

const WeekDay& Day::getWeekDay() const {
	return _weekDay;
}

bool Day::addMeeting(Meeting& meeting) {
	vector <Meeting*>::const_iterator iter;

	for (iter = _meetings.begin(); iter != _meetings.end( ); iter++) {
		if ((*iter)->doesOverlap(meeting)) {
			cout << "The meeting overlaps an exisitng meeting" << endl;
			delete &meeting;
			return false;
		}
	}

	meeting.setId(_meetingIdCounter++);
	_meetings.push_back(&meeting);
	return true;
}

bool Day::deleteMeeting(const int& id) {
	vector <Meeting*>::const_iterator iter;
	for (iter = _meetings.begin(); iter != _meetings.end(); iter++) {
		if ((*iter)->getId() == id) {
			break;
		}
	}

	if (iter == _meetings.end()) {
		return false;
	}
	else {
		delete (*iter);
		_meetings.erase(iter);
		return true;
	}
}

void Day::cleanDay() {
	for (unsigned int i = 0 ; i < _meetings.size(); i++) {
		delete _meetings[i];
	}

	_meetings.clear();
}

const Meeting* Day::findMeeting(const float& startTime) const {
	for (unsigned int i = 0; i < _meetings.size(); i++) {
		if (Meeting::compareTimes(_meetings[i]->getStartTime(), startTime)) {
			return _meetings[i];
		}
	}

	return NULL;
}

const Meeting* Day::findMeeting(const int& id) const {
	for (unsigned int i = 0; i < _meetings.size(); i++) {
		if (_meetings[i]->getId() == id) {
			return _meetings[i];
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

	vector <Meeting*>::const_iterator iter;
	for (iter = _meetings.begin(); iter != _meetings.end( ); iter++) {
		(*iter)->print();
	}
}