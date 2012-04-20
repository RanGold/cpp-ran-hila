#include "Restaurant.h"

Restaurant::Restaurant() {
	_custArray = new CustomerArray();
}

Restaurant::~Restaurant() {
	delete _custArray;
}

int Restaurant::addCustomer(Customer & customer){
	return _custArray->addCustomer(customer);
}

void Restaurant::removeCustomer(int & customerId){
	_custArray->removeCustomer(customerId);
}

void Restaurant::removeCustomer(string& name){
	_custArray->removeCustomer(name);
}

const Order & Restaurant::getCustomerOrder(int& customerId){
	return _custArray->getCustomer(customerId).getOrder();
}

const Order & Restaurant::getCustomerOrder(string& name){
	return _custArray->getCustomer(name).getOrder();
}

void Restaurant::updateCustomerOrder(int& customerId, const Order& order){
	_custArray->getCustomer(customerId).setOrder(order);
}

void Restaurant::updateCustomerOrder(string& name, const Order& order){
	_custArray->getCustomer(name).setOrder(order);
}

void Restaurant::printCustomersAndOrders() const{
	_custArray->printArray();
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

		switch(choice) {

		case 0:{
			cout<<"1 Add Customer\n";
			cout<<"2 Remove Customer by ID \n";
			cout<<"3 Remove Customer by Name \n";
			cout<<"4 Update Customer Order by Name\n";
			cout<<"5 Update Customer Order by ID\n";
			cout<<"6 Get Customer Order by Name\n";
			cout<<"7 Get Customer Order by ID\n";
			cout<<"8 Print Customer and Matching Orders\n";
			cout<<"9 Exit \n";
			break;
		}
		case 1: {
			string name;
			cout<<"Enter customer's name: ";
			getline(cin, name);
			Customer * customer = new Customer(name);
			int id = restaurant->addCustomer(*customer);
			cout << "Customer " << name << " was created with id " << id << ".\n";
			break;
		}
		case 2: {
			cout<<"Enter customer's id: ";
			getline(cin, input);
			stringstream myStream(input);
			int id;
			if (!(myStream >> id)){
				cout<<"Error: expected integer.\n";
				continue;
			}
			restaurant->removeCustomer(id);
			cout << "Customer with id " << id << " was deleted.\n";
			break;
		}
		case 3: {
			string name;
			cout<<"Enter customer's name: ";
			getline(cin, name);
			restaurant->removeCustomer(name);
			cout << "Customer with name " << name << " was deleted.\n";
			break;
		}
		case 4:{
			cout<<"Enter customer's id: ";
			getline(cin, input);
			stringstream myStream(input);
			int id;
			if (!(myStream >> id)){
				cout<<"Error: expected integer.\n";
				continue;
			}
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
			Order * order = new Order(&drink, &first, &main, &dessert);
			restaurant->updateCustomerOrder(id, *order);
			cout << "Customer's order was updated.\n";
			break;
		}
		case 5:{
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
			Order * order = new Order(&drink, &first, &main, &dessert);
			restaurant->updateCustomerOrder(name, *order);
			cout << "Customer's order was updated.\n";
			break;
		}
		case 6:{
			cout<<"Enter customer's name: ";
			string name;
			getline(cin, name);
			Order order = restaurant->getCustomerOrder(name);
			cout << "Customer's order is: \n";
			cout << "Drink: " << order.getDrink() << "\n";
			cout << "First course: " << order.getFirst() << "\n";
			cout << "Main course: " << order.getMain() << "\n";
			cout << "Dessert: " << order.getDessert() << "\n";
			break;
		}
		case 7:{
			cout<<"Enter customer's id: ";
			getline(cin, input);
			stringstream myStream(input);
			int id;
			if (!(myStream >> id)){
				cout<<"Error: expected integer.\n";
				continue;
			}
			Order order = restaurant->getCustomerOrder(id);
			cout << "Customer's order is: \n";
			cout << "Drink: " << order.getDrink() << "\n";
			cout << "First course: " << order.getFirst() << "\n";
			cout << "Main course: " << order.getMain() << "\n";
			cout << "Dessert: " << order.getDessert() << "\n";
			break;
		}
		case 8:{
			restaurant->printCustomersAndOrders();
			break;
		}
		case 9:{
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
