#include "Customer.h"
#include <iostream>

class Restaurant {
public:

	Restaurant(); /* create dynamic array (8 cells) */
	virtual ~Restaurant();
	int addCustomer(Customer & customer);
	void setOrderOfCustomer(int & id, Order & order); // TODO ask if we should supply int as ref of pass it by value
	const Order & getClientOrder();

};
