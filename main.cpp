//////////////////////////////////////
//       VIRTUAL PET SIMULATOR      //
//       BETTER NAME PENDING :)     //
//////////////////////////////////////

// Include external libraries and define namespace

#include <iostream>
#include <cstdlib>
#include <string>
#include "game.hpp" // Header file

using namespace std;

// Set constants

#define VPSVERSION "a0.2"
#define VPS "Virtual Pet Simulator"

// Global variables

int credits = 0;
int xp = 0; // will implement xp later
int gems = 0;
string petType;
// I have nooo clue what this 32 means. 32 bits I guess? I was able to get
// 80-character pet names when testing it out, and I don't think anyone would
// make pet names that long, so I stopped testing. The max character count might be
// 256 but I can't be bothered to test.
char petName[32];

// Game

void newGame(void) {
	char verifyChoice[] = " ";
	int petTypeSelected = 0;
	
	while (petTypeSelected == 0) {
		char petTypeOption[] = " ";
		cout << "Please select your pet type. Enter the number before the pet type to select it.\nValid types are:\n1 ) dog\n2 ) cat\n" << endl;
		cout << "pcw > "; // pcw = pet creation wizard
		cin >> petTypeOption;

		if (petTypeOption[0] == '1') {
			petType = "dog";
			cout << "Pet type selected is dog. Is this correct? (y/n) ";
			cin >> verifyChoice;
			if (verifyChoice[0] == 'y') {
				petTypeSelected = 1;
			} else {
				cout << "\n";
			}
		} else if (petTypeOption[0] == '2') {
			petType = "cat";
			cout << "Pet type selected is cat. Is this correct? (y/n) ";
			cin >> verifyChoice;
			if (verifyChoice[0] == 'y') {
				petTypeSelected = 1;
			} else {
				cout << "\n";
			}
		} else {
			cout << "Please select a valid pet type.\n" << endl;
		}
	}

	int petNameSelected = 0;

	while (petNameSelected == 0) {
		char verifyChoice[] = " ";

		cout << "\nPlease select your pet's name (Replace spaces with underscores).\n" << endl;
		cout << "pcw > ";
		cin >> petName;

		cout << "Selected pet name is " << petName << ", is this correct? (y/n) ";
		cin >> verifyChoice;
		if (verifyChoice[0] == 'y') {
			petNameSelected = 1;
		}
	}

	cout << "Pet registered. Information:" << endl;
	cout << "Pet type: " << petType << endl;
	cout << "Pet name: " << petName << endl;
	cout << "Continuing to main game...\n" << endl;
}

void game(void) {
	newGame();

	char action[] = " ";
	int exitGame = 0;

	cout << "Enter in the number or character before the action to do that action. Actions are case-sensitive.\nValid actions are:\n1 ) Walk\n2 ) Statistics\nE ) Return to main menu\n" << endl;
	while (exitGame != 1) {
		cout << "game > ";
		cin >> action;
		
		if (action[0] == '1') {
			int isBoost = walkPet(); // Set isBoost to return value of walkPet
			if (isBoost == 2) {
				cout << "You got a boost!\n" << endl;
			}
			walkPetReward();
		} else if (action[0] == 'E') {
			cout << "Returning to main menu"; // Too many newlines if I add an endl
			exitGame = 1; // Exit while loop and return to main init function
		} else if (action[0] == '2') {
			allStats();
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
			cout << "\nWelcome to " << VPS << " version " << VPSVERSION << endl;
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
