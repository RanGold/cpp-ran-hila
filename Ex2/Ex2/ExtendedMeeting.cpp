#include "ExtendedMeeting.h"

ExtendedMeeting::ExtendedMeeting() {
}

ExtendedMeeting::ExtendedMeeting(const float& startTime, const float& endTime, const string& subject, const list <string> participants)
	: Meeting(startTime, endTime, subject), _participants(participants) {}

ExtendedMeeting::ExtendedMeeting(const ExtendedMeeting& meeting)
	: Meeting(meeting), _participants(meeting.getParticipants()){}

const ExtendedMeeting& ExtendedMeeting::operator=(const ExtendedMeeting& meeting){
	if (this != &meeting){
		Meeting.operator=(meeting);
		_participants = meeting.getParticipants();
	}

	return *this;
}

ExtendedMeeting::~ExtendedMeeting(){}

const list <string> ExtendedMeeting::getParticipants() const {
	return _participants;
}
const void ExtendedMeeting::setParticipants(const list <string> participants) {
	_participants = participants;
}

bool ExtendedMeeting::doesOverlap(const Meeting& meeting) const {
	if (!this->isExtended()) {
		cout << "Cannot check overlapping between incompatibale meetings types" << endl;
		return true;
	}

	if (!Meeting.doesOverlap(meeting)) {
		return false;
	}
	
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

void ExtendedMeeting::print() const {
	cout << "Start time: "; 
	printTime(this->getStartTime()) ;
	cout << ", End time: ";
	printTime(this->getEndTime());
	cout << ", Subject: " << this->getSubject() << ", Participants: " << endl;
	
	list <string>::const_iterator iter;
	for (iter = _participants.begin(); iter != _participants.end( ); iter++) {
		cout << *iter << endl;
	}
}

const bool& Meeting::isExtended() const {
	return true;
}