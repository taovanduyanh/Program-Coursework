#include "Puzzle.h"

using namespace std;
// Default constructor
Puzzle::Puzzle() :
	config(DEFAULT_NUM_ROW_COL * DEFAULT_NUM_ROW_COL) {}

// Deconstructor
// No memory on the heap atm
// Could remove this later
Puzzle::~Puzzle() {}

// make this operator do the file stuff
ostream& operator<<(ostream& ostr, const Puzzle& pzl) {

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

// Print out the configuration
// Could possibly do one loop only?
void Puzzle::print_config() const {
	cout << "The latest configuration is:" << "\n\n";

	for (const int& value : config) {
		ptrdiff_t curr_index = find(config.begin(), config.end(), value) - config.begin() + 1;

		if (value != 0)
			cout << value << '\t';
		else 
			cout << "";

		// check if it's the end of row
		if (curr_index % DEFAULT_NUM_ROW_COL == 0)
			cout << "\n\n";
	}
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
	print_config();
}

void Puzzle::create_pseudo_random_config() {
	for (int j = 0; j < config.size(); j++) {
		int random_num = rand() % 20 + 1;

		while (is_existed(j, random_num))
			random_num = rand() % 20 + 1;

		config[j] = random_num;
	}

	config[config.size() - 1] = 0;
	print_config();
}