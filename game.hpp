// VIRTUAL PET SIM

// Import ext. libraries and define namespace

#include <iostream>
#include <cstdlib>

using namespace std;

// Game actions

/// Walk your pet

int walkPet(void) {
	int chanceOfBoost = rand() % 10 + 1; // Pick random number between 1 and 10

	cout << "You are walking your pet...\n" << endl;
	if (chanceOfBoost == 7) {
		return 2;
	} else {
		return 1;
	}
}