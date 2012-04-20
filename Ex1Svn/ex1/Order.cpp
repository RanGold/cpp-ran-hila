#include "Order.h"

//Constructors/Destructors
Order::Order(){
	_drink = new string();
	_first = new string();
	_main = new string();
	_dessert = new string();
}

Order::Order(const string * drink, const string * first, const string * main, const string * dessert){
	_drink = (string *) drink;
	_first = (string *) first;
	_main = (string *) main;
	_dessert = (string *) dessert;
}

Order::Order(const Order& order){
	_drink = new string(order.getDrink());
	_first = new string(order.getFirst());
	_main = new string(order.getMain());
	_dessert = new string(order.getDessert());
}

Order::~Order(){
	delete _drink;
	delete _first;
	delete _main;
	delete _dessert;
}

const Order& Order::operator=(const Order& order) {
	if (this != &order) {
		this->setDrink(order.getDrink());
		this->setFirst(order.getFirst());
		this->setMain(order.getMain());
		this->setDessert(order.getDessert());
	}

	return *this;
}
/*
Getters
*/
const string & Order::getDrink() const{
	return *_drink;
}

const string & Order::getFirst() const{
	return *_first;
}

const string & Order::getMain() const{
	return *_main;
}

const string & Order::getDessert() const{
	return *_dessert;
}

void Order::setDrink(string* drink){
	delete _drink;
	_drink = new string(*drink);
}

void Order::setDrink(const string& drink){
	delete _drink;
	_drink = new string(drink);
}

void Order::setFirst(string* first){
	delete _first;
	_first = new string(*first);
}

void Order::setFirst(const string& first){
	delete _first;
	_first = new string(first);
}

void Order::setMain(string* main){
	delete _main;
	_main = new string(*main);
}

void Order::setMain(const string& main){
	delete _main;
	_main = new string(main);
}

void Order::setDessert(string* dessert){
	delete _dessert;
	_dessert = new string(*dessert);
}

void Order::setDessert(const string& dessert){
	delete _main;
	_main = new string(dessert);
}
