#include "Diary.h"

Diary::Diary() {
	for (int i = 0; i < 7; i++) {
		_days[i] = new Day((WeekDay)i);
		if (_days[i] == NULL) {
			cout << "Error allocating day" << endl;
			deleteDays(WeekDay(i - 1));
			break;
		}
	}
}

Diary::Diary(const Diary& diary) {
	for (int i = 0; i < 7; i++) {
		_days[i] = new Day(*(diary._days[i]));
		if (_days[i] == NULL) {
			cout << "Error allocating day" << endl;
			deleteDays(WeekDay(i - 1));
			break;
		}
	}
}

const Diary& Diary::operator=(const Diary& diary) {
	if (this != &diary) {
		for (int i = 0; i < 7; i++) {
			*(_days[i]) = *(diary._days[i]);
		}
	}

	return *this;
}

Diary::~Diary() {
	deleteDays(Saturday);
}

bool Diary::addMeeting(WeekDay weekDay, float startTime, float endTime, 
	const string& subject, const list<string>& participants) 
{
	Meeting *meeting;

	if (participants.size() == 0) {
		meeting = new Meeting(startTime, endTime, subject);
	} else {
		meeting = new ExtendedMeeting(startTime, endTime, subject, participants);
	}

	if (meeting == NULL) {
		cout << "Error allocating meeting" << endl;
		return false;
	}

	if (!meeting->isValid()) {
		cout << "Invalid values for new meeting" << endl;
		delete meeting;
		return false;
	}

	return _days[weekDay]->addMeeting(*meeting);
}

bool Diary::deleteMeeting(WeekDay weekDay, int id) {
	return _days[weekDay]->deleteMeeting(id);
}

const Meeting* Diary::findMeeting(WeekDay weekday, int id) const {
	return _days[weekday]->findMeeting(id);
}

const Meeting* Diary::findMeeting(WeekDay weekday, float startTime) const {
	return _days[weekday]->findMeeting(startTime);
}

bool Diary::copyMeeting(WeekDay weekDay, const Meeting& meeting) {
	return copyMeeting(weekDay, meeting.getStartTime(), meeting.getEndTime(), meeting);
}

bool Diary::copyMeeting(WeekDay weekDay, float startTime, float endTime, const Meeting& meeting) {

	Meeting* newMeeting;

	if (meeting.isExtended()) {
		newMeeting = new ExtendedMeeting((ExtendedMeeting&) meeting);
	}
	else {
		newMeeting = new Meeting(meeting);
	}

	if (newMeeting == NULL) {
		cout << "Error allocating meeting" << endl;
		return false;
	}

	newMeeting->setStartTime(startTime);
	newMeeting->setEndTime(endTime);

	if (!meeting.isValid()) {
		cout << "Invalid values for new meeting" << endl;
		delete newMeeting;
		return false;
	}

	return _days[weekDay]->addMeeting(*newMeeting);
}

void Diary::cleanDiary() {
	for (int i = 0; i < 7; i++) {
		_days[i]->cleanDay();
	}
}

void Diary::print() const {
	cout << "Diary: " << endl;
	for (int i = 0; i < 7; i++){
		printDay((WeekDay)i);
		cout << endl;
	}
}

void Diary::printDay(WeekDay weekDay) const {
	_days[weekDay]->print();
}

void Diary::deleteDays(WeekDay weekDay) {
	for (int i = 0; i <= weekDay; i++) {
		delete (_days[i]);
	}
}