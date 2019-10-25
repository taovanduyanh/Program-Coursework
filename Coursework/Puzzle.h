#pragma once
#include <iostream>
#include <functional>
#include <ctime>
#include <string>
#include <sstream>
#include <stdexcept>
#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;

// Puzzle clas
class Puzzle {
public:
	Puzzle();
	~Puzzle();
	Puzzle(const Puzzle& src);
	Puzzle& operator=(const Puzzle& src);
	friend ostream& operator<<(ostream& ostr, const Puzzle& pzl);
	int get_num_row_col() const { return *num_row_col; }
	vector<unsigned int> get_config() const { return config; }
	bool is_existed(const int& index, const int& curr_value) const;
	bool is_in_range(const int& curr_value) const { return curr_value > 0 && curr_value <= (*num_row_col) * (*num_row_col) + (*num_row_col); }
	void add_value(const int& value) { config.push_back(value); }
	void set_num_row_col(const int& value) { *num_row_col = value; }
	void create_manual_config(const int& nrc) throw (length_error);
	void create_pseudo_random_config(const int& nrc) throw (length_error);
private:
	int* num_row_col;
	vector<unsigned int> config;
};