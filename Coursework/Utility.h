// Class for main 
#pragma once
#include "Puzzle.h"

class Utility {
public:
	Utility();
	~Utility();
	unsigned int ask_for_num(const string& msg1, const string& msg2, const int& limit);
	unsigned int get_num_poss_cont_blocks(const Puzzle& config, const int& partial_num);
	unsigned long long int count_cont_blocks_all(const Puzzle& config, const int& partial_num);
	string ask_file_name();
	bool ask_yes_no(const string& msg);
	void write_file(const Puzzle& config);
	void write_file(const vector<Puzzle>& configs);
	void write_file(const Puzzle& config, const unsigned int& num_cont_blocks_all);
	void write_file(const vector<Puzzle>& configs, const vector<unsigned long long int>& nums_cont_blocks_all);
	void read_file();
	void count_num_pos_cont_blocks(const vector<unsigned int>& config_copy, const int& num_steps, const int& shift, int& num_cont_blocks, int& num_shifts_made);
	void solve_config(const Puzzle& config);
	void solve_config(const vector<Puzzle>& configs);
	void set_manual_config();
	void set_pseudo_configs();
	void print_num_cont_blocks_advance(const Puzzle& puzzle, int& partial_num);
	void print_num_cont_blocks_all(const Puzzle& puzzle, const unsigned long long int& num_cont_blocks_all);
	void print_num_cont_blocks_all(ostream& ostr, const Puzzle& puzzle, const unsigned long long int& num_cont_blocks_all);
	void print_num_cont_blocks_all(ostream& ostr, const vector<Puzzle>& configs, const vector<unsigned long long int>& nums_cont_blocks_all);
	void print_num_partial_cont_blocks(const Puzzle& puzzle, int& partial_num);
	void get_configs(ifstream& configs_file);
private:
	unsigned long long int* num_configs;
	vector<Puzzle> configs;
};
