#pragma once
#include "Puzzle.h"

// Function for main
int get_num_pseudo_configs();
void set_manual_config();
void set_pseudo_configs();
void write_configs_file(const vector<Puzzle>& configs_vector);
vector<vector<int>> read_configs_file(string file_name) throw (invalid_argument);