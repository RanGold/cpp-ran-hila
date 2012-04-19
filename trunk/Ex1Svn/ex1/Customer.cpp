#include "Customer.h"

// Constructors/Destructors
Customer::Customer() {
	_id = -1;
	_name = new string();
	_order = new Order();
}

Customer::Customer(const int& id, const string& name) {
	_id = id;
	_name = new string(name);
	_order = new Order();
}

Customer::Customer(const string& name) {
	_id = -1;
	_name = new string(name);
	_order = new Order();
}

Customer::Customer(const Customer& customer) {
	_id = customer.getId();
	_name = new string(customer.getName());
	_order = new Order(customer.getOrder());
}

const Customer& Customer::operator=(const Customer& customer) {
	if (this != &customer) {
		this->setId(customer.getId());
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
const int& Customer::getId() const {
	return _id;
}

void Customer::setId(const int& id) {
	_id = id;
}

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