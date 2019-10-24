/**
Newcaslte University
Author: Tao Van Duy Anh
Student ID: 190332316
Version: 0.1.4
*/
#include "Utility.h"

using namespace std;

int main() {
	Utility utility;
	utility.set_manual_config();	// Manual configuration part
	utility.set_pseudo_configs();	// Pseudo-random configuration(s) part

	// HEAVILY WIP
	cout << "TESTING PHASE" << endl;
	try {
		utility.read_configs_file("Configurations.txt");
	}
	catch (const invalid_argument & iae) {
		cout << "Unable to open file. " << iae.what() << endl;
		// change this part to ask the user to enter the name again
		exit(1);
	}

	int x = 4;
	utility.print_num_cont_blocks_all(x);

	// Pause the console till any key is pressed
	system("pause");

	return 0;
}