#include "ExtendedDiary.h"

ExtendedDiary::ExtendedDiary() {}

ExtendedDiary::ExtendedDiary(const ExtendedDiary& extendedDiary) 
	: Diary(extendedDiary) {}

const Diary& ExtendedDiary::operator=(const Diary& diary) {
	if (this != &diary) {
		Diary::operator=(diary);
	}

	return *this;
}

ExtendedDiary::~ExtendedDiary() {}

bool ExtendedDiary::addMeeting(const WeekDay& weekDay, const float& startTime, const float& endTime, 
	const string& subject, const list<string>& participants) 
{
	if (participants.size() == 0) {
		cout << "Extended diary's meetings must contain participants" << endl;
		return false;
	}

	return Diary::addMeeting(weekDay, startTime, endTime, subject, participants);
}

bool ExtendedDiary::copyMeeting(const WeekDay& weekDay, const float& startTime, const float& endTime, const Meeting& meeting) {
	if (!meeting.isExtended()) {
		cout << "Cannot copy non extended meeting to an extended diary" << endl;
		return false;
	}

	return Diary::copyMeeting(weekDay, startTime, endTime, meeting);
}

void ExtendedDiary::print() const{
	cout << "Extended Diary: " << endl;
	for (int i = 0; i < 7; i++){
		_days[i]->print();
	}
}