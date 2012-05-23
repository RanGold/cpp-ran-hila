#include "tContainer_t.h"
#include <list>
#include <vector>
#include <string>

void runRefTestsVector() {
	tContainer_t<string, vector> v;

	string* string1 = new string("String1");
	string* string2 = new string("String2");
	string* string3 = new string("String1");

	cout << endl << "### Test 1 - check empty ###" << endl << endl;
	//check empty
	string emptyString = v.empty() ? "empty" : "not empty";
	cout << "tContainer is " << emptyString<< endl;


	cout << endl << "### Test 2 - check push_back ###" << endl << endl;
	//check push_back
	cout << "Adding string1:" << endl;
	v.push_back(*string1);
	v.print();
	
	
	cout << endl << "### Test 3 - check remove without delete ###" << endl << endl;
	//check remove without delete
	cout << "string print before delete (expected: String1):" << endl;
	cout << *string1 << endl;
	string1 = v.remove(*string1);
	cout << "string print after delete (expected: String1):" << endl;
	cout << *string1 << endl;
	cout << "Size of the tContainer (expected: 0):" << endl;
	cout << "Size: " << v.size() << endl;
	
	cout << endl << "############################" << endl << endl;
	cout << "Adding 2 strings to the tContainer (one valuewise and one pointerwise:" << endl;
	v.push_back(*string1);
	v.push_back(string2);
	v.print();

	
	cout << endl << "### Test 4 - check front ###" << endl << endl;
	//check front
	string& stringFront = v.front();
	cout << "Print of front string (expected: String1):" << endl;
	cout << stringFront << endl;
	
	
	cout << endl << "### Test 5 - check back ###" << endl << endl;
	//check back
	string& stringBack = v.back();
	cout << "Print of back string (expected: String2):" << endl;
	cout << stringBack << endl;


	cout << endl << "### Test 6 - check size ###" << endl << endl;
	//check size
	int size = v.size();
	cout << "tContainer size is (expected: 2):" << endl;
	cout << size << endl;


	cout << endl << "### Test 7 - check [0] ###" << endl << endl;
	//check front
	string& stringAt0 = v[0];
	cout << "Print of string at place [0] (expected: String1):" << endl;
	cout << stringAt0 << endl;

	
	cout << endl << "### Test 8 - check [2] (index out of bounds) ###" << endl << endl;
	//check front
	cout << "Print of string at place [2] (expected: \"tContainer_t::operator[] : index out of range\"):" << endl;
	try{
		string& stringAt2 = v[2];
	}
	catch (const IndexOutOfBoundsException& ex){
		cout << ex.getMessage() << endl;
	}

	
	cout << endl << "### Test 9 - check find ###" << endl << endl;
	//check find
	string* foundString = v.find(*string3);
	cout << "foundString is (expected: String1):" << endl;
	cout << *foundString << endl;
	foundString = v.find("string3");
	cout << "foundString is (expected: not found):" << endl;
	string foundRes = foundString == 0 ? "not found" : "found";
	cout << foundRes << endl;

	
	cout << endl << "### Test 10 - check clear without delete ###" << endl << endl;
	//check clear without delete
	cout << "Clearing the tContainer." << endl;
	v.clear();
	cout << "tContainer after delete (expected: Size 0):" << endl;
	cout << "Size: " << v.size() << endl;
	cout << "String1 print after clear (expected: the string should not be deleted so should be String1): " << endl;
	cout << *string1 << endl;
	cout << "String2 print after clear (expected: the string should not be deleted so should be String2): " << endl;
	cout << *string2 << endl;


	cout << endl << "### Test 11 - check removeAndDelete ###" << endl << endl;
	//check remove and delete
	cout << "Adding Two strings to the tContainer." << endl;
	v.push_back(*string1);
	v.push_back(*string2);
	v.print();
	v.removeAndDelete(*string3);
	cout << "tContainer after remove and delete (expected: Only String2):" << endl;
	v.print();


	cout << endl << "### Test 12 - check clearAndDeleteElements ###" << endl << endl;
	//check clear and delete
	v.clearAndDeleteElements();
	cout << "tContainer after clear and delete (expected: Size: 0):" << endl;
	cout << "Size: " << v.size() << endl;


	delete string3;
}

