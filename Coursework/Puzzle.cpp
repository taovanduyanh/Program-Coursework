#include "Puzzle.h"

using namespace std;
// Default constructor
Puzzle::Puzzle() :
	num_row_col(DEFAULT_NUM_ROW_COL), config(num_row_col* num_row_col) {}

// Custom constructor
Puzzle::Puzzle(int nrc) :
	num_row_col(nrc), config(num_row_col* num_row_col) {}

// Deconstructor
// No memory on the heap atm
// Could remove this later
Puzzle::~Puzzle() {}

// Print out the configuration to the screen or file
ostream& operator<<(ostream& ostr, const Puzzle& pzl) {
	for (const int& value : pzl.config) {
		ptrdiff_t curr_index = find(pzl.config.begin(), pzl.config.end(), value) - pzl.config.begin() + 1;

		if (value != 0)
			ostr << value << '\t';
		else
			ostr << "";

		// check if it's the end of row
		if (curr_index % pzl.num_row_col == 0)
			ostr << '\n';
	}

	ostr << '\n';

	return ostr;
}

// Check if the input has already been inserted into the puzzle (configuration)
// not known yet the efficiency
bool Puzzle::is_existed(const int& index, const int& curr_value) const {
	if (index == 0)
		return false;
	
	for (int i = 0; i < index; i++) {
		if (config[i] == curr_value)
			return true;
	}

	return false; 
}

// Check if the input is in range or not
// Allow user to enter the range?
bool Puzzle::is_in_range(const int& curr_value) const {
	if (curr_value < 1 || curr_value > 20)
		return false;

	return true;
}

// Create a configuration manually 
void Puzzle::create_manual_config() {
	int blank_index = config.size() - 1;

	for (int i = 0; i < blank_index; i++) {
		int temp_val_holder;
		cout << "Please enter a number into the configuration at position " << i << endl;
		cin >> temp_val_holder;

		while (!cin || !is_in_range(temp_val_holder) || is_existed(i, temp_val_holder)) {
			cout << "Error: invalid input. Please enter a number within the range of 1 to 20" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> temp_val_holder;
		}

		config.at(i) = temp_val_holder;
	}

	config.at(blank_index) = 0;
}

void Puzzle::create_pseudo_random_config() {
	int blank_index = config.size() - 1;

	for (int i = 0; i < blank_index; i++) {
		int random_num = rand() % 20 + 1;

		while (is_existed(i, random_num))
			random_num = rand() % 20 + 1;

		config.at(i) = random_num;
	}

	config.at(blank_index) = 0;
}

///////////////////////////		To be used in main()	///////////////////////////

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
	cout << "Welcome to 15-puzzle configuration!" << "\n\n";
	Puzzle manual_config;

	// ask user to create the configuration manually
	manual_config.create_manual_config();
	cout << "\nThe configuration you've just entered:\n" << manual_config;
}

// Start up the pseudo-random configuration part
void set_pseudo_configs() {
	srand(time(NULL)); // Prevent the same sequence of randomness among the configurations
	vector<Puzzle> pseudo_configs(get_num_pseudo_configs());

	for (Puzzle& config : pseudo_configs) {
		config.create_pseudo_random_config();
		cout << config;
	}

	// Produce a text file part
	create_configs_file(pseudo_configs);
}

// Create a file that stores the created configurations
void create_configs_file(const vector<Puzzle>& configs_vector) {
	ofstream configs_file("Configurations.txt");

	if (configs_file.is_open()) {
		configs_file << configs_vector.size() << endl;
		for (const Puzzle& config : configs_vector) {
			configs_file << config;
		}
		configs_file.close();
	}
	else
		cout << "Error: unable to open file";
}