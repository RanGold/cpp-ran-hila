#include "Customer.h"

// Constructors/Destructors
Customer::Customer() {
	_name = new string();
	_order = new Order();
}

Customer::Customer(const string& name) {
	_name = new string(name);
	_order = new Order();
}

Customer::Customer(const Customer& customer) {
	_name = new string(customer.getName());
	_order = new Order(customer.getOrder());
}

const Customer& Customer::operator=(const Customer& customer) {
	if (this != &customer) {
		this->setName(customer.getName());
		this->setOrder(customer.getOrder());
	}

	return *this;
}

Customer::~Customer() {
	delete _name;
	delete _order;
}

// Properties
const string& Customer::getName() const {
	return *_name;
}

void Customer::setName(const string& name) {
	delete _name;
	_name = new string(name);
}

const Order& Customer::getOrder() const {
	return *_order;
}

void Customer::setOrder(const Order& order) {
	delete _order;
	_order = new Order(order);
}

void Customer::print() const {
	cout<<"Name: " << getName() << endl;
	getOrder().print();
}