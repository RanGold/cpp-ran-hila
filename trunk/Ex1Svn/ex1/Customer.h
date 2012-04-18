#ifndef CUSTOMER_H_
#define CUSTOMER_H_

#include "Order.h"

class Customer {
public:
	Customer(int id, string name);
	virtual ~Customer();
	int & getId();
	string & getName();
	const Order & getOrder();
	void setOrder(const Order & order);

private:
	Customer::Customer();
};

#endif /* CUSTOMER_H_ */
