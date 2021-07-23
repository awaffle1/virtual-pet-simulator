//////////////////////////////////////
//       VIRTUAL PET SIMULATOR      //
//       BETTER NAME PENDING :)     //
//////////////////////////////////////

// Include external libraries and define namespace

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "game.hpp" // Header file

using namespace std;

// Set constants

#define VPSVERSION "a1.0"
#define VPS "Virtual Pet Simulator"

// Global variables

int credits = 0;
int xp = 0; // will implement xp later
int gems = 0;
string fileName = "save.vpssave"; // .vpssave is virtual pet simulator save
string petType;
// I have nooo clue what this 32 means. 32 bits I guess? I was able to get
// 80-character pet names when testing it out, and I don't think anyone would
// make pet names that long, so I stopped testing. The max character count might be
// 256 but I can't be bothered to test.
char petName[32];

// Save/load

void saveFile(void) {
	{
        // If you're looking to modify your save file (like your pet name or type),
		// use this order to determine how. 
        ofstream fout(fileName);
        fout << credits << '\n' << gems << '\n' << xp << '\n' << petName << "\n" << petType;
    }

	cout << "Saved your game. Bye!\n" << endl;
}

void loadFile(void) {
	{
        ifstream fin(fileName);
        fin >> credits >> gems >> xp >> petName >> petType;
    }

	cout << "Loaded game.\n" << endl;
}

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

void loadOrNew(void) {
	char selection[] = " ";
	int selectedTrue = 0;

	while (selectedTrue == 0) {
		cout << "Please select either to load a game or start a new one. Starting a new game will wipe your existing save file. Select the number before a word to do it.\nOptions are:\n1 ) Start a new save file\n2 ) Load your existing save file\n" << endl;
		cout << "menu > ";
		cin >> selection;

		if (selection[0] == '1') {
			cout << "Starting pcw\n" << endl;
			selectedTrue = 1;
			newGame();
		} else if (selection[0] == '2') {
			cout << "Loading file\n" << endl;
			selectedTrue = 1;
			loadFile();
		} else {
			cout << "Unknown command\n" << endl;
			selectedTrue = 0;
		}
	}
}

void game(void) {
	loadOrNew();

	char action[] = " ";
	int exitGame = 0;

	cout << "Enter in the number or character before the action to do that action. Actions are case-sensitive.\nValid actions are:\n1 ) Walk\n2 ) Statistics\n3 ) Pet Info\nE ) Return to main menu\n" << endl;
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
			saveFile();
			cout << "Returning to main menu" << endl;
			exitGame = 1; // Exit while loop and return to main init function
		} else if (action[0] == '2') {
			allStats();
		} else if (action[0] == '3') {
			petInfo();
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
