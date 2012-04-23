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
	Dish(const DishType& dishType);
	Dish(const DishType& dishType, const string& name);
	const Dish& operator=(const Dish& dish);
	~Dish();

	const DishType& getDishType() const;
	void setDishType(const DishType& dishType);
	const string& getName() const;
	void setName(const string& name);

	const bool& isEmpty() const;

	void print() const;

private:
	DishType _dishType;
	string _name;
	bool _isEmpty;
};