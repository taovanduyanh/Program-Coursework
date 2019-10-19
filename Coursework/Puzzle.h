#pragma once
#include <iostream>
#include <ctime>
#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;

// Puzzle clas
class Puzzle {
public:
	const static int DEFAULT_NUM_ROW_COL = 4;
	Puzzle();
	Puzzle(int nrc);
	~Puzzle();
	friend ostream& operator<<(ostream& ostr, const Puzzle& pzl);
	bool is_existed(const int& index, const int& curr_value) const;
	bool is_in_range(const int& curr_value) const;
	void print_config() const;
	void create_manual_config();
	void create_pseudo_random_config();
private:
	int num_row_col;
	vector<int> config;
};

// Function for main
int get_num_pseudo_configs();
