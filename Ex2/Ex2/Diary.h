#include "Day.h"

class Diary {
public:
	Diary();
	Diary(const Diary& diary);
	virtual const Diary& operator=(const Diary& diary);
	virtual ~Diary();

	virtual bool addMeeting(WeekDay weekDay, float startTime, float endTime, 
		const string& subject, const list <string>& participants);
	bool deleteMeeting(WeekDay weekDay, int id);
	const Meeting* findMeeting(WeekDay weekday, int id) const;
	const Meeting* findMeeting(WeekDay weekday, float startTime) const;
	bool copyMeeting(WeekDay weekDay, const Meeting& meeting);
	virtual bool copyMeeting(WeekDay weekDay, float startTime, float endTime, const Meeting& meeting);
	virtual void cleanDiary();
	virtual void print() const;
	virtual void printDay(WeekDay weekDay) const;

protected:
	Day* _days[7];

	virtual void deleteDays(WeekDay weekDay);
};