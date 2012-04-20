#include "Dish.h"

Dish::Dish() {
	_name = new string();
}

Dish::Dish(const Dish& dish) {
	_dishType = dish.getDishType();
	_name = new string(dish.getName());
}

Dish::Dish(const DishType& dishType, const string& name) {
	_dishType = dishType;
	_name = new string(name);
}

Dish::~Dish() {
	delete _name;
}

const DishType& Dish::getDishType() const {
	return _dishType;
}

void Dish::setDishType(const DishType& dishType) {
	_dishType = dishType;
}

const string& Dish::getName() const {
	return *_name;
}
	
void Dish::setName(const string& name) {
	delete _name;
	_name = new string(name);
}

void Dish::print() const {
	switch (getDishType()) {
	case Drink:
		cout<<"Drink: ";
		break;
	case First:
		cout<<"First course: ";
		break;
	case Main:
		cout<<"Main course: ";
		break;
	case Dessert:
		cout<<"Dessert: ";
		break;
	}

	cout<<getName();
}