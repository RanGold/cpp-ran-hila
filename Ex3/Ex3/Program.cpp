#include "tContainer_t.h"
#include <list>
#include <vector>
#include <string>
#include <assert.h>

template <template <class, class> class Cont>
void runRefTests() {
	tContainer_t<string, Cont> v;

	string* string1 = new string("String1");
	string* string2 = new string("String2");
	string* string3 = new string("String1");
	
	cout << endl << "### Test 1 - check empty ###" << endl << endl;
	// Check empty
	assert(v.empty());

	
	cout << endl << "### Test 2 - check push_back ###" << endl << endl;
	// Check push_back
	cout << "Adding string1:" << endl;
	v.push_back(*string1);
	assert(v.size() == 1);
	assert(v[0].compare("String1") == 0);
	assert(!v.empty());
	
	
	cout << endl << "### Test 3 - check remove without delete ###" << endl << endl;
	// Check remove without delete
	cout << "string print before delete (expected: String1):" << endl;
	assert(string1->compare("String1") == 0);
	string1 = v.remove(*string1);
	cout << "string print after delete (expected: String1):" << endl;
	assert(string1->compare("String1") == 0);
	assert(v.remove("String1") == 0);
	cout << "Size of the tContainer (expected: 0):" << endl;
	assert(v.size() == 0);
	
	
	cout << endl << "############################" << endl << endl;
	cout << "Adding 2 strings to the tContainer (one valuewise and one pointerwise:" << endl;
	v.push_back(*string1);
	v.push_back(string2);
	assert(v.size() == 2);
	v.print();

	
	cout << endl << "### Test 4 - check front ###" << endl << endl;
	// Check front
	string& stringFront = v.front();
	cout << "Print of front string (expected: String1):" << endl;
	assert(stringFront.compare("String1") == 0);
	
	
	cout << endl << "### Test 5 - check back ###" << endl << endl;
	// Check back
	string& stringBack = v.back();
	cout << "Print of back string (expected: String2):" << endl;
	assert(stringBack.compare("String2") == 0);


	cout << endl << "### Test 6 - check size ###" << endl << endl;
	// Check size
	cout << "tContainer size is (expected: 2):" << endl;
	assert(v.size() == 2);


	cout << endl << "### Test 7 - check [0] ###" << endl << endl;
	// Check front
	cout << "Print of string at place [0] (expected: String1):" << endl;
	assert(v[0].compare("String1") == 0);

	
	cout << endl << "### Test 8 - check [2] (index out of bounds) ###" << endl << endl;
	// Check front
	cout << "Print of string at place [2] (expected: \"tContainer_t::operator[] : index out of range\"):" << endl;
	try{
		string& stringAt2 = v[2];
		assert(false);
	}
	catch (const IndexOutOfBoundsException& ex){
		cout << ex.getMessage() << endl;
	}

	
	cout << endl << "### Test 9 - check find ###" << endl << endl;
	// Check find
	string* foundString = v.find(*string3);
	cout << "foundString is (expected: String1):" << endl;
	assert(foundString->compare("String1") == 0);
	foundString = v.find("string3");
	cout << "foundString is (expected: not found):" << endl;
	assert(foundString == 0);

	
	cout << endl << "### Test 10 - check clear without delete ###" << endl << endl;
	// Check clear without delete
	cout << "Clearing the tContainer." << endl;
	v.clear();
	cout << "tContainer after delete (expected: Size 0):" << endl;
	assert(v.size() == 0);
	cout << "String1 print after clear (expected: the string should not be deleted so should be String1): " << endl;
	assert(string1->compare("String1") == 0);
	cout << "String2 print after clear (expected: the string should not be deleted so should be String2): " << endl;
	assert(string2->compare("String2") == 0);


	cout << endl << "### Test 11 - check removeAndDelete ###" << endl << endl;
	// Check remove and delete
	cout << "Adding Two strings to the tContainer." << endl;
	v.push_back(*string1);
	v.push_back(*string2);
	v.print();
	v.removeAndDelete(*string3);
	cout << "tContainer after remove and delete (expected: Only String2):" << endl;
	assert(v[0].compare("String2") == 0);
	assert(v.size() == 1);


	cout << endl << "### Test 12 - check clearAndDeleteElements ###" << endl << endl;
	// Check clear and delete
	v.clearAndDeleteElements();
	cout << "tContainer after clear and delete (expected: Size: 0):" << endl;
	assert(v.size() == 0);


	delete string3;
}

