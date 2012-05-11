#include <vector>
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
	const bool& addMeeting(Meeting& meeting);
	const bool& deleteMeeting(const Meeting& meeting);
	const Meeting* findMeeting(const float& startTime) const;


	virtual const void print() const;

private:
	WeekDay _weekDay;
	vector <Meeting> _meetings;
	int _meetingIdCounter;
}