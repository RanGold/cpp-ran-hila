#include "Diary.h"

Diary::Diary() {
	_days[0] = new Day(Sunday);
	_days[1] = new Day(Monday);
	_days[2] = new Day(Tuesday);
	_days[3] = new Day(Wednesday);
	_days[4] = new Day(Thursday);
	_days[5] = new Day(Friday);
	_days[6] = new Day(Saturday);
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

	return _days[weekDay]->addMeeting(*meeting);
}

bool Diary::deleteMeeting(const WeekDay& weekDay, const int& id) {
	return _days[weekDay]->deleteMeeting(id);
}

const Meeting* Diary::findMeeting(const WeekDay& weekday, const float& startTime) const {
	return _days[weekday]->findMeeting(startTime);

}

bool Diary::copyMeeting(const WeekDay& weekDay, const Meeting& meeting) {
	Meeting& newMeeting = *(new Meeting(meeting));
	return _days[weekDay]->addMeeting(newMeeting);
}

void Diary::print() const {
	cout << "Diary: " << endl;
	for (int i = 0; i < 7; i++){
		_days[i]->print();
	}
}