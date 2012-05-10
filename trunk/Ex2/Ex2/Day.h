#include <list>
#include "Meeting.h"

enum WeekDay {
	Sunday,
	Monday,
	Tuesday,
	Wednesday,
	Thursday,
	Friday,
	Saturday
};

class Day {
public:
	Day();
	Day(const WeekDay& weekDay);
	Day(const Day& day);
	const Day& operator=(const Day& day);
	virtual ~Day();

	const WeekDay& getWeekDay() const;
	const bool& addMeeting(const Meeting& meeting);
	const bool& deleteMeeting(const Meeting& meeting);
	Meeting& findMeeting(const float& startTime) const;

	virtual const void print() const;

private:
	WeekDay _weekDay;
	list <Meeting> _meetings;
}