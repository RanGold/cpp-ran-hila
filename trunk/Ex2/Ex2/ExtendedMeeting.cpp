#include "ExtendedMeeting.h"

ExtendedMeeting::ExtendedMeeting() {
}

ExtendedMeeting::ExtendedMeeting(const float& startTime, const float& endTime, const string& subject, const list <string>& participants)
	: Meeting(startTime, endTime, subject), _participants(participants) {}

ExtendedMeeting::ExtendedMeeting(const ExtendedMeeting& meeting)
	: Meeting(meeting), _participants(meeting.getParticipants()) {}

const Meeting& ExtendedMeeting::operator=(const Meeting& meeting){
	if (this != &meeting) {
		Meeting::operator=(meeting);
		if (meeting.isExtended()) {
			_participants = ((ExtendedMeeting&)meeting).getParticipants();
		}
	}

	return *this;
}

ExtendedMeeting::~ExtendedMeeting() {}

const list <string> ExtendedMeeting::getParticipants() const {
	return _participants;
}
const void ExtendedMeeting::setParticipants(const list <string> participants) {
	_participants = participants;
}

bool ExtendedMeeting::doesOverlap(const Meeting& meeting) const {
	if (!Meeting::doesOverlap(meeting)) {
		return false;
	}
	
	// For non extended meeting if they overlap in time they are considered overlapping, otherwise we compare the participants
	if (!meeting.isExtended()) {
		return true;
	}
	else {
		// Comparing participants
		// TODO : verify no copy constructor is called (assign)
		const list <string>& otherParticipants = ((ExtendedMeeting*)&meeting)->getParticipants();
		list <string>::const_iterator iter1, iter2;
		for (iter1 = _participants.begin(); iter1 != _participants.end(); iter1++) {
			for (iter2 = otherParticipants.begin(); iter2 != otherParticipants.end(); iter2++) {
				if ((*iter1).compare(*iter2) == 0) {
					return true;
				}
			}
		}

		return false;
	}
}

void ExtendedMeeting::print() const {
	cout << "ID: " << this->getId();
	cout << " Start time: "; 
	printTime(this->getStartTime()) ;
	cout << ", End time: ";
	printTime(this->getEndTime());
	cout << ", Subject: " << this->getSubject() << ", Participants: " << endl;
	
	list <string>::const_iterator iter;
	for (iter = _participants.begin(); iter != _participants.end(); iter++) {
		cout << *iter << endl;
	}
}

bool ExtendedMeeting::isExtended() const {
	return true;
}

bool ExtendedMeeting::isValid() const {
	return 
		Meeting::isValid() &&
		_participants.size() > 0;
}