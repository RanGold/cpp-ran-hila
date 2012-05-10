#include <iostream>
#include <string>
using namespace std;

class Meeting {
public:
	Meeting();
	Meeting(const float& startTime, const float& endTime, const string& subject);
	Meeting(const Meeting& meeting);
	const Meeting& operator=(const Meeting& meeting);
	virtual ~Meeting();
	
	const float& getStartTime() const;
	const void setStartTime(const float& startTime);
	const float& getEndTime() const;
	const void setEndTime(const float& endTime);
	const string& getSubject() const;
	void setSubject(const string& subject);

	virtual bool doesOverlap(const Meeting& meeting) const;
	virtual void print() const;

protected:
	virtual const bool& isExtended() const;
	static void printTime(const float& time);

private:
	float _startTime;
	float _endTime;
	string _subject;
};
