#include <string>
#include "Order.h"

class Customer {
public:
	Customer();
	Customer(const string& name);
	Customer(const Customer& customer);
	const Customer& operator=(const Customer& customer);
	~Customer();
	
	const string& getName() const;
	void setName(const string& name);
	const Order& getOrder() const;
	void setOrder(const Order& order);

	void Customer::print() const;

private:
	string* _name;
	Order* _order;
};
