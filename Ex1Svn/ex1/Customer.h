#include "Order.h"

class Customer {
public:
	Customer();
	Customer(const int& id, const string& name);
	Customer(const string& name);
	Customer(const Customer& customer);
	const Customer& operator=(const Customer& customer);
	~Customer();
	
	const int& getId() const;
	void setId(const int& id);
	const string& getName() const;
	void setName(const string& name);
	const Order& getOrder() const;
	void setOrder(const Order& order);

private:
	int _id;
	string* _name;
	Order* _order;
};
