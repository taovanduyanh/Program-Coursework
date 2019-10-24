#include "Puzzle.h"

using namespace std;
// Default constructor
Puzzle::Puzzle() throw (invalid_argument) :
	num_row_col(DEFAULT_NUM_ROW_COL), config() {
	int config_size(num_row_col * num_row_col);
	config.resize(config_size);

	if (num_row_col <= 0)
		throw invalid_argument("the size must be higher than zero. Size gotten: " + to_string(num_row_col));
}

// Custom constructor
Puzzle::Puzzle(int nrc) throw (invalid_argument) :
	num_row_col(nrc), config() {
	int config_size(num_row_col * num_row_col);
	config.resize(config_size);

	if (num_row_col <= 0)
		throw invalid_argument("the size must be higher than zero. Size gotten: " + to_string(num_row_col));
}

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
	for (int i = 0; i < config.size() - 1; i++) {
		int temp_val_holder;
		cout << "Please enter a number at position " << i << endl;
		cin >> temp_val_holder;

		while (!cin || !is_in_range(temp_val_holder) || is_existed(i, temp_val_holder)) {
			cout << "Error: invalid input. Please enter a number within the range of 1 to 20" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> temp_val_holder;
		}

		config.at(i) = temp_val_holder;
	}

	config.at(config.size() - 1) = 0;
}

void Puzzle::create_pseudo_random_config() {
	for (int i = 0; i < config.size() - 1; i++) {
		int random_num = rand() % 20 + 1;

		while (is_existed(i, random_num))
			random_num = rand() % 20 + 1;

		config.at(i) = random_num;
	}

	config.at(config.size() - 1) = 0;
}