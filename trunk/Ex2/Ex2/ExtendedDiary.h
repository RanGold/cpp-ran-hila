#include "Diary.h"

class ExtendedDiary : public Diary{
public:
	ExtendedDiary();
	virtual ~ExtendedDiary();

	virtual bool addMeeting(const WeekDay& weekDay, const float& startTime, const float& endTime, 
		const string& subject, const list<string>& participants);
	virtual bool copyMeeting(const WeekDay& weekDay, const Meeting& meeting);
	virtual void print() const;
};