#include <iostream>
#include <string>
using namespace std;

class Meeting {
public:
	Meeting();
	Meeting(const float& startTime, const float& endTime, const string& subject);
	Meeting(const Meeting& meeting);
	virtual const Meeting& operator=(const Meeting& meeting);
	virtual ~Meeting();
	
	const int& getId() const;
	void setId(const int& id);
	const float& getStartTime() const;
	void setStartTime(const float& startTime);
	const float& getEndTime() const;
	void setEndTime(const float& endTime);
	const string& getSubject() const;
	void setSubject(const string& subject);
	static bool compareTimes(const float& t1, const float& t2) { return (abs(t1 - t2) <= epsilon); }

	virtual bool doesOverlap(const Meeting& meeting) const;
	virtual void print() const;
	virtual bool isExtended() const;
	virtual bool isValid() const;

protected:
	static void printTime(const float& time);
	const static float epsilon;
	void printNoNL() const;

private:
	int _id;
	float _startTime;
	float _endTime;
	string _subject;
};