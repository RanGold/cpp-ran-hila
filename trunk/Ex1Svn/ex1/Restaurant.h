#include "CustomerArray.h"
#include <iostream>
#include <sstream>

class Restaurant {
public:

	Restaurant();
	~Restaurant();

	void addCustomer(const Customer& customer);
	void removeCustomer(const string& name);
	const Order& getCustomerOrder(const string& name) const;
	void updateCustomerOrder(const string& name, const Order& order);
	void printCustomersAndOrders() const;

private:
	CustomerArray* _custArray;
};
