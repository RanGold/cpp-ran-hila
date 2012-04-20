#include <string>
#include <iostream>
using namespace std;

enum DishType {
	Drink,
	First,
	Main,
	Dessert
};

class Dish {
public:
	Dish();
	Dish(const Dish& dish);
	Dish(const DishType& dishType, const string& name);
	~Dish();

	const DishType& getDishType() const;
	void setDishType(const DishType& dishType);
	const string& getName() const;
	void setName(const string& name);

	void print() const;

private:
	DishType _dishType;
	string* _name;
};