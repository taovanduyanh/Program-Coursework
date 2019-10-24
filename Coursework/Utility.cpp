///////////////////////////		To be used in main()	///////////////////////////
#include "Utility.h"

Utility::Utility() {
	num_row_col = new int();
	num_configs = new int();
}

Utility::~Utility() {
	delete num_row_col;
	delete num_configs;
}

// Get the number of pseudo-random configurations from user
int Utility::get_num_pseudo_configs() {
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

// Get the number of possible continuous 
// e.g. 1234, 2345, 3456 are continuous
int Utility::get_num_possible_cont_blocks(vector<int> config_copy) {
	int num_cont = 0;
	int num_shifts_made = 0;
	int shift = *num_row_col - 2;
	int num_steps = *num_row_col - 1;

	// Sort the copy configuration
	sort(config_copy.begin(), config_copy.end());

	// There is possibly a better way?
	for (int i = 1; i < config_copy.size(); i++) {
		if (config_copy.at(i) - config_copy.at((_int64) i - 1) == 1) {
			num_shifts_made++;

			if (num_shifts_made % num_steps == 0) {
				i -= shift;
				num_shifts_made = 0;	// reset the number of step here
				num_cont++;
			}
		}
		else {
			num_shifts_made = 0;	// reset the number of step here
		}
	}

	return num_cont;
}

// Print out the configurartion with its continuous row
void Utility::print_num_cont_blocks_all(const int& partial_num) {
	for (const vector<int>& config : configs) {
		unsigned int num_cont_blocks_all = count_cont_blocks_all(config, partial_num);
		for (int j = 0; j < config.size(); j++) {
			int t = j + 1;
			cout << config.at(j) << '\t';

			if (t % 4 == 0)
				cout << endl;
		}
		cout << endl;
		cout << "row = " << num_cont_blocks_all << '\n';
		cout << "column = " << num_cont_blocks_all << '\n';
		cout << "reverse row = " << num_cont_blocks_all << '\n';
		cout << "reverse column = " << num_cont_blocks_all << "\n\n";
	}
}

// Start up the manual configuration part
void Utility::set_manual_config() {
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
void Utility::set_pseudo_configs() {
	srand((unsigned int)time(0)); // Prevent the same sequence of randomness among the configurations
	vector<Puzzle> pseudo_configs(get_num_pseudo_configs());

	for (Puzzle& config : pseudo_configs) {
		config.create_pseudo_random_config();
		cout << config;
	}

	// Produce a text file part
	write_configs_file(pseudo_configs);
}

unsigned long long int Utility::count_cont_blocks_all(const vector<int>& config, const int& partial_num) {
	// Lambda function - factorial
	function<unsigned int(int)> fac = [&fac](int value) {
		int result = 1;

		if (value > 1)
			result *= value * fac(value - 1);

		return result;
	};

	function<int()> get_poss_orderings = [&]() {
		return (*num_row_col) * (*num_row_col - partial_num + 1) - 1;
	};

	// change this part later on
	// i.e. change the num_row_col: do it with Puzzle instead
	unsigned long long int num_valid_cont_blocks = get_num_possible_cont_blocks(config) * get_poss_orderings() * fac(config.size() - partial_num) / 2;
	return num_valid_cont_blocks;
}

// Create a file that stores the created configurations
void Utility::write_configs_file(const vector<Puzzle>& configs) {
	ofstream configs_file("Configurations.txt");

	if (configs_file) {
		configs_file << configs.size() << '\n';
		for (const Puzzle& config : configs) {
			configs_file << config;
		}
		configs_file.close();
	}
	else
		cout << "Error: unable to open file";
}

// Get the configurations from the file
// remove configs as argument as well
void Utility::get_configs(ifstream& configs_file) {
	int num_lines = 0;	// number of lines excluding the empty line; it's used to calculate the number of rows and cols
	string line;
	configs_file >> *num_configs;
	configs.resize(*num_configs);
	configs_file.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore the first line of the file

	for (vector<int>& config : configs) {
		while (getline(configs_file, line) && !line.empty()) {
			num_lines++;
			int value;
			istringstream row(line);

			while (row >> value)
				config.push_back(value);
		}
	}

	*num_row_col = num_lines / *num_configs;
}

// Make this void instead
void Utility::read_configs_file(string file_name) throw (invalid_argument) {
	ifstream configs_file(file_name);

	// read the file
	if (configs_file) {
		get_configs(configs_file);
	}
	else
		throw invalid_argument("Error: " + file_name + " does not exist");

	configs_file.close();
}