void runRefTestsList(){
	tContainer_t<string, list> v;

	string* string1 = new string("String1");
	string* string2 = new string("String2");
	string* string3 = new string("String1");

	cout << endl << "### Test 1 - check empty ###" << endl << endl;
	//check empty
	string emptyString = v.empty() ? "empty" : "not empty";
	cout << "tContainer is " << emptyString<< endl;


	cout << endl << "### Test 2 - check push_back ###" << endl << endl;
	//check push_back
	cout << "Adding string1:" << endl;
	v.push_back(*string1);
	v.print();
	
	
	cout << endl << "### Test 3 - check remove without delete ###" << endl << endl;
	//check remove without delete
	cout << "string print before delete (expected: String1):" << endl;
	cout << *string1 << endl;
	string1 = v.remove(*string1);
	cout << "string print after delete (expected: String1):" << endl;
	cout << *string1 << endl;
	cout << "Size of the tContainer (expected: 0):" << endl;
	cout << "Size: " << v.size() << endl;
	
	cout << endl << "############################" << endl << endl;
	cout << "Adding 2 strings to the tContainer (one valuewise and one pointerwise:" << endl;
	v.push_back(*string1);
	v.push_back(string2);
	v.print();

	
	cout << endl << "### Test 4 - check front ###" << endl << endl;
	//check front
	string& stringFront = v.front();
	cout << "Print of front string (expected: String1):" << endl;
	cout << stringFront << endl;
	
	
	cout << endl << "### Test 5 - check back ###" << endl << endl;
	//check back
	string& stringBack = v.back();
	cout << "Print of back string (expected: String2):" << endl;
	cout << stringBack << endl;


	cout << endl << "### Test 6 - check size ###" << endl << endl;
	//check size
	int size = v.size();
	cout << "tContainer size is (expected: 2):" << endl;
	cout << size << endl;


	cout << endl << "### Test 7 - check [0] ###" << endl << endl;
	//check front
	string& stringAt0 = v[0];
	cout << "Print of string at place [0] (expected: String1):" << endl;
	cout << stringAt0 << endl;

	
	cout << endl << "### Test 8 - check [2] (index out of bounds) ###" << endl << endl;
	//check front
	cout << "Print of string at place [2] (expected: \"tContainer_t::operator[] : index out of range\"):" << endl;
	try{
		string& stringAt2 = v[2];
	}
	catch (const IndexOutOfBoundsException& ex){
		cout << ex.getMessage() << endl;
	}

	
	cout << endl << "### Test 9 - check find ###" << endl << endl;
	//check find
	string* foundString = v.find(*string3);
	cout << "foundString is (expected: String1):" << endl;
	cout << *foundString << endl;
	foundString = v.find("string3");
	cout << "foundString is (expected: not found):" << endl;
	string foundRes = foundString == 0 ? "not found" : "found";
	cout << foundRes << endl;

	
	cout << endl << "### Test 10 - check clear without delete ###" << endl << endl;
	//check clear without delete
	cout << "Clearing the tContainer." << endl;
	v.clear();
	cout << "tContainer after delete (expected: Size 0):" << endl;
	cout << "Size: " << v.size() << endl;
	cout << "String1 print after clear (expected: the string should not be deleted so should be String1): " << endl;
	cout << *string1 << endl;
	cout << "String2 print after clear (expected: the string should not be deleted so should be String2): " << endl;
	cout << *string2 << endl;


	cout << endl << "### Test 11 - check removeAndDelete ###" << endl << endl;
	//check remove and delete
	cout << "Adding Two strings to the tContainer." << endl;
	v.push_back(*string1);
	v.push_back(*string2);
	v.print();
	v.removeAndDelete(*string3);
	cout << "tContainer after remove and delete (expected: Only String2):" << endl;
	v.print();


	cout << endl << "### Test 12 - check clearAndDeleteElements ###" << endl << endl;
	//check clear and delete
	v.clearAndDeleteElements();
	cout << "tContainer after clear and delete (expected: Size: 0):" << endl;
	cout << "Size: " << v.size() << endl;


	delete string3;
}

