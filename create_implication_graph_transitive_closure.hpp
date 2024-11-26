#pragma once

#include <vector>

void create_implication_graph_transitive_closure(int k_inverse, int double_variable_count,
                                                 std::vector<std::vector<int>>& implication_graph);