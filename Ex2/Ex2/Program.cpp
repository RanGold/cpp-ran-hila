#include "ExtendedDiary.h"

WeekDay getWeekDayFromUser() {
	cout << "Enter week day" << endl;
	cout << "1 - Sunady" << endl;
	cout << "2 - Monday" << endl;
	cout << "3 - Tuesday" << endl;
	cout << "4 - Wednesday" << endl;
	cout << "5 - Thursday" << endl;
	cout << "6 - Friday" << endl;
	cout << "7 - Saturday" << endl;
	int weekDayInt;
	cin >> weekDayInt;
	WeekDay weekDay = (WeekDay)(weekDayInt - 1);
}

int getAppointmentIdFromUser(Diary& diary, WeekDay& weekDay) {
	cout << "Enter appointment id or -1 for appointments print for the selected day" << endl;
	int id;
	cin >> id;
	while (id == -1) {
		diary.printDay(weekDay);
		cout << "Enter appointment id or -1 for appointments print for the selected day" << endl;
		cin >> id;
	}

	return id;
}

void addMeeting(Diary& diary) {
	WeekDay weekDay = getWeekDayFromUser();
	cout << "Enter start time" << endl;
	float startTime;
	cin >> startTime;
	cout << "Enter end time" << endl;
	float endTime;
	cin >> endTime;
	cout << "Enter subject" << endl;
	string subject;
	cin >> subject;
	cout << "Enter participant name or \"Done\" when all participants were entered" << endl;
	list <string> participants;
	bool done = false;
	while (!done) {
		string participant;
		cin >> participant;
		if (participant.compare("Done") == 0) {
			break;
		} 
		else {
			participants.push_back(participant);
		}
	}

	if (diary.addMeeting(weekDay, startTime, endTime, subject, participants)) {
		cout << "Meeting added" << endl;
	}
	else {
		cout << "Meeting not added" << endl;
	}
}

void rmvMeeting(Diary& diary) {
	WeekDay weekDay = getWeekDayFromUser();
	int id = getAppointmentIdFromUser(diary, weekDay);

	if (diary.deleteMeeting(weekDay, id)) {
		cout << "Meeting deleted" << endl;
	}
	else {
		cout << "Meeting not deleted" << endl;
	}
}

void cleanDiary(Diary& diary) {
	diary.cleanDiary();
}

void findMeeting(Diary& diary) {
	WeekDay weekDay = getWeekDayFromUser();
	cout << "Enter start time" << endl;
	float startTime;
	cin >> startTime;

	const Meeting* meeting = diary.findMeeting(weekDay, startTime);

	if (meeting == NULL) {
		cout << "Meeting not found" << endl;
	}
	else {
		meeting->print();
	}
}

void copyMeeting(Diary& diary) {
	cout << "Source: ";
	WeekDay srcWeekDay = getWeekDayFromUser();
	int id = getAppointmentIdFromUser(diary, srcWeekDay);

	cout << "Destination: ";
	WeekDay dstWeekDay = getWeekDayFromUser();

	const Meeting* meeting = diary.findMeeting(srcWeekDay, id);
	if (meeting == NULL) {
		cout << "Source meeting not found" << endl;
	}
	else {
		if (diary.copyMeeting(dstWeekDay, *meeting)) {
			cout << "Meeting copied" << endl;
		}
		else {
			cout << "Meeting not copied" << endl;
		}
	}
}

void printDiary(const Diary& diary) {
	diary.print();
}

int main(int argc, char* argv[]) {

	cout << "Select type of diary: 1 - Regular Diary, 2 - Extended Diary" << endl;
	int diaryType;
	Diary* diary;
	cin >> diaryType;
	switch (diaryType) {
	case 2:
		diary = new ExtendedDiary();
		cout << "Extended diary created" << endl;
		break;
	case 1:
	default:
		diary = new Diary();
		cout << "Regular diary created" << endl;
	}

	bool quit = false;
	while(!quit) {
		cout << "1. Add meetings" << endl;
		cout << "2. Remove meeting" << endl;
		cout << "3. Clean Diary" << endl;
		cout << "4. Find meeting" << endl;
		cout << "5. Copy meeting" << endl;
		cout << "6. Print Diary" << endl;
		cout << "7. Quit" << endl;
		cout << "Enter your choice:" << endl;

		int choice;
		cin >> choice;
		switch (choice) {
		case 1:
			addMeeting(*diary);
			break;
		case 2:
			rmvMeeting(*diary);
			break;
		case 3:
			cleanDiary(*diary);
			break;
		case 4:
			findMeeting(*diary);
			break;
		case 5:
			copyMeeting(*diary);
			break;
		case 6:
			printDiary(*diary);
			break;
		case 7:
			quit = true;
			break;
		}
	}

	delete diary;
	return 0;
}