template <template <class, class> class Cont>
void runPrimTests(){
	tContainer_t<int, Cont> v;

	int* int1 = new int(1);
	int* int2 = new int(2);
	int* int3 = new int(1);
	
	cout << endl << "### Test 1 - check empty ###" << endl << endl;
	// Check empty
	assert(v.empty());

	
	cout << endl << "### Test 2 - check push_back ###" << endl << endl;
	// Check push_back
	cout << "Adding int1:" << endl;
	v.push_back(*int1);
	assert(v.size() == 1);
	assert(v[0] == 1);
	assert(!v.empty());
	
	
	cout << endl << "### Test 3 - check remove without delete ###" << endl << endl;
	// Check remove without delete
	cout << "int print before delete (expected: 1):" << endl;
	assert(*int1 == 1);
	int1 = v.remove(*int1);
	cout << "int print after delete (expected: 1):" << endl;
	assert(*int1 == 1);
	assert(v.remove(1) == 0);
	cout << "Size of the tContainer (expected: 0):" << endl;
	assert(v.size() == 0);
	
	
	cout << endl << "############################" << endl << endl;
	cout << "Adding 2 ints to the tContainer (one valuewise and one pointerwise:" << endl;
	v.push_back(*int1);
	v.push_back(int2);
	assert(v.size() == 2);
	v.print();

	
	cout << endl << "### Test 4 - check front ###" << endl << endl;
	// Check front
	int& intFront = v.front();
	cout << "Print of front int (expected: 1):" << endl;
	assert(intFront == 1);
	
	
	cout << endl << "### Test 5 - check back ###" << endl << endl;
	// Check back
	int& intBack = v.back();
	cout << "Print of back int (expected: 2):" << endl;
	assert(intBack == 2);


	cout << endl << "### Test 6 - check size ###" << endl << endl;
	// Check size
	cout << "tContainer size is (expected: 2):" << endl;
	assert(v.size() == 2);


	cout << endl << "### Test 7 - check [0] ###" << endl << endl;
	// Check front
	cout << "Print of int at place [0] (expected: 1):" << endl;
	assert(v[0] == 1);

	
	cout << endl << "### Test 8 - check [2] (index out of bounds) ###" << endl << endl;
	// Check front
	cout << "Print of int at place [2] (expected: \"tContainer_t::operator[] : index out of range\"):" << endl;
	try{
		int& intAt2 = v[2];
		assert(false);
	}
	catch (const IndexOutOfBoundsException& ex){
		cout << ex.getMessage() << endl;
	}

	
	cout << endl << "### Test 9 - check find ###" << endl << endl;
	// Check find
	int* foundInt = v.find(*int3);
	cout << "foundInt is (expected: 1):" << endl;
	assert(*foundInt == 1);
	foundInt = v.find(3);
	cout << "foundInt is (expected: not found):" << endl;
	assert(foundInt == 0);

	
	cout << endl << "### Test 10 - check clear without delete ###" << endl << endl;
	// Check clear without delete
	cout << "Clearing the tContainer." << endl;
	v.clear();
	cout << "tContainer after delete (expected: Size 0):" << endl;
	assert(v.size() == 0);
	cout << "int1 print after clear (expected: the int should not be deleted so should be 1): " << endl;
	assert(*int1 == 1);
	cout << "int2 print after clear (expected: the int should not be deleted so should be 2): " << endl;
	assert(*int2 == 2);


	cout << endl << "### Test 11 - check removeAndDelete ###" << endl << endl;
	// Check remove and delete
	cout << "Adding Two ints to the tContainer." << endl;
	v.push_back(*int1);
	v.push_back(*int2);
	v.print();
	v.removeAndDelete(*int3);
	cout << "tContainer after remove and delete (expected: Only 2):" << endl;
	assert(v[0] == 2);
	assert(v.size() == 1);


	cout << endl << "### Test 12 - check clearAndDeleteElements ###" << endl << endl;
	// Check clear and delete
	v.clearAndDeleteElements();
	cout << "tContainer after clear and delete (expected: Size: 0):" << endl;
	assert(v.size() == 0);


	delete int3;
}

