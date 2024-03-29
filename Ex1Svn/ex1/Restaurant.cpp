#include "Restaurant.h"

Restaurant::Restaurant() {
}

Restaurant::~Restaurant() {
}

void Restaurant::addCustomer(Customer& customer) {
	_custArray.addCustomer(customer);
}

bool Restaurant::removeCustomer(const string& name) {
	return _custArray.removeCustomer(name);
}

Order* Restaurant::getCustomerOrder(const string& name) const {
	Customer* customer = _custArray.getCustomer(name);
	if (customer != NULL) {
		return &(customer->getOrder());
	}

	return NULL;
}

bool Restaurant::updateCustomerOrder(const string& name, Order& order){
	Customer* customer = _custArray.getCustomer(name);
	if (customer != NULL) {
		customer->setOrder(order);
	}

	return (customer != NULL);
}

void Restaurant::printCustomersAndOrders() const{
	_custArray.print();
}

void printHelp() {
	cout<<"1 Add Customer" << endl;
	cout<<"2 Remove Customer by Name" << endl;
	cout<<"3 Update Customer Order by Name" << endl;
	cout<<"4 Get Customer Order by Name" << endl;
	cout<<"5 Print Customer and Matching Orders" << endl;
	cout<<"6 Exit" << endl;
}

int main(int argc, char* argv[]) {
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