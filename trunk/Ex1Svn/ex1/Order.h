#ifndef ORDER_H_
#define ORDER_H_

#include <string> 
using namespace std;

class Order {
public:
	Order();
	Order(const string* drink, const string* first, const string* main, const string* dessert);
	Order(const Order& order);
	const Order& operator=(const Order& order);
	~Order();

	const string & getDrink() const;
	const string & getFirst() const;
	const string & getMain() const;
	const string & getDessert() const;

	void setDrink(string* drink);
	void setFirst(string* first);
	void setMain(string* main);
	void setDessert(string* dessert);

private:
	string* _drink;
	string* _first;
	string* _main;
	string* _dessert;

	void setDrink(const string& drink);
	void setFirst(const string& first);
	void setMain(const string& main);
	void setDessert(const string& dessert);
};

#endif /* ORDER_H_ */