void runPrimTestsVector(){
	tContainer_t<int, vector> v;

	int* int1 = new int(1);
	int* int2 = new int(2);
	int* int3 = new int(1);

	cout << endl << "### Test 1 - check empty ###" << endl << endl;
	//check empty
	string emptyString = v.empty() ? "empty" : "not empty";
	cout << "tContainer is " << emptyString<< endl;


	cout << endl << "### Test 2 - check push_back ###" << endl << endl;
	//check push_back
	cout << "Adding int1:" << endl;
	v.push_back(*int1);
	v.print();
	
	
	cout << endl << "### Test 3 - check remove without delete ###" << endl << endl;
	//check remove without delete
	cout << "int print before delete (expected: 1):" << endl;
	cout << *int1 << endl;
	int1 = v.remove(*int1);
	cout << "int print after delete (expected: 1):" << endl;
	cout << *int1 << endl;
	cout << "Size of the tContainer (expected: 0):" << endl;
	cout << "Size: " << v.size() << endl;
	
	cout << endl << "############################" << endl << endl;
	cout << "Adding 2 ints to the tContainer (one valuewise and one pointerwise:" << endl;
	v.push_back(*int1);
	v.push_back(int2);
	v.print();

	
	cout << endl << "### Test 4 - check front ###" << endl << endl;
	//check front
	int& intFront = v.front();
	cout << "Print of front int (expected: 1):" << endl;
	cout << intFront << endl;
	
	
	cout << endl << "### Test 5 - check back ###" << endl << endl;
	//check back
	int& intBack = v.back();
	cout << "Print of back int (expected: 2):" << endl;
	cout << intBack << endl;


	cout << endl << "### Test 6 - check size ###" << endl << endl;
	//check size
	int size = v.size();
	cout << "tContainer size is (expected: 2):" << endl;
	cout << size << endl;


	cout << endl << "### Test 7 - check [0] ###" << endl << endl;
	//check front
	int& intAt0 = v[0];
	cout << "Print of int at place [0] (expected: 1):" << endl;
	cout << intAt0 << endl;

	
	cout << endl << "### Test 8 - check [2] (index out of bounds) ###" << endl << endl;
	//check front
	cout << "Print of int at place [2] (expected: \"tContainer_t::operator[] : index out of range\"):" << endl;
	try{
		int& intAt2 = v[2];
	}
	catch (const IndexOutOfBoundsException& ex){
		cout << ex.getMessage() << endl;
	}

	
	cout << endl << "### Test 9 - check find ###" << endl << endl;
	//check find
	int* foundInt = v.find(*int3);
	cout << "foundInt is (expected: 1):" << endl;
	cout << *foundInt << endl;
	foundInt = v.find(3);
	cout << "foundInt is (expected: not found):" << endl;
	string foundRes = foundInt == 0 ? "not found" : "found";
	cout << foundRes << endl;
	
	cout << endl << "### Test 10 - check clear without delete ###" << endl << endl;
	//check clear without delete
	cout << "Clearing the tContainer." << endl;
	v.clear();
	cout << "tContainer after delete (expected: Size 0):" << endl;
	cout << "Size: " << v.size() << endl;
	cout << "int1 print after clear (expected: the int should not be deleted so should be 1): " << endl;
	cout << *int1 << endl;
	cout << "int2 print after clear (expected: the int should not be deleted so should be 2): " << endl;
	cout << *int2 << endl;


	cout << endl << "### Test 11 - check removeAndDelete ###" << endl << endl;
	//check remove and delete
	cout << "Adding Two ints to the tContainer." << endl;
	v.push_back(*int1);
	v.push_back(*int2);
	v.print();
	v.removeAndDelete(*int3);
	cout << "tContainer after remove and delete (expected: Only 2):" << endl;
	v.print();


	cout << endl << "### Test 12 - check clearAndDeleteElements ###" << endl << endl;
	//check clear and delete
	v.clearAndDeleteElements();
	cout << "tContainer after clear and delete (expected: Size: 0):" << endl;
	cout << "Size: " << v.size() << endl;


	delete int3;
}

