///////////////////////////		To be used in main()	///////////////////////////
#include "Utility.h"

Utility::Utility() {
	num_configs = new unsigned long long int();
}

Utility::~Utility() {
	delete num_configs;
}

// Ask the number for specific tasks (size, no. pseudo configs, partial, etc.)
unsigned int Utility::ask_for_num(const string& msg1, const string& msg2, const int& limit) {
	int num;

	cout << msg1;
	cin >> num;

	while (!cin || num <= limit) {
		cout << msg2 + '\n';
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> num;
	}

	return num;
}

// Get the number of possible continuous blocks
unsigned int Utility::get_num_poss_cont_blocks(const Puzzle& config, const int& partial_num) {
	int num_cont_blocks = 0;
	int num_shifts_made = 0;
	int shift = partial_num - 2;
	int num_steps = partial_num - 1;

	vector<unsigned int> config_copy = config.get_config();
	// Sort the copy configuration
	sort(config_copy.begin(), config_copy.end());
	count_num_pos_cont_blocks(config_copy, num_steps, shift, num_cont_blocks, num_shifts_made);

	return num_cont_blocks;
}

// Get number of rows within a single configuration
// P/S: it's long cause there was no time
unsigned int Utility::get_num_rows(const Puzzle& config, const int& partial_num) {
	int num_row = 0;
	int num_shift_made = 0;
	int num_shifts_made = 0;
	int shift = partial_num - 2;
	int num_steps = partial_num - 1;

	vector<unsigned int> config_copy = config.get_config();

	for (int i = 1; i < config_copy.size(); i++) {
		if (config_copy.at(i) - config_copy.at((_int64)i - 1) == 1) {
			num_shifts_made++;

			if (num_shifts_made % num_steps == 0 && (i + 1) % config.get_num_row_col() == 0) {
				i++;
				num_shifts_made = 0;	// reset the number of step here
				num_row++;
			}
			else if (num_shifts_made % num_steps == 0 && (i + 1) % config.get_num_row_col() != 0) {
				i -= shift;
				num_shifts_made = 0;
				num_row++;
			}
		}
		else {
			num_shifts_made = 0;	// reset the number of step here
		}
	}

	return num_row;
}

// Get number of cols within a single configuration
// P/S: it's long cause there was no time
unsigned int Utility::get_num_cols(const Puzzle& config, const int& partial_num) {
	int num_col = 0;
	int num_shift_made = 0;
	int num_shifts_made = 0;
	int shift = (partial_num - 1) * config.get_num_row_col();
	int num_steps = partial_num - 1;

	vector<unsigned int> config_copy = config.get_config();

	for (int i = config.get_num_row_col(), j = 0; i < config_copy.size(); i += 4) {
		if (config_copy.at(i) - config_copy.at((_int64)i - config.get_num_row_col()) == 1) {
			num_shifts_made++;

			if (num_shifts_made % num_steps == 0 && i % config.get_num_row_col() == j) {
				j++;
				i = j;
				num_shifts_made = 0;	// reset the number of step here
				num_col++;
			}
			else if (num_shifts_made % num_steps == 0 && i % config.get_num_row_col() != j) {
				i -= shift;
				num_shifts_made = 0;
				num_col++;
			}
		}
		else {
			num_shifts_made = 0;	// reset the number of step here
		}
	}

	return num_col;
}

// Print out the configurartion with its continuous rows/cols/re. rows/re. cols on screen
void Utility::print_num_cont_blocks_all(const Puzzle& puzzle, const unsigned long long int& num_cont_blocks_all) {
	cout << puzzle;

	if (puzzle.get_num_row_col() != 2) {
		cout << "row = " << num_cont_blocks_all << '\n';
		cout << "column = " << num_cont_blocks_all << '\n';
		cout << "reverse row = " << num_cont_blocks_all << '\n';
		cout << "reverse column = " << num_cont_blocks_all << '\n';
	}
	else {
		cout << "row = " << num_cont_blocks_all << '\n';
		cout << "column = " << 0 << '\n';
		cout << "reverse row = " << 0 << '\n';
		cout << "reverse column = " << num_cont_blocks_all << '\n';
	}
}

