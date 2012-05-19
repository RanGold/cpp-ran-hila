#include "tContainer_t.h"
#include <list>
#include <vector>
#include <string>

int main(int argc, char* argv[]) {
	tContainer_t<int, list> l;
	tContainer_t<int, vector> v;

	cout << v.empty() << endl;
	int i = 3;
	v.push_back(i);
	i=5;
	v.push_back(i);
	v.remove(i);
	cout << v[0] << endl;
	try {
		l[0];
	} catch (IndexOutOfBoundsException& e) {
		cout << e.getMessage() << endl;
	}
	int* e = v.find(5);
	cout << v.empty() << endl;
	v.print();
}