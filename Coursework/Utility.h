// Class for main 
#pragma once
#include "Puzzle.h"

class Utility {
public:
	Utility();
	~Utility();
	int get_num_pseudo_configs();
	int get_num_possible_cont_blocks(vector<int> config_copy);
	void read_configs_file(string file_name) throw (invalid_argument);
	void set_manual_config();
	void set_pseudo_configs();
	void count_cont_blocks_all_turns();
	void write_configs_file(const vector<Puzzle>& configs);
	void get_configs(ifstream& configs_file);
	// purely for testing, delete it later
	vector<vector<int>> get_configs() const { return configs; }
private:
	int* num_row_col;
	int* num_configs;
	vector<vector<int>> configs;
	// vector here..
};
