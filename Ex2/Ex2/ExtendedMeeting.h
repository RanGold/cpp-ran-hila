#include <list>
#include "Meeting.h"

class ExtendedMeeting : public Meeting {
public:
	ExtendedMeeting();
	ExtendedMeeting(float startTime, float endTime, const string& subject, const list <string>& participants);
	ExtendedMeeting(const ExtendedMeeting& meeting);
	virtual const Meeting& operator=(const Meeting& meeting);
	virtual ~ExtendedMeeting();

	const list <string>& getParticipants() const;
	void setParticipants(const list <string>& participants);

	virtual bool doesOverlap(const Meeting& meeting) const;
	virtual void print() const;
	virtual bool isExtended() const;
	virtual bool isValid() const;

private:
	list <string> _participants;
};