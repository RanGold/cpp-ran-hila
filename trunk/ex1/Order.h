/*
* Order.h
*
*  Created on: Apr 8, 2012
*      Author: hila_barzilai
*/

#ifndef ORDER_H_
#define ORDER_H_

#include <string> 
using namespace std;
class Order {
public:
	Order::Order(const string* drink, const string* first, const string* main, const string* dessert);
	Order::Order();
	~Order();

	const string * getDrink();
	const string * getFirst();
	const string * getMain();
	const string * getDessert();

	void setDrink(string * drink);
	void setFirst(string * first);
	void setMain(string * main);
	void setDessert(string * dessert);

};

#endif /* ORDER_H_ */
