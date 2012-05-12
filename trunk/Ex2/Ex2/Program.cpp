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
	WeekDay weekDay = (WeekDay)(weekDay > 7 || weekDay < Sunday ? 0 : weekDayInt - 1);
	return weekDay;
}

int getAppointmentIdFromUser(const Diary& diary, const WeekDay& weekDay) {
	cout << "Enter appointment id or -1 for the appointments printout for the selected day" << endl;
	int id;
	cin >> id;
	while (id == -1) {
		diary.printDay(weekDay);
		cout << "Enter appointment id or -1 for the appointments printout for the selected day" << endl;
		cin >> id;
	}

	return id;
}

float getTime() {
	while (1) {
		float time;
		cin >> time;
		if (time < 0 || time > 24) {
			cout << "Invalid time enterd, the value must be between 0.0 and 24.0, choose again" << endl;
			continue;
		}

		return time;
	}
}

void addMeeting(Diary& diary) {
	WeekDay weekDay = getWeekDayFromUser();
	cout << "Enter start time as a floating point number" << endl;
	float startTime = getTime();

	cout << "Enter end time as a floating point number" << endl;
	float endTime = getTime();

	cout << "Enter subject" << endl;
	string subject;
	cin.ignore();
	getline(cin, subject);

	cout << "Enter participants name separated by new line or \"Done\" when all participants were entered" << endl;
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

void findMeeting(const Diary& diary) {
	WeekDay weekDay = getWeekDayFromUser();
	cout << "Enter start time as a floating point number" << endl;
	float startTime = getTime();

	const Meeting* meeting = diary.findMeeting(weekDay, startTime);

	if (meeting == NULL) {
		cout << "Meeting not found" << endl;
	}
	else {
		meeting->print();
	}
}

void copyMeeting(Diary& diary) {
	cout << "Source meeting details: ";
	WeekDay srcWeekDay = getWeekDayFromUser();
	int id = getAppointmentIdFromUser(diary, srcWeekDay);
	
	const Meeting* meeting = diary.findMeeting(srcWeekDay, id);
	if (meeting == NULL) {
		cout << "Source meeting not found" << endl;
		return;
	}

	cout << "Do you wish to:" << endl;
	cout << "1. Change time" << endl;
	cout << "2. Change day" << endl;
	cout << "3. Change both" << endl;
	int choice;
	cin >> choice;
	bool result;
	float startTime;
	float endTime;
	WeekDay dstWeekDay;
	switch (choice) {
	case 1:
		cout << "Enter a new start time as a floating point number: " << endl;
		startTime = getTime();
		cout << "Enter a new end time as a floating point number: " << endl;
		endTime = getTime();
		result = diary.copyMeeting(srcWeekDay, startTime, endTime, *meeting);
		break;
	case 2:
		dstWeekDay = getWeekDayFromUser();
		result = diary.copyMeeting(dstWeekDay, *meeting);
		break;
	case 3:
	default:
		cout << "Enter a new start time as a floating point number: " << endl;
		startTime = getTime();
		cout << "Enter a new end time as a floating point number: " << endl;
		endTime = getTime();
		dstWeekDay = getWeekDayFromUser();
		result = diary.copyMeeting(dstWeekDay, startTime, endTime, *meeting);
		break;
	}

	if (result) {
		cout << "Meeting copied" << endl;
	}
	else {
		cout << "Meeting not copied" << endl;
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
		cout << endl << endl;
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
		default:
			break;
		}
	}

	delete diary;
	return 0;
}