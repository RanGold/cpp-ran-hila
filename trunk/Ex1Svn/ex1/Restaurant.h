#ifndef RESTAURANT_H_
#define RESTAURANT_H_

#include "Customer.h"
#include "CustomerArray.h"
#include <sstream>

class Restaurant {
public:

	Restaurant();
	~Restaurant();
	int addCustomer(Customer& customer);
	void removeCustomer(int& customerId);
	void removeCustomer(string& name);
	const Order & getCustomerOrder(int & customerId);
	const Order & getCustomerOrder(string& name);
	void updateCustomerOrder(int& customerId, const Order & order);
	void updateCustomerOrder(string& name, const Order & order);
	void printCustomersAndOrders() const;

private:
	CustomerArray * _custArray;
};

#endif /* RESTAURANT_H_ */
