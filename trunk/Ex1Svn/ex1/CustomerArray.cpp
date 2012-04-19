#include "CustomerArray.h"

int CustomerArray::_arrayResize = 8;

CustomerArray::CustomerArray() {
	_customers = new Customer[1];
	_freeId = 1;
	_customersAmount = 0;
	_size = 1;
}

CustomerArray::~CustomerArray() {
	delete[] _customers;
}

int CustomerArray::addCustomer(Customer& customer) {
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

	customer.setId(_freeId++);
	_customers[_customersAmount] = customer;
	_customersAmount++;

	return (customer.getId());
}

void CustomerArray::removeCustomer(const int& id) {
	int i;
	for (i = 0; i < _customersAmount; i++) {
		if (_customers[i].getId() == id) {
			break;
		}
	}

	// Implementing left shift on the array because instructor insisted
	for (int j = i; j < (_customersAmount - 1); j++) {
		_customers[j] = _customers[j + 1];
	}

	_customers[_customersAmount].setId(-1);
	_customersAmount--;
}

Customer& CustomerArray::getCustomer(const int& id) const {
	if (id < 1) {
		// TODO error message
	} else {
		for (int i = 0; i < _customersAmount; i++) {
			if (_customers[i].getId() == id) {
				return (_customers[i]);
			}
		}
	}
}