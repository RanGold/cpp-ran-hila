#include "Order.h"

//members
string* _drink;
string* _first;
string* _main;
string* _dessert;


//Constructors/Destructors
Order::Order(const string * drink, const string * first, const string * main, const string * dessert){
	_drink = (string *) drink;
	_first = (string *) first;
	_main = (string *) main;
	_dessert = (string *) dessert;
}

Order::Order(){}
Order::~Order(){}

/*
Getters
*/
const string* getDrink(){
	return _drink;
}

const string* getFirst(){
	return _first;
}

const string* getMain(){
	return _main;
}

const string* getDessert(){
	return _dessert;
}

void setDrink(string * drink){
	_drink = drink;
}

void setFirst(string * first){
	_first = first;
}

void setMain(string * main){
	_main = main;
}

void setDessert(string * dessert){
	_dessert = dessert;
}