// Print out the configurartion with its continuous rows/cols/re. rows/re. cols on file
void Utility::print_num_cont_blocks_all(ostream& ostr, const Puzzle& puzzle, const unsigned long long int& num_cont_blocks_all) {
	ostr << puzzle;

	if (puzzle.get_num_row_col() != 2) {
		ostr << "row = " << num_cont_blocks_all << '\n';
		ostr << "column = " << num_cont_blocks_all << '\n';
		ostr << "reverse row = " << num_cont_blocks_all << '\n';
		ostr << "reverse column = " << num_cont_blocks_all << '\n';
	}
	else {
		ostr << "row = " << num_cont_blocks_all << '\n';
		ostr << "column = " << 0 << '\n';
		ostr << "reverse row = " << 0 << '\n';
		ostr << "reverse column = " << num_cont_blocks_all << '\n';
	}
}

// Print out the configurations with their cont. rows/cols/re.rows/re.cols on file
void Utility::print_num_cont_blocks_all(ostream& ostr, const vector<Puzzle>& configs, const vector<unsigned long long int>& nums_cont_blocks_all) {
	for (size_t i = 0; i < configs.size(); i++) {
		print_num_cont_blocks_all(ostr, configs.at(i), nums_cont_blocks_all.at(i));
		ostr << '\n';
	}
}

void Utility::print_num_total_cont_single(const Puzzle& puzzle) {
	cout << "(total for row & column, including reverse, in this configuration)\n";
	cout << "2 = " << get_num_rows(puzzle, 2) + get_num_cols(puzzle, 2) << '\n';
	cout << "3 = " << get_num_rows(puzzle, 3) + get_num_cols(puzzle, 3) << '\n';
	cout << "4 = " << get_num_rows(puzzle, 4) + get_num_cols(puzzle, 4) << '\n';
}

void Utility::print_num_total_cont_single(ostream& ostr, const Puzzle& puzzle) {
	ostr << "(total for row & column, including reverse, in this configuration)\n";
	ostr << "2 = " << get_num_rows(puzzle, 2) + get_num_cols(puzzle, 2) << '\n';
	ostr << "3 = " << get_num_rows(puzzle, 3) + get_num_cols(puzzle, 3) << '\n';
	ostr << "4 = " << get_num_rows(puzzle, 4) + get_num_cols(puzzle, 4) << '\n';
}

void Utility::print_num_total_cont_all(const Puzzle& puzzle) {
	cout << "(total for row & column, including reverse, for all valid turns)\n";
	cout << "2 = " << count_cont_blocks_all(puzzle, 2) * 4 << '\n';
	cout << "3 = " << count_cont_blocks_all(puzzle, 3) * 4 << '\n';
	cout << "4 = " << count_cont_blocks_all(puzzle, 4) * 4 << '\n';
}

void Utility::print_num_total_cont_all(ostream& ostr, const Puzzle& puzzle) {
	ostr << "(total for row & column, including reverse, for all valid turns)\n";
	ostr << "2 = " << count_cont_blocks_all(puzzle, 2) * 4 << '\n';
	ostr << "3 = " << count_cont_blocks_all(puzzle, 3) * 4 << '\n';
	ostr << "4 = " << count_cont_blocks_all(puzzle, 4) * 4 << '\n';
}

// Start up the manual configuration part
void Utility::set_manual_config() {
	int num_row_col = ask_for_num("Please enter a size for the configuration(s): ", "Invalid input. Please enter a number greater than one", 1);
	Puzzle manual_config;

	try {
		manual_config.create_manual_config(num_row_col);
		cout << "\nThe configuration you've entered:\n" << manual_config;

		// Just config
		if (ask_yes_no("Would you like to save the configuration(s)?"))
			write_file(manual_config);

		// Solution part
		solve_config(manual_config);
	}
	catch (const length_error & le) {
		cout << "Unable to create configuration: " << le.what() << '\n';
	}
}

// Start up the pseudo-random configuration part
void Utility::set_pseudo_configs() {
	srand((unsigned int)time(NULL)); // Prevent the same sequence of randomness among the configurations
	int num_row_col = ask_for_num("Please enter a size for the configuration(s): ", "Invalid input. Please enter a number greater than one", 1);
	vector<Puzzle> pseudo_configs(ask_for_num("Please enter the number of pseudo-random configurations you would like to have: ", "Invalid input. Please enter a number greater than zero", 0));
	try {
		for (Puzzle& config : pseudo_configs) {
			config.create_pseudo_random_config(num_row_col);
			cout << config << '\n';
		}

		// Produce a text file part
		if (ask_yes_no("Would you like to save the configuration(s)?"))
			write_file(pseudo_configs);

		// Solution part
		solve_config(pseudo_configs);
	}
	catch (const length_error & le) {
		cout << "Unable to create configuration: " << le.what() << '\n';
	}
}