void runPrimTestsList(){
	tContainer_t<int, list> v;

	int* int1 = new int(1);
	int* int2 = new int(2);
	int* int3 = new int(1);

	cout << endl << "### Test 1 - check empty ###" << endl << endl;
	//check empty
	string emptyString = v.empty() ? "empty" : "not empty";
	cout << "tContainer is " << emptyString<< endl;


	cout << endl << "### Test 2 - check push_back ###" << endl << endl;
	//check push_back
	cout << "Adding int1:" << endl;
	v.push_back(*int1);
	v.print();
	
	
	cout << endl << "### Test 3 - check remove without delete ###" << endl << endl;
	//check remove without delete
	cout << "int print before delete (expected: 1):" << endl;
	cout << *int1 << endl;
	int1 = v.remove(*int1);
	cout << "int print after delete (expected: 1):" << endl;
	cout << *int1 << endl;
	cout << "Size of the tContainer (expected: 0):" << endl;
	cout << "Size: " << v.size() << endl;
	
	cout << endl << "############################" << endl << endl;
	cout << "Adding 2 ints to the tContainer (one valuewise and one pointerwise:" << endl;
	v.push_back(*int1);
	v.push_back(int2);
	v.print();

	
	cout << endl << "### Test 4 - check front ###" << endl << endl;
	//check front
	int& intFront = v.front();
	cout << "Print of front int (expected: 1):" << endl;
	cout << intFront << endl;
	
	
	cout << endl << "### Test 5 - check back ###" << endl << endl;
	//check back
	int& intBack = v.back();
	cout << "Print of back int (expected: 2):" << endl;
	cout << intBack << endl;


	cout << endl << "### Test 6 - check size ###" << endl << endl;
	//check size
	int size = v.size();
	cout << "tContainer size is (expected: 2):" << endl;
	cout << size << endl;


	cout << endl << "### Test 7 - check [0] ###" << endl << endl;
	//check front
	int& intAt0 = v[0];
	cout << "Print of int at place [0] (expected: 1):" << endl;
	cout << intAt0 << endl;

	
	cout << endl << "### Test 8 - check [2] (index out of bounds) ###" << endl << endl;
	//check front
	cout << "Print of int at place [2] (expected: \"tContainer_t::operator[] : index out of range\"):" << endl;
	try{
		int& intAt2 = v[2];
	}
	catch (const IndexOutOfBoundsException& ex){
		cout << ex.getMessage() << endl;
	}

	
	cout << endl << "### Test 9 - check find ###" << endl << endl;
	//check find
	int* foundInt = v.find(*int3);
	cout << "foundInt is (expected: 1):" << endl;
	cout << *foundInt << endl;
	foundInt = v.find(3);
	cout << "foundInt is (expected: not found):" << endl;
	string foundRes = foundInt == 0 ? "not found" : "found";
	cout << foundRes << endl;

	
	cout << endl << "### Test 10 - check clear without delete ###" << endl << endl;
	//check clear without delete
	cout << "Clearing the tContainer." << endl;
	v.clear();
	cout << "tContainer after delete (expected: Size 0):" << endl;
	cout << "Size: " << v.size() << endl;
	cout << "int1 print after clear (expected: the int should not be deleted so should be 1): " << endl;
	cout << *int1 << endl;
	cout << "int2 print after clear (expected: the int should not be deleted so should be 2): " << endl;
	cout << *int2 << endl;


	cout << endl << "### Test 11 - check removeAndDelete ###" << endl << endl;
	//check remove and delete
	cout << "Adding Two ints to the tContainer." << endl;
	v.push_back(*int1);
	v.push_back(*int2);
	v.print();
	v.removeAndDelete(*int3);
	cout << "tContainer after remove and delete (expected: Only 2):" << endl;
	v.print();


	cout << endl << "### Test 12 - check clearAndDeleteElements ###" << endl << endl;
	//check clear and delete
	v.clearAndDeleteElements();
	cout << "tContainer after clear and delete (expected: Size: 0):" << endl;
	cout << "Size: " << v.size() << endl;


	delete int3;
}

int main(int argc, char* argv[]) {
	string dummy;
	
	cout << endl << "@@@@@ Running Reference + Vector tests @@@@@" << endl;
	cout << "Press enter to continue...";
	getline(cin, dummy);
	runRefTestsVector();
	cout << endl << "@@@@@ Running Reference + List tests @@@@@" << endl;
	cout << "Press enter to continue...";
	getline(cin, dummy);
	runRefTestsList();
	cout << endl << "@@@@@ Running Primitive + Vector tests @@@@@" << endl;
	cout << "Press enter to continue...";
	getline(cin, dummy);
	runPrimTestsVector();
	cout << endl << "@@@@@ Running Primitive + List tests @@@@@" << endl;
	cout << "Press enter to continue...";
	getline(cin, dummy);
	runPrimTestsList();

	cout << "Press enter to continue...";
	getline(cin, dummy);
	return 0;
}