#include <iostream>
#include <vector>
#include "Aquarium.h"
#include "Fish.h"

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
			int fishId;
			cout << "Enter fish id" << endl;
			cin >> fishId;
			if (fishId >= 0 && fishId <= fishes.size() - removedFishes.size()) {
				Aquarium::instance().remove(fishes[fishId]);
				removedFishes.push_back(fishes[fishId]);
			} else {
				cout << "Invalid fish id" << endl;
			}
			break;
		case 2:
			for (int i = 0; i < fishes.size(); i++) {
				int j;
				for (j = 0; j < removedFishes.size(); j++) {
					if (fishes[i] == removedFishes[j]) {
						break;
					}
				}

				if (j == removedFishes.size()) {
					cout << "Fish Id: " << i << endl;
					//fishes[i]
				}
			}
		}
	}
}

// TODO check all new for exception
// TODO what to do with "Fish" copy and operator= and default constructor
int main(int argc, char* argv[]) {
	bool quit = false;
	vector<Fish*> fishes;
	vector<Fish*> removedFishes;
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
			if (newFish == 0) {
				quit = true;
			} else {
				fishes.push_back(newFish);
			}

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
			// TODO
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

	vector<Fish*>::iterator iter = fishes.begin();
	for(; iter != fishes.end(); iter++) {
		delete *iter;
	}

	return 0;
}