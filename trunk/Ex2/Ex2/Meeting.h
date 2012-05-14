#include <iostream>
#include <string>
using namespace std;

class Meeting {
public:
	Meeting();
	Meeting(float startTime, float endTime, const string& subject);
	Meeting(const Meeting& meeting);
	virtual const Meeting& operator=(const Meeting& meeting);
	virtual ~Meeting();
	
	int getId() const;
	void setId(int id);
	float getStartTime() const;
	void setStartTime(float startTime);
	float getEndTime() const;
	void setEndTime(float endTime);
	const string& getSubject() const;
	void setSubject(const string& subject);
	static bool compareTimes(float t1, float t2) { return (abs(t1 - t2) <= epsilon); }

	virtual bool doesOverlap(const Meeting& meeting) const;
	virtual void print() const;
	virtual bool isExtended() const;
	virtual bool isValid() const;

protected:
	static void printTime(float time);
	const static float epsilon;
	void printNoNL() const;

private:
	int _id;
	float _startTime;
	float _endTime;
	string _subject;
};