#pragma once
#include <iostream>
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
	const static int DEFAULT_NUM_ROW_COL = 4;
	Puzzle() throw (invalid_argument);
	Puzzle(int nrc) throw (invalid_argument);
	~Puzzle();
	friend ostream& operator<<(ostream& ostr, const Puzzle& pzl);
	bool is_existed(const int& index, const int& curr_value) const;
	bool is_in_range(const int& curr_value) const;
	void create_manual_config();
	void create_pseudo_random_config();
private:
	int num_row_col;
	vector<int> config;
};