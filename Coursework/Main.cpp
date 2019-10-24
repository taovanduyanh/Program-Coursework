/**
Newcaslte University
Author: Tao Van Duy Anh
Student ID: 190332316
Version: 0.1.3
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
		vector<vector<int>> test = utility.get_configs();
		for (int i = 0; i < test.size(); i++) {
			for (int j = 0; j < test[i].size(); j++) {
				int t = j + 1;
				cout << test[i][j] << '\t';

				if (t % 4 == 0 || j == (test[i].size() - 1))
					cout << endl;
			}
			cout << endl;
		}
	}
	catch (const invalid_argument & iae) {
		cout << "Unable to open file. " << iae.what() << endl;
		// change this part to ask the user to enter the name again
		exit(1);
	}

	utility.count_cont_blocks_all_turns();

	// Pause the console till any key is pressed
	system("pause");

	return 0;
}