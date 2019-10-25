/**
Newcaslte University
Author: Tao Van Duy Anh
Student ID: 190332316
Version: 0.1.6
*/

#include "Utility.h"

using namespace std;

// Forward declaration
void init();
void ask_continue(bool& is_running);
void select_option(Utility& utility);
void init_option(Utility& utility, const short& option);

enum Option {
	ManualConfig = 1,
	RandomConfgs,
	ReadFile,
};

int main() {
	cout << "Newcastle University\nCourtery of: Tao Van Duy Anh\nStudent ID: 190332316\nVersion: 0.1.6\n\nWelcome! ";

	init();

	return 0;
}

// Initialise the program
void init() {
	Utility utility;
	bool is_running = true;
	
	while (is_running) {
		select_option(utility);
		ask_continue(is_running);
	}

	// Pause the console till any key is pressed
	system("pause");
}

// Ask user if they want to continue
void ask_continue(bool& is_running) {
	char response;
	cout << "Would you like to continue? (y/n) ";
	cin >> response;

	while (!cin || (response != 'y' && response != 'n')) {
		cout << "Invalid input. Please enter either 'y' or 'n'\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> response;
	}

	if (response == 'n')
		is_running = false;

	cout << '\n';
}

// Ask the user to choose one of the available options
void select_option(Utility& utility) {
	cout << "Please choose one of the options below to begin:\n";
	cout << "1. Create configuration manually\n2. Create configuration(s) randomly (pseudo random)\n";
	cout << "3. Read configurations(s) from file\nOption: ";

	short option;
	cin >> option;

	while (!cin || option <= 0 || option > 3) {
		cout << "Invalid input. Please enter a number between 1 to 4\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> option;
	}

	init_option(utility, option);
}

// Initialise the option the user chooses
void init_option(Utility& utility, const short& option) {
	cout << '\n';

	switch (option) {
	case ManualConfig:
		utility.set_manual_config();	// Manual configuration part
		break;
	case RandomConfgs:
		utility.set_pseudo_configs();	// Pseudo-random configuration(s) part
		break;
	case ReadFile:
		try {
			utility.read_file();	// Reading configuration(s) part
		}
		catch (const invalid_argument & iae) {
			cout << "Unable to open file. " << iae.what() << endl;
		}
		break;
	}
}