#include <iostream>

using namespace std;

class IndexOutOfBoundsException {
public:
	IndexOutOfBoundsException(const string& message = "Index out of bounds") : _message(message) {}
	~IndexOutOfBoundsException() {};

	const string& getMessage() const { return _message; }
private:
	string _message;
};