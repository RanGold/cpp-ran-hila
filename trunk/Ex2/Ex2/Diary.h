#include "Day.h"

class Diary {
public:
	Diary();
	virtual ~Diary();

	const bool& addMeeting(const WeekDay& weekDay, const float& startTime, const float& endTime, const string& subject);
	const bool& deleteMeeting(const WeekDay& weekDay, const float& startTime);
	Meeting& findMeeting(const WeekDay& weekday, const float& startTime) const;
	const bool& copyMeeting(const WeekDay& weekDay, const Meeting& meeting);
	virtual void print() const;

protecteds:
	Day _days[7];
}