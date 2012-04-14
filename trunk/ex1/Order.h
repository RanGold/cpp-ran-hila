/*
 * Order.h
 *
 *  Created on: Apr 8, 2012
 *      Author: hila_barzilai
 */

#ifndef ORDER_H_
#define ORDER_H_

class Order {
public:
	Order(const String * drink, const String * first, const String * main, const String * dessert);
	virtual ~Order();

	const String * getDrink();
	const String * getFirst();
	const String * getMain();
	const String * getDessert();

	void setDrink(String * drink);
	void setFirst(String * first);
	void setMain(String * main);
	void setDessert(String * dessert);
};

#endif /* ORDER_H_ */
