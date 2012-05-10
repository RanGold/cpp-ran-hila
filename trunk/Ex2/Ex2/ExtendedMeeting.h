#include <list>
#include "Meeting.h"

class ExtendedMeeting : public Meeting {
	ExtendedMeeting();
	ExtendedMeeting(const float& startTime, const float& endTime, const string& subject, const list <string> participants);
	ExtendedMeeting(const ExtendedMeeting& meeting);
	const ExtendedMeeting& operator=(const ExtendedMeeting& meeting);
	virtual ~ExtendedMeeting();

	const list <string> getParticipants() const;
	const void setParticipants(const list <string> participants);

	virtual bool doesOverlap(const Meeting& meeting) const;
	virtual void print() const;

protected:
	virtual bool isExtended() const;

private:
	list <string> _participants;
}