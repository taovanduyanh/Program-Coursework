/**
Newcaslte University
Author: Tao Van Duy Anh
Student ID: 190332316
Version: 0.0.8
*/
#include "Puzzle.h"

using namespace std;

int main() {
	// Manual configuration part
	{
		cout << "Welcome to 15-puzzle configuration!" << "\n\n";
		Puzzle manual_config;

		// ask user to create the configuration manually
		manual_config.create_manual_config();
	}

	// Pseudo-random configuration(s) part
	{
		srand(time(NULL)); // Prevent the same sequence of randomness among the configurations
		vector<Puzzle> pseudo_configs(get_num_pseudo_configs());
		
		for (Puzzle config : pseudo_configs) {
			config.create_pseudo_random_config();
		}
	}

	return 0;
}
