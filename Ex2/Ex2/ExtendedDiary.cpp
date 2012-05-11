#include "ExtendedDiary.h"

ExtendedDiary::ExtendedDiary(){}

ExtendedDiary::~ExtendedDiary(){}

bool ExtendedDiary::addMeeting(const WeekDay& weekDay, const float& startTime, const float& endTime, 
	const string& subject, const list<string>& participants) 
{
	if (participants.size() == 0) {
		cout << "Extended diary meetings must contain participants" << endl;
		return false;
	}

	return Diary::addMeeting(weekDay, startTime, endTime, subject, participants);
}

bool ExtendedDiary::copyMeeting(const WeekDay& weekDay, const Meeting& meeting) {
	if (!meeting.isExtended()){
		return false;
	}

	ExtendedMeeting& extendedMeeting = (ExtendedMeeting&) meeting;
	ExtendedMeeting& newMeeting = *(new ExtendedMeeting(extendedMeeting));
	return _days[weekDay]->addMeeting(newMeeting);
}

void ExtendedDiary::print() const{
	cout << "Extended Diary: " << endl;
	for (int i = 0; i < 7; i++){
		_days[i]->print();
	}
}