#include "Order.h"

//Constructors/Destructors
Order::Order(){
	_drink = new Dish(Drink, "");
	_first = new Dish(First, "");
	_main = new Dish(Main, "");
	_dessert = new Dish(Dessert, "");
}

Order::Order(const string& drink, const string& first, const string& main, const string& desert) {
	_drink = new Dish(Drink, drink);
	_first = new Dish(First, first);
	_main = new Dish(Main, main);
	_dessert = new Dish(Dessert, desert);
}

Order::Order(const Order& order){
	_drink = new Dish(order.getDrink());
	_first = new Dish(order.getFirst());
	_main = new Dish(order.getMain());
	_dessert = new Dish(order.getDessert());
}

Order::~Order(){
	delete _drink;
	delete _first;
	delete _main;
	delete _dessert;
}

const Order& Order::operator=(const Order& order) {
	if (this != &order) {
		this->setDrink(order.getDrink().getName());
		this->setFirst(order.getFirst().getName());
		this->setMain(order.getMain().getName());
		this->setDessert(order.getDessert().getName());
	}

	return *this;
}

/*
Getters/Setters
*/
const Dish& Order::getDrink() const{
	return *_drink;
}

const Dish& Order::getFirst() const{
	return *_first;
}

const Dish& Order::getMain() const{
	return *_main;
}

const Dish& Order::getDessert() const{
	return *_dessert;
}

void Order::setDrink(const string& drink) {
	delete _drink;
	_drink = new Dish(Drink, drink);
}

void Order::setFirst(const string& first){
	delete _first;
	_first = new Dish(First, first);
}

void Order::setMain(const string& main){
	delete _main;
	_main = new Dish(Main, main);
}

void Order::setDessert(const string& dessert){
	delete _main;
	_main = new Dish(Dessert, dessert);
}

void Order::print() const {
	cout << "Order:" << endl;
	getDrink().print();
	getFirst().print();
	getMain().print();
	getDessert().print();
}