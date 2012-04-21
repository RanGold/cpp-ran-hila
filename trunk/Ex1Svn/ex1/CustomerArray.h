#include <string>
#include <iostream>
#include "Customer.h"

class CustomerArray {
public:
	CustomerArray();
	~CustomerArray();

	void addCustomer(const Customer& customer);
	bool removeCustomer(const string& name);
	Customer* getCustomer(const string &name) const;
	void CustomerArray::print() const;

private:
	Customer** _customers;
	static int _arrayResize;
	int _customersAmount;
	int _size;
};