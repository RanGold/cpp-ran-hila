#include "Customer.h"

// Constructors/Destructors
Customer::Customer() {
	_name.clear();
}

Customer::Customer(const string& name) 
	: _name(name)
{
}

Customer::Customer(const Customer& customer) 
	: _name(customer.getName()), _order(customer.getOrder())
{
}

const Customer& Customer::operator=(const Customer& customer) {
	if (this != &customer) {
		this->setName(customer.getName());
		this->setOrder(customer.getOrder());
	}

	return *this;
}

Customer::~Customer() {
}

// Properties
const string& Customer::getName() const {
	return _name;
}

void Customer::setName(const string& name) {
	_name = name;
}

Order& Customer::getOrder() const {
	return (Order&)_order;
}

void Customer::setOrder(Order& order) {
	_order = order;
}

void Customer::print() const {
	cout << "Name: " << getName() << endl;
	getOrder().print();
}