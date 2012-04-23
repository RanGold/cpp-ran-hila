#include <string>
#include "Dish.h"
using namespace std;

class Order {
public:
	Order();
	Order(const string& drink, const string& first, const string& main, const string& dessert);
	Order(const Order& order);
	const Order& operator=(const Order& order);
	~Order();

	const Dish& getDrink() const;
	const Dish& getFirst() const;
	const Dish& getMain() const;
	const Dish& getDessert() const;

	void setDrink(const string& drink);
	void setFirst(const string& first);
	void setMain(const string& main);
	void setDessert(const string& dessert);

	void Order::print() const;

private:
	Dish _drink;
	Dish _first;
	Dish _main;
	Dish _dessert;
};
