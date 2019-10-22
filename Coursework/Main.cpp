/**
Newcaslte University
Author: Tao Van Duy Anh
Student ID: 190332316
Version: 0.1.1
*/
#include "Utility.h"

using namespace std;

int main() {
	set_manual_config();	// Manual configuration part
	set_pseudo_configs();	// Pseudo-random configuration(s) part

	// HEAVILY WIP
	cout << "TESTING PHASE" << endl;
	try {
		vector<vector<int>> test = read_configs_file("Configurations.txt");
		vector<vector<int>> test2 = sort_configs(test);
		for (int i = 0; i < test2.size(); i++) {
			for (int j = 0; j < test2[i].size(); j++) {
				int t = j + 1;
				cout << test2[i][j] << '\t';

				if (t % 4 == 0 || j == (test2[i].size() - 1))
					cout << endl;
			}
			cout << endl;
		}
	}
	catch (const invalid_argument& iae) {
		cout << "Unable to open file. " << iae.what() << endl;
		// change this part to ask the user to enter the name again
		exit(1);
	}

	// Pause the console till any key is pressed
	system("pause");

	return 0;
}