#include "Restaurant.h"

Restaurant::Restaurant() {
	_custArray = new CustomerArray();
}

Restaurant::~Restaurant() {
	delete _custArray;
}

void Restaurant::addCustomer(const Customer& customer) {
	_custArray->addCustomer(customer);
}

void Restaurant::removeCustomer(const string& name) {
	_custArray->removeCustomer(name);
}

const Order& Restaurant::getCustomerOrder(const string& name) const {
	return _custArray->getCustomer(name).getOrder();
}

void Restaurant::updateCustomerOrder(const string& name, const Order& order){
	_custArray->getCustomer(name).setOrder(order);
}

void Restaurant::printCustomersAndOrders() const{
	_custArray->print();
}

int main(int argc, char* argv[]) {

	Restaurant * restaurant =  new Restaurant();
	bool finish = false;
	int choice;
	string input;
	while(!finish) {
		cout<<"Enter your choice or type 0 for help\n";
		getline(cin, input);

		stringstream myStream(input);
		if (!(myStream >> choice)){
			cout<<"Error: invalid selection.\n";
			continue;
		}
		// TODO delete string got by input?
		switch(choice) {

		case 0:{
			cout<<"1 Add Customer\n";
			cout<<"2 Remove Customer by Name \n";
			cout<<"3 Update Customer Order by Name\n";
			cout<<"4 Get Customer Order by Name\n";
			cout<<"5 Print Customer and Matching Orders\n";
			cout<<"6 Exit \n";
			break;
		}
		case 1: {
			string name;
			cout<<"Enter customer's name: ";
			getline(cin, name);
			Customer* customer = new Customer(name);
			restaurant->addCustomer(*customer);
			cout << "Customer " << name << " was created.\n";
			break;
		}
		case 2: {
			string name;
			cout<<"Enter customer's name: ";
			getline(cin, name);
			restaurant->removeCustomer(name);
			cout << "Customer with name " << name << " was deleted.\n";
			break;
		}
		case 3:{
			cout<<"Enter customer's name: ";
			string name;
			getline(cin, name);
			cout<<"Enter drink:\n";
			string drink;
			getline(cin, drink);
			cout<<"Enter first course:\n";
			string first;
			getline(cin, first);
			cout<<"Enter main course:\n";
			string main;
			getline(cin, main);
			cout<<"Enter dessert:\n";
			string dessert;
			getline(cin, dessert);
			Order * order = new Order(drink, first, main, dessert);
			restaurant->updateCustomerOrder(name, *order);
			cout << "Customer's order was updated.\n";
			break;
		}
		case 4:{
			cout<<"Enter customer's name: ";
			string name;
			getline(cin, name);
			Order order = restaurant->getCustomerOrder(name);
			cout << "Customer's order is: \n";
			order.print();
			cout << "\n";
			break;
		}
		case 5:{
			restaurant->printCustomersAndOrders();
			break;
		}
		case 6:{
			cout<<"Program exit.\n";
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