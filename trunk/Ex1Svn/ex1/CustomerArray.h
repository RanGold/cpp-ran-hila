#include "Customer.h"

class CustomerArray {
public:
	CustomerArray();
	~CustomerArray();

	int addCustomer(Customer& customer);
	void removeCustomer(const int& id);
	Customer& getCustomer(const int& id) const;

private:
	Customer* _customers;
	static int _arrayResize;
	int _customersAmount;
	int _freeId;
	int _size;
};