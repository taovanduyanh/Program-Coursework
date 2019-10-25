#include "Puzzle.h"

using namespace std;

// Constructor
Puzzle::Puzzle() {
	num_row_col = new int();
}

// Copy constructor
Puzzle::Puzzle(const Puzzle& src) : 
	num_row_col(new int(*src.num_row_col)) {
	config = src.config;
}

// Assignment operator (for Puzzle)
Puzzle& Puzzle::operator=(const Puzzle& src) {
	if (this == &src)
		return *this;

	delete num_row_col;

	num_row_col = new int(*src.num_row_col);
	config = src.config;

	return *this;
}

// Deconstructor
Puzzle::~Puzzle() {
	delete num_row_col;
}

// Print out the configuration to the screen or file
ostream& operator<<(ostream& ostr, const Puzzle& pzl) {
	for (size_t i = 0; i < pzl.config.size(); i++) {
		ostr << pzl.config.at(i) << '\t';	// print out the value

		// check if it's the end of row
		if ((i + 1) % *pzl.num_row_col == 0)
			ostr << '\n';
	}

	ostr << '\n';

	return ostr;
}

// Check if the input has already been inserted into the puzzle (configuration)
// not known yet the efficiency
bool Puzzle::is_existed(const int& index, const int& curr_value) const {
	for (const int& value : config) {
		if (value == curr_value)
			return true;
	}

	return false; 
}

// Create a configuration manually 
void Puzzle::create_manual_config(const int& nrc) {
	if ((nrc * nrc + nrc) + 1 > config.max_size())
		throw length_error("exceed vector's maximum size = " + to_string(config.max_size()));

	*num_row_col = nrc;
	config.resize(nrc * nrc - 1);
	cout << "Please enter a value at position\n";

	for (size_t i = 0; i < config.size(); i++) {
		int value;
		cout << '[' << i << "]:\t";
		cin >> value;

		while (!cin || !is_in_range(value) || is_existed(i, value)) {
			cout << "Invalid input. Please enter a number within the range of 1 to " << nrc * nrc + nrc << '\n';
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> value;
		}

		config.at(i) = value;
	}
}

// Create pseudo random configuration(s)
void Puzzle::create_pseudo_random_config(const int& nrc) throw (length_error) {
	if ((nrc * nrc + nrc) + 1 > config.max_size())
		throw length_error("exceed vector's maximum size = " + to_string(config.max_size()));

	*num_row_col = nrc;
	config.resize(nrc* nrc - 1);

	generate_n(config.begin(), config.size(), [&]() {
		int rand_num = rand() % (nrc * nrc + nrc) + 1;

		while (is_existed(0, rand_num))
			rand_num = rand() % (nrc * nrc + nrc) + 1;

		return rand_num;
		});
}