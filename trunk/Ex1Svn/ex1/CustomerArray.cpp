#include "CustomerArray.h"

int CustomerArray::_arrayResize = 8;

CustomerArray::CustomerArray() {
	_customers = new Customer[1];
	_customersAmount = 0;
	_size = 1;
}

CustomerArray::~CustomerArray() {
	delete[] _customers;
}

void CustomerArray::addCustomer(const Customer& customer) {
	// Need to resize
	if (_customersAmount == _size) {
		Customer* tmp = _customers;
		_customers = new Customer[_size + _arrayResize];
		for (int i = 0; i < _size; i++) {
			_customers[i] = tmp[i];
		}

		delete[] tmp;
		_size += _arrayResize;
	}

	_customers[_customersAmount] = customer;
	_customersAmount++;
}

bool CustomerArray::removeCustomer(const string& name) {
	int i;
	for (i = 0; i < _customersAmount; i++) {
		if (_customers[i].getName().compare(name) == 0) {
			break;
		}
	}

	// Customer not found
	if (i == _customersAmount) {
		cout<< "Customer " << name << " not found." << endl;
	}
	else {
		// Implementing left shift on the array because instructor insisted
		for (int j = i; j < (_customersAmount - 1); j++) {
			_customers[j] = _customers[j + 1];
		}

		_customersAmount--;
	}

	return !(i == _customersAmount);
}

Customer* CustomerArray::getCustomer(const string& name) const {
	for (int i = 0; i < _customersAmount; i++) {
		if (_customers[i].getName().compare(name) == 0) {
			return _customers + i;
		}
	}

	// Name not found - returning NULL along with an error message
	cout<< "Customer " << name << " not found." << endl;
	return NULL;
}

void CustomerArray::print() const {
	cout<<"Customers and their orders:\n" ;
	for (int i = 0; i < _customersAmount; i++) {
		_customers[i].print();
	}
}