#include "Dish.h"

Dish::Dish() {
	_name = new string();
	_isEmpty = true;
}

Dish::Dish(const Dish& dish) {
	_dishType = dish.getDishType();
	_name = new string(dish.getName());
	_isEmpty = dish.getName().length() == 0;
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
	_isEmpty = name.length() == 0;
}

const bool& Dish::isEmpty() const {
	return _isEmpty;
}

void Dish::print() const {
	if (!_isEmpty) {
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

		cout<<getName()<<endl;
	}
}