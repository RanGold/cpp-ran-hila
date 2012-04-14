/*
 * Customer.h
 *
 *  Created on: Apr 8, 2012
 *      Author: hila_barzilai
 */

#ifndef CUSTOMER_H_
#define CUSTOMER_H_

class Customer {
public:
	Customer(int id, Sting name);
	virtual ~Customer();

	void setOrder(const Order & order);
	const Order & getOrder();
	int & getId();
	String & getName();
};

#endif /* CUSTOMER_H_ */
