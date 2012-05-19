#include "tContainer_t.h"
#include <list>
#include <vector>
using namespace std;

int main(int argc, char* argv[]){

	tContainer_t<int, list> l;
	tContainer_t<int, vector> v;

	cout << v.empty();
	int i = 3;
	v.push_back(i);
	i=5;
	v.push_back(i);
	v.remove(i);
	v[0];
	int* e = v.find(5);
	cout << v.empty();
	v.print();
}