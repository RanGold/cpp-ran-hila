#include <string> 
using namespace std;

class Order {
public:
	Order();
	Order(const string* drink, const string* first, const string* main, const string* dessert);
	Order(const Order& order);
	const Order& operator=(const Order& order);
	~Order();

	const string * getDrink();
	const string * getFirst();
	const string * getMain();
	const string * getDessert();

	void setDrink(string * drink);
	void setFirst(string * first);
	void setMain(string * main);
	void setDessert(string * dessert);

};
