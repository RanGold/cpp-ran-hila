#include "Order.h"

//Constructors/Destructors
Order::Order() 
	: _drink(Drink), _first(First), _main(Main), _dessert(Dessert)
{
}

Order::Order(const string& drink, const string& first, const string& main, const string& desert) 
	: _drink(Drink, drink), _first(First, first), _main(Main, main), _dessert(Dessert, desert)
{
}

Order::Order(const Order& order) 
	: _drink(order.getDrink()), _first(order.getFirst()), _main(order.getMain()), _dessert(order.getDessert())
{
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

Order::~Order() {
}

/*
Getters/Setters
*/
const Dish& Order::getDrink() const{
	return _drink;
}

const Dish& Order::getFirst() const{
	return _first;
}

const Dish& Order::getMain() const{
	return _main;
}

const Dish& Order::getDessert() const{
	return _dessert;
}

void Order::setDrink(const string& drink) {
	_drink.setName(drink);
}

void Order::setFirst(const string& first){
	_first.setName(first);
}

void Order::setMain(const string& main){
	_main.setName(main);
}

void Order::setDessert(const string& dessert){
	_dessert.setName(dessert);
}

void Order::print() const {
	cout << "Order:" << endl;
	getDrink().print();
	getFirst().print();
	getMain().print();
	getDessert().print();
}