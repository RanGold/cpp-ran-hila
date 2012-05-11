#include "ExtendedDiary.h"

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

	while(1) {
		cout << "1. Add appoiments" << endl;
		cout << "2. Remove appoiment" << endl;
		cout << "3. Clean Diary" << endl;
		cout << "4. Find appoiment" << endl;
		cout << "5. Print Diary" << endl;
		cout << "6. Quit" << endl;
		cout << "Enter your choice:" << endl;

		int choise;
		cin >> choise;
		switch (choice) {

		}
	}

	delete diary;

	while(1)  {
		

		
			

		switch (choice)  {
		case 1:		 
			addMeeting (…);	break; 			
		case 2:		
			rmvMeeting(…);	break;
		case 3:
			cleanDiary(…);	break;
		case 4:
			findMeeting(…);  	break;
		case 5:
			printDiary(…);     	break;
		case 6:				break;
		}		
	}



	Restaurant restaurant;
	bool finish = false;
	int choice;
	string input;
	printHelp();

	while(!finish) {	
		cout << "Enter your choice or type 0 for help" << endl;
		getline(cin, input);

		stringstream myStream(input);
		if (!(myStream >> choice)){
			cout<<"Error: invalid selection." << endl;
			continue;
		}
		switch(choice) {

		case 0:{
			printHelp();
			break;
			   }
		case 1: {
			string name;
			cout<<"Enter customer's name: ";
			getline(cin, name);
			restaurant.addCustomer(*(new Customer(name)));
			cout << "Customer " << name << " was created." << endl;
			break;
				}
		case 2: {
			string name;
			cout<<"Enter customer's name: ";
			getline(cin, name);
			if (restaurant.removeCustomer(name)) {
				cout << "Customer with name " << name << " was deleted." << endl;
			}
			break;
				}
		case 3:{
			cout<<"Enter customer's name: ";
			string name;
			getline(cin, name);
			cout<<"You can press enter (leave empty string) if you don't want the specific dish." << endl;
			cout<<"Enter drink:" << endl;
			string drink;
			getline(cin, drink);
			cout<<"Enter first course:" << endl;
			string first;
			getline(cin, first);
			cout<<"Enter main course:" << endl;
			string main;
			getline(cin, main);
			cout<<"Enter dessert:" << endl;
			string dessert;
			getline(cin, dessert);
			Order *order = restaurant.getCustomerOrder(name);
			if (order != NULL) {
				order->setDrink(drink);
				order->setFirst(first);
				order->setMain(main);
				order->setDessert(dessert);
				cout << "Customer's order was updated." << endl;
			}

			break;
			   }
		case 4:{
			cout<<"Enter customer's name: ";
			string name;
			getline(cin, name);
			Order *order = restaurant.getCustomerOrder(name);
			if (order != NULL) {
				order->print();
			}

			break;
			   }
		case 5:{
			restaurant.printCustomersAndOrders();
			break;
			   }
		case 6:{
			cout<<"Program exit." << endl;
			finish = true;
			break;
			   }
		default:{
			cout<<"Invalid choice.\n";
			break;
				}
		}
	}

	return 0;
}