void automatedTest() {
	string dummy;

	cout << endl << "@@@@@ Running Reference + Vector tests @@@@@" << endl;
	cout << "Press enter to continue...";
	getline(cin, dummy);
	runRefTests<vector>();
	cout << endl << "@@@@@ Running Reference + List tests @@@@@" << endl;
	cout << "Press enter to continue...";
	getline(cin, dummy);
	runRefTests<list>();
	cout << endl << "@@@@@ Running Primitive + Vector tests @@@@@" << endl;
	cout << "Press enter to continue...";
	getline(cin, dummy);
	runPrimTests<vector>();
	cout << endl << "@@@@@ Running Primitive + List tests @@@@@" << endl;
	cout << "Press enter to continue...";
	getline(cin, dummy);
	runPrimTests<list>();

	cout << "Press enter to continue...";
	getline(cin, dummy);
}

template <template <class, class> class Cont>
void manualTest() {
	tContainer_t<int, Cont> cont;
	
	bool quit = false;
	while(!quit) {
		cout << endl << endl;
		cout << "1. Check Empty" << endl;
		cout << "2. Get Size" << endl;
		cout << "3. Insert New Val" << endl;
		cout << "4. Get Front Value" << endl;
		cout << "5. Get Back Value" << endl;
		cout << "6. Find Value" << endl;
		cout << "7. Remove Value" << endl;
		cout << "8. Remove And Delete Value" << endl;
		cout << "9. Clear Container" << endl;
		cout << "10. Clear And Delete Values From Container" << endl;
		cout << "11. Get Value By Location" << endl;
		cout << "12. Print" << endl;
		cout << "13. Quit" << endl;
		cout << "Enter your choice:" << endl;

		int choice;
		cin >> choice;
		switch (choice) {
		case 1:
			cout << (cont.empty() ? "Empty" : "Not Empty") << endl;
			break;
		case 2:
			cout << "Size: " << cont.size() << endl;
			break;
		case 3:
			int newVal;
			cout << "Enter new value" << endl;
			cin >> newVal;
			cont.push_back(new int(newVal));
			break;
		case 4:
			if (cont.size() > 0) {
				cout << cont.front() << endl;
			} else {
				cout << "No front value - container is empty" << endl;
			}
			break;
		case 5:
			if (cont.size() > 0) {
				cout << cont.back() << endl;
			} else {
				cout << "No back value - container is empty" << endl;
			}
			break;
		case 6:
			int findVal;
			cout << "Enter value to find" << endl;
			cin >> findVal;
			int *foundVal;
			foundVal = cont.find(findVal);
			if (foundVal == 0) {
				cout << "Value not found" << endl;
			} else {
				cout << "Found value is: " << *foundVal << endl;
			}
			break;
		case 7:
			int removeVal;
			cout << "Enter value to remove" << endl;
			cin >> removeVal;
			int *removedVal;
			removedVal = cont.remove(removeVal);
			if (removedVal == 0) {
				cout << "Value not found" << endl;
			} else {
				cout << "Removed value is: " << *removedVal << endl;
			}
			break;
		case 8:
			int removeAndDeleteVal;
			cout << "Enter value to remove and delete" << endl;
			cin >> removeAndDeleteVal;
			bool removeResult;
			removeResult = cont.removeAndDelete(removeAndDeleteVal);
			if (!removeResult) {
				cout << "Value not found" << endl;
			} else {
				cout << removedVal << " was removed" << endl;
			}
			break;
		case 9:
			cont.clear();
			break;
		case 10:
			cont.clearAndDeleteElements();
			break;
		case 11:
			try {
				int valueLocation;
				cout << "Enter value location" << endl;
				cin >> valueLocation;
				cout << "Value is: " << cont[valueLocation] << endl;
			} catch(IndexOutOfBoundsException exp) {
				cout << exp.getMessage() << endl;
			}
			break;
		case 12:
			cont.print();
			break;
		case 13:
			quit = true;
			break;
		default:
			cout << "Invalid choise" << endl;
			break;
		}
	}
}

int main(int argc, char* argv[]) {
	cout << "Select type of test: 1 - Automated test, 2 - Manual test" << endl;
	int testType;
	cin >> testType;
	switch (testType) {
	case 1:
		automatedTest();
		return 0;
		break;
	case 2:
	default:
		break;
	}

	cout << "Select type of container (the container will hold integers): 1 - vector, 2 - list" << endl;
	int containerType;
	cin >> containerType;
	switch (containerType) {
	case 1:
		manualTest<vector>();
		break;
	case 2:
	default:
		manualTest<list>();
		break;
	}

	return 0;
}