// Print out the solution (advance) on screen
void Utility::print_num_cont_blocks_advance(const Puzzle& puzzle) {
	print_num_total_cont_single(puzzle);
	print_num_total_cont_all(puzzle);
}

// Print out the solution (advance) to file
void Utility::print_num_cont_blocks_advance(ostream& ostr, const Puzzle& puzzle) {
	print_num_total_cont_single(ostr, puzzle);
	print_num_total_cont_all(ostr, puzzle);
}

void Utility::print_num_cont_blocks_advance(ostream& ostr, const vector<Puzzle>& puzzles, const vector<unsigned long long int>& nums_cont_blocks_all) {
	for (int i = 0; i < puzzles.size(); i++) {
		print_num_cont_blocks_all(ostr, puzzles.at(i), nums_cont_blocks_all.at(i));
		print_num_total_cont_single(ostr, puzzles.at(i));
		print_num_total_cont_all(ostr, puzzles.at(i));
		ostr << '\n';
	}
}

// Count the number of cont. blocks in all valid turns
unsigned long long int Utility::count_cont_blocks_all(const Puzzle& config, const int& partial_num) {
	if (config.get_num_row_col() < partial_num)
		return 0;

	// Lambda function - factorial
	function<unsigned long long int(int)> fac = [&fac](int value) {
		unsigned long long int result = 1;

		if (value > 1)
			result *= value * fac(value - 1);

		return result;
	};

	function<unsigned long long int(const Puzzle&)> get_poss_orderings = [&partial_num](const Puzzle& config) {
		return (config.get_num_row_col()) * (config.get_num_row_col() - partial_num + 1) - 1;
	};

	// change this part later on
	// i.e. change the num_row_col: do it with Puzzle instead
	unsigned long long int num_valid_cont_blocks = get_num_poss_cont_blocks(config, partial_num) * get_poss_orderings(config) * fac(config.get_config().size() - partial_num) / 2;

	// reverse the half in case the configuration is 2x2
	if (config.get_num_row_col() == 2) 
		return num_valid_cont_blocks * 2;

	return num_valid_cont_blocks;
}

// Ask the user the file name
string Utility::ask_file_name() {
	string file_name;

	cout << "Please enter the file name: ";
	cin >> file_name;

	return file_name;
}

// Ask for response [yes or no]
bool Utility::ask_yes_no(const string& msg) {
	char response;
	cout << msg + " [y/n] ";
	cin >> response;

	while (!cin || (response != 'y' && response != 'n')) {
		cout << "Invalid input. Please enter either 'y' or 'n'\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> response;
	}

	if (response == 'y')
		return true;

	return false;
}

// Create a file that stores one configuration
void Utility::write_file(const Puzzle& config) {
	ofstream configs_file(ask_file_name());

	if (configs_file) {
		configs_file << 1 << '\n';
		configs_file << config;
		configs_file.close();
	}
	else
		cout << "Unable to open file";

	cout << "File has been successfully written\n";
}

// Create a file that stores multiple configurations
void Utility::write_file(const vector<Puzzle>& configs) {
	ofstream configs_file(ask_file_name());

	if (configs_file) {
		configs_file << configs.size() << '\n';
		for (const Puzzle& config : configs) {
			configs_file << config << '\n';
		}
		configs_file.close();
	}
	else
		cout << "Unable to open file";

	cout << "File has been successfully written\n";
}

// Create a file that stores one configuration and its continuous rows/cols/re. rows/re. cols
void Utility::write_file(const Puzzle& config, const unsigned int& num_cont_blocks_all) {
	ofstream configs_file(ask_file_name());

	if (configs_file) {
		configs_file << 1 << '\n';
		print_num_cont_blocks_all(configs_file, config, num_cont_blocks_all);
		configs_file.close();
	}
	else
		cout << "Unable to open file";

	cout << "File has been successfully written\n";
}

// Create a file that stores multi configs and their cont. rows/cols/re.rows/re.cols 
void Utility::write_file(const vector<Puzzle>& configs, const vector<unsigned long long int>& nums_cont_blocks_all) {
	ofstream configs_file(ask_file_name());

	if (configs_file) {
		configs_file << configs.size() << '\n';
		print_num_cont_blocks_all(configs_file, configs, nums_cont_blocks_all);
		configs_file.close();
	}
	else
		cout << "Unable to open file";

	cout << "File has been successfully written\n";
}

