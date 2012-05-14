#include <vector>
#include "ExtendedMeeting.h"

enum WeekDay {
	Sunday = 0,
	Monday = 1,
	Tuesday = 2,
	Wednesday = 3,
	Thursday = 4,
	Friday = 5,
	Saturday = 6
};

class Day {
public:
	Day();
	Day(WeekDay weekDay);
	Day(const Day& day);
	const Day& operator=(const Day& day);
	virtual ~Day();

	WeekDay getWeekDay() const;
	bool addMeeting(Meeting& meeting);
	bool deleteMeeting(int id);
	void cleanDay();
	const Meeting* findMeeting(float startTime) const;
	const Meeting* findMeeting(int id) const;

	virtual const void print() const;

private:
	WeekDay _weekDay;
	vector <Meeting*> _meetings;
	int _meetingIdCounter;
	
	void copyDayMeetings(const Day& day);
};