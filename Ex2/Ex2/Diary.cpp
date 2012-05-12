#include "Diary.h"

Diary::Diary() {
	for (int i = 0; i < 7; i++) {
		_days[i] = new Day((WeekDay)i);
	}
}

Diary::~Diary(){
	for (int i = 0; i < 7; i++){
		delete _days[i];
	}
}

bool Diary::addMeeting(const WeekDay& weekDay, const float& startTime, const float& endTime, 
	const string& subject, const list<string>& participants) 
{
	Meeting *meeting;

	if (participants.size() == 0) {
		meeting = new Meeting(startTime, endTime, subject);
	} else {
		meeting = new ExtendedMeeting(startTime, endTime, subject, participants);
	}

	if (!meeting->isValid()) {
		cout << "Invalid values for new meeting" << endl;
		return false;
	}

	return _days[weekDay]->addMeeting(*meeting);
}

bool Diary::deleteMeeting(const WeekDay& weekDay, const int& id) {
	return _days[weekDay]->deleteMeeting(id);
}

const Meeting* Diary::findMeeting(const WeekDay& weekday, const int& id) const {
	return _days[weekday]->findMeeting(id);
}

const Meeting* Diary::findMeeting(const WeekDay& weekday, const float& startTime) const {
	return _days[weekday]->findMeeting(startTime);
}

bool Diary::copyMeeting(const WeekDay& weekDay, const Meeting& meeting) {
	return copyMeeting(weekDay, meeting.getStartTime(), meeting.getEndTime(), meeting);
}

bool Diary::copyMeeting(const WeekDay& weekDay, const float& startTime, const float& endTime, const Meeting& meeting) {

	Meeting* newMeeting;

	if (meeting.isExtended()){
		newMeeting = new ExtendedMeeting((ExtendedMeeting&) meeting);
	}
	else {
		newMeeting = new Meeting(meeting);
	}

	newMeeting->setStartTime(startTime);
	newMeeting->setEndTime(endTime);

	if (!meeting.isValid()) {
		cout << "Invalid values for new meeting" << endl;
		return false;
	}

	bool result = _days[weekDay]->addMeeting(*newMeeting);
	if (!result) {
		delete newMeeting;
	}

	return result;
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

void Diary::printDay(const WeekDay& weekDay) const {
	_days[weekDay]->print();
}