// Print out a single solution (advance) to file
void Utility::write_file_advance(const Puzzle& config, const unsigned long long int& num_cont_blocks_all) {
	ofstream configs_file(ask_file_name());

	if (configs_file) {
		configs_file << 1 << '\n';
		print_num_cont_blocks_all(configs_file, config, num_cont_blocks_all);
		print_num_cont_blocks_advance(configs_file, config);
		configs_file.close();
	}
	else
		cout << "Unable to open file";

	cout << "File has been successfully written\n";
}

// Print out multiple solutions (advance) to file
void Utility::write_file_advance(const vector<Puzzle>& configs, const vector<unsigned long long int>& nums_cont_blocks_all) {
	ofstream configs_file(ask_file_name());

	if (configs_file) {
		configs_file << configs.size() << '\n';
		print_num_cont_blocks_advance(configs_file, configs, nums_cont_blocks_all);
		configs_file.close();
	}
	else
		cout << "Unable to open file";

	cout << "File has been successfully written\n";
}

// Get the configurations from the file
// remove configs as argument as well
void Utility::get_configs(ifstream& configs_file) {
	string line;
	configs_file >> *num_configs;
	configs.resize(*num_configs);
	configs_file.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore the first line of the file

	for (Puzzle& config : configs) {
		int num_lines = 0;	// number of lines excluding the empty line; it's used to calculate the number of rows and cols
		while (getline(configs_file, line) && !line.empty()) {
			num_lines++;
			int value;
			istringstream row(line);

			while (row >> value)
				config.add_value(value);
		}
		config.set_num_row_col(num_lines);
	}
}

// Make this void instead
void Utility::read_file() throw (invalid_argument) {
	configs.clear();	// clean the vector before reading
	string file_name = ask_file_name();
	ifstream configs_file(file_name);
	
	// read the file
	if (configs_file) {
		get_configs(configs_file);
		configs_file.close();
		cout << "File has been successfully read\n";
		solve_config(configs);
	}
	else {
		configs_file.clear();	// just in case if somehow the file is being rewritten
		throw invalid_argument(file_name + " does not exist");
	}
}

// Count the number of possible continuous blocks
void Utility::count_num_pos_cont_blocks(const vector<unsigned int>& config_copy, const int& num_steps, const int& shift, int& num_cont_blocks, int& num_shifts_made) {
	for (size_t i = 1; i < config_copy.size(); i++) {
		if (config_copy.at(i) - config_copy.at((_int64)i - 1) == 1) {
			num_shifts_made++;

			if (num_shifts_made % num_steps == 0) {
				i -= shift;
				num_shifts_made = 0;	// reset the number of step here
				num_cont_blocks++;
			}
		}
		else {
			num_shifts_made = 0;	// reset the number of step here
		}
	}
}

// Solve a single configuration
void Utility::solve_config(const Puzzle& config) {
	int partial_num = ask_for_num("Which partial continuous would you like to do? ", "Invalid input. Please enter a number greater than one", 1);
	unsigned long long int num_cont_blocks_all = count_cont_blocks_all(config, partial_num);
	print_num_cont_blocks_all(config, num_cont_blocks_all);
	print_num_cont_blocks_advance(config);
	cout << '\n';

	if (ask_yes_no("Would you like to save the solution(s)? [basic] "))
		write_file(config, num_cont_blocks_all);

	if (ask_yes_no("Would you like to save the solution(s)? [advance] "))
		write_file_advance(config, num_cont_blocks_all);
}

// Solve multiple configuration
void Utility::solve_config(const vector<Puzzle>& configs) {
	vector<unsigned long long int> nums_cont_blocks_all;
	int partial_num = ask_for_num("Which partial continuous would you like to do? ", "Invalid input. Please enter a number greater than one", 1);

	for (const Puzzle& config : configs) {
		unsigned long long int num_cont_blocks_all = count_cont_blocks_all(config, partial_num);
		print_num_cont_blocks_all(config, num_cont_blocks_all);
		print_num_cont_blocks_advance(config);
		nums_cont_blocks_all.push_back(num_cont_blocks_all);
		cout << '\n';
	}

	if (ask_yes_no("Would you like to save the solution(s)? [basic]"))
		write_file(configs, nums_cont_blocks_all);

	if (ask_yes_no("Would you like to save the solution(s)? [advance]"))
		write_file_advance(configs, nums_cont_blocks_all);
}
