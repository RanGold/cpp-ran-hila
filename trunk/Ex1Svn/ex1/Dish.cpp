#include "Dish.h"

Dish::Dish() {
	_name.clear();
	_isEmpty = true;
}

Dish::Dish(const Dish& dish) {
	this->setDishType(dish.getDishType());
	this->setName(dish.getName());
}

Dish::Dish(const DishType& dishType) {
	this->setDishType(dishType);
	_name.clear();
	_isEmpty = true;
}

Dish::Dish(const DishType& dishType, const string& name) {
	this->setDishType(dishType);
	this->setName(name);
}

const Dish& Dish::operator=(const Dish& dish) {
	if (this != &dish) {
		this->setDishType(dish.getDishType());
		this->setName(dish.getName());
	}

	return *this;
}

Dish::~Dish() {
}

const DishType& Dish::getDishType() const {
	return _dishType;
}

void Dish::setDishType(const DishType& dishType) {
	_dishType = dishType;
}

const string& Dish::getName() const {
	return _name;
}
	
void Dish::setName(const string& name) {
	_name = name;
	_isEmpty = name.length() == 0;
}

const bool& Dish::isEmpty() const {
	return _isEmpty;
}

void Dish::print() const {
	if (!_isEmpty) {
		switch (getDishType()) {
		case Drink:
			cout << "Drink: ";
			break;
		case First:
			cout << "First course: ";
			break;
		case Main:
			cout << "Main course: ";
			break;
		case Dessert:
			cout << "Dessert: ";
			break;
		}

		cout << getName() << endl;
	}
}