#ifndef CUSTOMERARRAY_H_
#define CUSTOMERARRAY_H_

#include "Customer.h"
#include <iostream>

class CustomerArray {
public:
	CustomerArray();
	~CustomerArray();

	int addCustomer(Customer& customer);
	void removeCustomer(const int& id);
	void removeCustomer(const string& name);
	Customer& getCustomer(const int& id) const;
	Customer& getCustomer(const string & name) const;
	void printArray() const;

private:
	Customer* _customers;
	static int _arrayResize;
	int _customersAmount;
	int _freeId;
	int _size;
};

#endif /* CUSTOMERARRAY_H_ */
