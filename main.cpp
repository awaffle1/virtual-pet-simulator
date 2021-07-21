//////////////////////////////////////
//       VIRTUAL PET SIMULATOR      //
//       BETTER NAME PENDING :)     //
//////////////////////////////////////

// Include external libraries and define namespace

#include <iostream>
#include <cstdlib>
#include <string>
#include "game.hpp" // Not a external library, but has game actions

using namespace std;

// Set constants

#define VPSVERSION "alpha 0.1"
#define VPS "Virtual Pet Simulator"

// Game

void game(void) {
	char action[] = " ";
	int exitGame = 0;
	int credits = 0;
	int xp = 0; // will implement xp later
	int gems = 0;

	cout << "Enter in the number or character before the action to do that action. Actions are case-sensitive.\nValid actions are:\n1 ) Walk\nE ) Return to main menu\n" << endl;
	while (exitGame != 1) {
		cout << "game > ";
		cin >> action;
		
		if (action[0] == '1') {
			int isBoost = walkPet(); // Set isBoost to return value of walkPet
			if (isBoost == 2) {
				cout << "You got a boost!\n" << endl;
			}

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

		} else if (action[0] == 'E') {
			cout << "Returning to main menu"; // Too many newlines if I add an endl
			exitGame = 1; // Exit while loop and return to main init function
		} else {
			cout << "Unknown command\n" << endl;
		}
	}
}

// Init

int main(void) {
	char menuSelection[] = " ";
	int startGame = 0;
	
	cout << "\n\nWelcome to " << VPS << " version " << VPSVERSION << endl;
	cout << "Please select a choice from the list below:\n1 ) Play\n2 ) Exit" << endl;

	while (startGame != 1) {
		startGame = 0;
		cout << "\nmenu > ";
		cin >> menuSelection;

		if (menuSelection[0] == '1') {
			cout << "Opening game\n" << endl;
			startGame = 1;
			game();
			cout << "\n\nWelcome to " << VPS << " version " << VPSVERSION << endl;
			cout << "Please select a choice from the list below:\n1 ) Play\n2 ) Exit" << endl;
			startGame = 0;
		} else if (menuSelection[0] == '2') {
			return 1;
			break;
		} else {
			cout << "Unknown command" << endl;
		}
	}

	return 1;
}
