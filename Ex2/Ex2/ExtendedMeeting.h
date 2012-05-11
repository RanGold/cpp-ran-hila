#include <list>
#include "Meeting.h"

class ExtendedMeeting : public Meeting {
public:
	ExtendedMeeting();
	ExtendedMeeting(const float& startTime, const float& endTime, const string& subject, const list <string> participants);
	ExtendedMeeting(const ExtendedMeeting& meeting);
	virtual const Meeting& operator=(const Meeting& meeting);
	virtual const bool& operator==(const Meeting& meeting);
	virtual ~ExtendedMeeting();

	const list <string> getParticipants() const;
	const void setParticipants(const list <string> participants);

	virtual bool doesOverlap(const Meeting& meeting) const;
	virtual void print() const;
	virtual const bool& isExtended() const;

private:
	list <string> _participants;
}