#include "Puzzle.h"

// Get the number of pseudo-random configurations from user
int get_num_pseudo_configs() {
	int num_configs;

	cout << "Please enter the number of pseudo-random configurations you would like to have" << endl;
	cin >> num_configs;

	while (!cin || num_configs <= 0) {
		cout << "Please enter a positive number (greater than 0)" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> num_configs;
	}

	return num_configs;
}