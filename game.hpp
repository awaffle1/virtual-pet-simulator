// VIRTUAL PET SIM

// Import ext. libraries and define namespace

#include <iostream>
#include <cstdlib>

using namespace std;

// ext. variables

extern int credits;
extern int xp;
extern int gems;
extern string petType;
extern char petName[32];

// Game actions

/// Walk your pet

int walkPet(void) {
	int chanceOfBoost = rand() % 10 + 1; // Pick random number between 1 and 10

	cout << "You are walking " << petName << "...\n" << endl;
	// I should probably move the boost to the reward function but the boost doesn't
	// even do anything yet so I don't need to right now, watch as I release this thing
	// and the boost is still useless
	if (chanceOfBoost == 7) {
		return 2;
	} else {
		return 1;
	}
}

void walkPetReward(void) {
	int walkingReward = rand() % 10 + 1; // Pick random number between 1 and 10
	int creditAmount;
	int gemAmount;

	if (walkingReward == 1) {
		cout << "No reward this time :(\n" << endl;
	} else if (walkingReward == 2 || walkingReward == 3) {
		creditAmount = rand() % 101 + 50; // Random number between 50 and 150
		cout << "Recieved " << creditAmount << " credits." << endl;
		credits += creditAmount;
		cout << "You now have " << credits << " credits.\n" << endl;
	} else if (walkingReward == 4 || walkingReward == 5 || walkingReward == 6) {
		gemAmount = rand() % 6 + 0; // Random number between 0 and 5
		creditAmount = rand() % 151 + 150; // Random number between 150 and 300
		if (gemAmount != 0) {
			cout << "Recieved " << gemAmount << " gems." << endl;
			gems += gemAmount;
		}
		cout << "Recieved " << creditAmount << " credits." << endl;
		credits += creditAmount;
		if (gemAmount != 0) {cout << "You now have " << gems << " gems." << endl;}
		cout << "You now have " << credits << " credits.\n" << endl;
	} else if (walkingReward == 7 || walkingReward == 8) {
		gemAmount = rand() % 11 + 0; // Random number between 0 and 10
		creditAmount = rand() % 201 + 250; // Random number between 250 and 450
		if (gemAmount != 0) {
			cout << "Recieved " << gemAmount << " gems." << endl;
			gems += gemAmount;
		}
		cout << "Recieved " << creditAmount << " credits." << endl;
		credits += creditAmount;
		if (gemAmount != 0) {cout << "You now have " << gems << " gems." << endl;}
		cout << "You now have " << credits << " credits.\n" << endl;
	} else if (walkingReward == 9) {
		gemAmount = rand() % 26 + 0; // Random number between 0 and 25
		creditAmount = rand() % 251 + 250; // Random number between 250 and 500
		if (gemAmount != 0) {
			cout << "Recieved " << gemAmount << " gems." << endl;
			gems += gemAmount;
		}
		cout << "Recieved " << creditAmount << " credits." << endl;
		credits += creditAmount;
		if (gemAmount != 0) {cout << "You now have " << gems << " gems." << endl;}
		cout << "You now have " << credits << " credits.\n" << endl;
	} else if (walkingReward == 10) {
		gemAmount = rand() % 43 + 0; // Random number between 0 and 42 (why 42? idk)
		creditAmount = rand() % 51 + 500; // Random number between 500 and 550
		if (gemAmount != 0) {
			cout << "Recieved " << gemAmount << " gems." << endl;
			gems += gemAmount;
		}
		cout << "Recieved " << creditAmount << " credits." << endl;
		credits += creditAmount;
		if (gemAmount != 0) {cout << "You now have " << gems << " gems." << endl;}
		cout << "You now have " << credits << " credits.\n" << endl;
	}
}

/// General statistics

void allStats(void) {
	// Displays current game statistics to the player
	cout << "\n--------( Statistics )--------" << endl;
	cout << "Credits: " << credits << endl;
	cout << "Gems: " << gems << endl;
	cout << "EXP: " << xp << "\n" << endl;
}

/// Pet info

void petInfo(void) {
	// Displays pet information to the player
	cout << "\n--------( " << petName << " )--------" << endl;
	cout << "Type: " << petType << endl;
	cout << "More coming soon" << "\n" << endl;
}