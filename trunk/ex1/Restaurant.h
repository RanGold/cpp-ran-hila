/*
 * Restaurant.h
 *
 *  Created on: Apr 8, 2012
 *      Author: hila_barzilai
 */

#ifndef RESTAURANT_H_
#define RESTAURANT_H_

class Restaurant {
public:

	Restaurant(); /* create dynamic array (8 cells) */
	virtual ~Restaurant();
	int addCustomer(Cusomer & customer);
	void setOrderOfCustomer(int & id, Order & order); //TODO ask if we should supply int as ref of pass it by value
	const Order & getClientOrder();
};

#endif /* RESTAURANT_H_ */
