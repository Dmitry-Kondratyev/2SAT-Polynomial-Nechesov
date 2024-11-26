#pragma once

#include <vector>

bool twosat_solver(int variable_inverse, int variable_count,
                   std::vector<std::vector<int>>& implication_graph_transitive_closure);