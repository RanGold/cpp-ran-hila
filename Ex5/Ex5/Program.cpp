#include <iostream>
#include <vector>
#include "Aquarium.h"
#include "AllocationException.h"
#include "Fish.h"
#include "UnimplementedHandleException.h"

Fish* addFish() {
	cout << "Enter fish type:" << endl;
	cout << "1. Gold fish" << endl;
	cout << "2. Salmon fish" << endl;
	int fishType;
	cin >> fishType;

	Fish* newFish;
	switch (fishType) {
	case 1:
		newFish = new Fish(GOLD, &Aquarium::instance());
		break;
	case 2:
	default:
		newFish = new Fish(SALMON, &Aquarium::instance());
		break;
	}

	if (newFish == 0) {
		cout << "Error allocating new fish" << endl;
		throw AllocationException();
	}

	return newFish;
}

void removeFish(const vector<Fish*>& fishes, vector<Fish*>& removedFishes) {
	bool cancel = false;
	while (!cancel) {
		cout << "1. Enter fish id for removal from the aquarium" << endl;
		cout << "2. Show fishes within the aquarium" << endl;
		cout << "3. Cancel" << endl;
		int choice;
		cin >> choice;

		switch (choice) {
		case 1:
			unsigned int fishId;
			cout << "Enter fish id" << endl;
			cin >> fishId;
			if (fishId < fishes.size() - removedFishes.size()) {
				Aquarium::instance().remove(fishes[fishId]);
				removedFishes.push_back(fishes[fishId]);
				cancel = true;
			} else {
				cout << "Invalid fish id" << endl;
			}
			break;
		case 2:
			for (unsigned int i = 0; i < fishes.size(); i++) {
				unsigned int j = 0;
				for (; j < removedFishes.size(); j++) {
					if (fishes[i] == removedFishes[j]) {
						break;
					}
				}

				if (j == removedFishes.size()) {
					cout << "Fish Id: " << i << endl;
					fishes[i]->debug();
				}
			}
			break;
		case 3:
			cancel = true;
			break;
		default:
			cout << "invalid choice" << endl;
			break;
		}
	}
}

void addExistingFish(vector<Fish*>& removedFishes) {
	bool cancel = false;
	while (!cancel) {
		cout << "1. Enter fish id for addition to the aquarium" << endl;
		cout << "2. Show fishes outside the aquarium" << endl;
		cout << "3. Cancel" << endl;
		int choice;
		cin >> choice;

		switch (choice) {
		case 1:
			unsigned int fishId;
			cout << "Enter fish id" << endl;
			cin >> fishId;
			if (fishId < removedFishes.size()) {
				Aquarium::instance().addFish(removedFishes[fishId]);
				vector<Fish*>::const_iterator iter;
				iter += fishId;
				removedFishes.erase(iter);
				cancel = true;
			} else {
				cout << "Invalid fish id" << endl;
			}
			break;
		case 2:
			for (unsigned int i = 0; i < removedFishes.size(); i++) {
				cout << "Fish Id: " << i << endl;
				removedFishes[i]->debug();
			}
			break;
		case 3:
			cancel = true;
			break;
		default:
			cout << "invalid choice" << endl;
			break;
		}
	}
}

// TODO check all new for exception
int main(int argc, char* argv[]) {
	bool quit = false;
	vector<Fish*> fishes;
	vector<Fish*> removedFishes;

	try {
		while (!quit) {
			cout << "1. Add fish" << endl;
			cout << "2. Feed fish" << endl;
			cout << "3. Empty Aquarium" << endl;
			cout << "4. Play Aquarium" << endl;
			cout << "5. Pause Aquarium" << endl;
			cout << "6. Debug Aquarium" << endl;
			cout << "7. Remove fish" << endl;
			cout << "8. Add exiting fish" << endl;
			cout << "9. Quit" << endl;
			cout << "Enter your choice:" << endl;

			int choice;
			cin >> choice;
			switch (choice) {
			case 1:
				Fish* newFish;
				newFish = addFish();
				fishes.push_back(newFish);
				break;
			case 2:
				Aquarium::instance().feed();
				break;
			case 3:
				Aquarium::instance().emptyAquarium();
				break;
			case 4:
				Aquarium::instance().play();
				break;
			case 5:
				Aquarium::instance().pause();
				break;
			case 6:
				Aquarium::instance().debug();
				break;
			case 7:
				removeFish(fishes, removedFishes);
				break;
			case 8:
				addExistingFish(removedFishes);
				break;
			case 9:
				quit = true;
				break;
			default:
				cout << "Invalid choice" << endl;
				break;
			}

			cout << endl << endl;
		}
	} catch(const AllocationException& exp) {
		cout << "Error: " << exp.getMessage() << endl;
	} catch(const UnimplementedHandleException& exp) {
		cout << "Error: " << exp.getMessage() << endl;
	}

	vector<Fish*>::iterator iter = fishes.begin();
	for(; iter != fishes.end(); iter++) {
		delete *iter;
	}

	return 0;
}