#include "Customer.h"

/*
members
*/
int _id;
string _name;
Order _order;

//Constructors/Destructors
Customer::Customer() {}

Customer::Customer(int id, string name){
	_id = id;
	_name = name;
}

Customer::~Customer() {
	// TODO Auto-generated destructor stub
}

void setOrder(const Order & order){
	_order = order;
}
const Order & getOrder(){
	return _order;
}

int & getId(){
	return _id;
}

string & getName(){
	return _name;
}