#include "Day.h"

class Diary {
public:
	Diary();
	virtual ~Diary();

	virtual bool addMeeting(const WeekDay& weekDay, const float& startTime, const float& endTime, 
		const string& subject, const list <string>& participants);
	bool deleteMeeting(const WeekDay& weekDay, const int& id);
	const Meeting* findMeeting(const WeekDay& weekday, const int& id) const;
	const Meeting* findMeeting(const WeekDay& weekday, const float& startTime) const;
	virtual bool copyMeeting(const WeekDay& weekDay, const float& startTime, const float& endTime, const Meeting& meeting);
	virtual void cleanDiary();
	virtual void print() const;
	virtual void printDay(const WeekDay& weekDay) const;

protected:
	Day* _days[7];
};