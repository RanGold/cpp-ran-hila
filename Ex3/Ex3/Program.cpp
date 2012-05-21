#include "tContainer_t.h"
#include "Meeting.h"
#include <list>
#include <vector>
#include <string>

void runRefTestsVector(){
	tContainer_t<Meeting, vector> v;

	Meeting* meeting1 = new Meeting(11.25f, 12.0f, "Subject1");
	Meeting* meeting2 = new Meeting(11.25f, 12.0f, "Subject2");
	Meeting* meeting3 = new Meeting(11.25f, 12.0f, "Subject1");

	cout << endl << "### Test 1 - check empty ###" << endl << endl;
	//check empty
	string emptyString = v.empty() ? "empty" : "not empty";
	cout << "tContainer is " << emptyString<< endl;


	cout << endl << "### Test 2 - check push_back ###" << endl << endl;
	//check push_back
	cout << "Adding meeting1:" << endl;
	v.push_back(*meeting1);
	v.print();
	
	
	cout << endl << "### Test 3 - check remove without delete ###" << endl << endl;
	//check remove without delete
	cout << "Meeting print before delete (expected: subject is Subject1):" << endl;
	meeting1->print();
	v.remove(*meeting1);
	cout << "Meeting print after delete (expected: subject is Subject1):" << endl;
	meeting1->print();
	cout << "Print of the tContainer (expected: empty container):" << endl;
	v.print();
	
	cout << endl << "############################" << endl << endl;
	cout << "Adding 2 meetings to the tContainer:" << endl;
	v.push_back(*meeting1);
	v.push_back(*meeting2);
	v.print();

	
	cout << endl << "### Test 4 - check front ###" << endl << endl;
	//check front
	Meeting& meetingFront = v.front();
	cout << "Print of front meeting (expected: subject is Subject1):" << endl;
	meetingFront.print();
	
	
	cout << endl << "### Test 5 - check back ###" << endl << endl;
	//check back
	Meeting& meetingBack = v.back();
	cout << "Print of back meeting (expected: subject is Subject2):" << endl;
	meetingBack.print();


	cout << endl << "### Test 6 - check size ###" << endl << endl;
	//check size
	int size = v.size();
	cout << "tContainer size is (expected: 2):" << endl;
	cout << size << endl;


	cout << endl << "### Test 7 - check [0] ###" << endl << endl;
	//check front
	Meeting& meetingAt0 = v[0];
	cout << "Print of meeting at place [0] (expected: subject is Subject1):" << endl;
	meetingAt0.print();

	
	cout << endl << "### Test 8 - check [2] (index out of bounds) ###" << endl << endl;
	//check front
	cout << "Print of meeting at place [2] (expected: Index out of bounds):" << endl;
	try{
		Meeting& meetingAt2 = v[2];
	}
	catch (IndexOutOfBoundsException& ex){
		cout << ex.getMessage() << endl;
	}

	
	cout << endl << "### Test 9 - check find ###" << endl << endl;
	//check find
	Meeting* foundMeeting = v.find(*meeting3);
	cout << "foundMeeting is (expected: subject is Subject1):" << endl;
	foundMeeting->print();

	
	cout << endl << "### Test 10 - check clear without delete ###" << endl << endl;
	//check clear without delete
	cout << "Clearing the tContainer." << endl;
	v.clear();
	cout << "tContainer after delete (expected: an empty container):" << endl;
	v.print();
	cout << "Meeting1 print after delete (expected: the meeting should not be deleted so the subject should be Subject1): " << endl;
	meeting1->print();
	cout << "Meeting2 print after delete (expected: the meeting should not be deleted so the subject should be Subject2): " << endl;
	meeting2->print();
}

void runRefTestsList(){
	tContainer_t<Meeting, list> l;

	Meeting* meeting1 = new Meeting(11.25f, 12.0f, "Subject1");
	Meeting* meeting2 = new Meeting(11.25f, 12.0f, "Subject2");
	Meeting* meeting3 = new Meeting(11.25f, 12.0f, "Subject1");

	cout << endl << "### Test 1 - check empty ###" << endl << endl;
	//check empty
	string emptyString = l.empty() ? "empty" : "not empty";
	cout << "tContainer is " << emptyString<< endl;


	cout << endl << "### Test 2 - check push_back ###" << endl << endl;
	//check push_back
	cout << "Adding meeting1:" << endl;
	l.push_back(*meeting1);
	l.print();
	
	
	cout << endl << "### Test 3 - check remove without delete ###" << endl << endl;
	//check remove without delete
	cout << "Meeting print before delete (expected: subject is Subject1):" << endl;
	meeting1->print();
	l.remove(*meeting1);
	cout << "Meeting print after delete (expected: subject is Subject1):" << endl;
	meeting1->print();
	cout << "Print of the tContainer (expected: empty container):" << endl;
	l.print();
	
	cout << endl << "############################" << endl << endl;
	cout << "Adding 2 meetings to the tContainer:" << endl;
	l.push_back(*meeting1);
	l.push_back(*meeting2);
	l.print();

	
	cout << endl << "### Test 4 - check front ###" << endl << endl;
	//check front
	Meeting& meetingFront = l.front();
	cout << "Print of front meeting (expected: subject is Subject1):" << endl;
	meetingFront.print();
	
	
	cout << endl << "### Test 5 - check back ###" << endl << endl;
	//check back
	Meeting& meetingBack = l.back();
	cout << "Print of back meeting (expected: subject is Subject2):" << endl;
	meetingBack.print();


	cout << endl << "### Test 6 - check size ###" << endl << endl;
	//check size
	int size = l.size();
	cout << "tContainer size is (expected: 2):" << endl;
	cout << size << endl;


	cout << endl << "### Test 7 - check [0] ###" << endl << endl;
	//check front
	Meeting& meetingAt0 = l[0];
	cout << "Print of meeting at place [0] (expected: subject is Subject1):" << endl;
	meetingAt0.print();

	
	cout << endl << "### Test 8 - check [2] (index out of bounds) ###" << endl << endl;
	//check front
	cout << "Print of meeting at place [2] (expected: Index out of bounds):" << endl;
	try{
		Meeting& meetingAt2 = l[2];
	}
	catch (IndexOutOfBoundsException& ex){
		cout << ex.getMessage() << endl;
	}

	
	cout << endl << "### Test 9 - check find ###" << endl << endl;
	//check find
	Meeting* foundMeeting = l.find(*meeting3);
	cout << "foundMeeting is (expected: subject is Subject1):" << endl;
	foundMeeting->print();

	
	cout << endl << "### Test 10 - check clear without delete ###" << endl << endl;
	//check clear without delete
	cout << "Clearing the tContainer." << endl;
	l.clear();
	cout << "tContainer after delete (expected: an empty container):" << endl;
	l.print();
	cout << "Meeting1 print after delete (expected: the meeting should not be deleted so the subject should be Subject1): " << endl;
	meeting1->print();
	cout << "Meeting2 print after delete (expected: the meeting should not be deleted so the subject should be Subject2): " << endl;
	meeting2->print();
}
std::ostream& operator<<(std::ostream &strm, const Meeting& meeting) {
	return strm << "Start time: " << meeting.getStartTime() << ", End time: " << meeting.getEndTime() << ", Subject: " << meeting.getSubject();
}

int main(int argc, char* argv[]) {
	
	cout << endl << "@@@@@ Running Reference + Vetor tests @@@@@" << endl;
	runRefTestsVector();
	cout << endl << "@@@@@ Running Reference + List tests @@@@@" << endl;
	runRefTestsList();

	return 0;
}