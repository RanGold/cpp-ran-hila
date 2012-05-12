#include "Diary.h"

class ExtendedDiary : public Diary{
public:
	ExtendedDiary();
	ExtendedDiary(const ExtendedDiary& extendedDiary);
	virtual const Diary& operator=(const Diary& diary);
	virtual ~ExtendedDiary();

	virtual bool addMeeting(const WeekDay& weekDay, const float& startTime, const float& endTime, 
		const string& subject, const list<string>& participants);
	virtual bool copyMeeting(const WeekDay& weekDay, const float& startTime, const float& endTime, const Meeting& meeting);
	virtual void print() const;
};