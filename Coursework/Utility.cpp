///////////////////////////		To be used in main()	///////////////////////////
#include "Utility.h"

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

// Start up the manual configuration part
void set_manual_config() {
	try {
		Puzzle manual_config;
		cout << "Welcome to 15-puzzle configuration!" << "\n\n";
		// ask user to create the configuration manually
		manual_config.create_manual_config();
		cout << "\nThe configuration you've just entered:\n" << manual_config;
	}
	catch (const invalid_argument & iae) {
		cout << "Unable to create the configuration: " << iae.what() << endl;
		// change this part to call the manual again as well
		exit(1);
	}
}

// Start up the pseudo-random configuration part
void set_pseudo_configs() {
	srand((unsigned int)time(0)); // Prevent the same sequence of randomness among the configurations
	vector<Puzzle> pseudo_configs(get_num_pseudo_configs());

	for (Puzzle& config : pseudo_configs) {
		config.create_pseudo_random_config();
		cout << config;
	}

	// Produce a text file part
	write_configs_file(pseudo_configs);
}

// Create a file that stores the created configurations
void write_configs_file(const vector<Puzzle>& configs_vector) {
	ofstream configs_file("Configurations.txt");

	if (configs_file) {
		configs_file << configs_vector.size() << endl;
		for (const Puzzle& config : configs_vector) {
			configs_file << config;
		}
		configs_file.close();
	}
	else
		cout << "Error: unable to open file";
}

// change the name to create vector or add num
vector<vector<int>> read_configs_file(string file_name) throw (invalid_argument) {
	vector<vector<int>> configs;
	ifstream configs_file(file_name);

	if (configs_file) {
		string line;
		int num_configs;
		configs_file >> num_configs;
		configs.resize(num_configs);
		configs_file.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore the first line of the file

		for (vector<int>& config : configs) {
			while (getline(configs_file, line) && !line.empty()) {
				int value;
				istringstream row(line);

				while (row >> value)
					config.push_back(value);
			}
		}
	}
	else
		throw invalid_argument("Error: " + file_name + " does not exist");

	configs_file.close();

	return configs;
}