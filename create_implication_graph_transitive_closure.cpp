#pragma once

#include <vector>
#include "create_implication_graph_transitive_closure_rows.hpp"

using std::vector;

void create_implication_graph_transitive_closure(int k_inverse, int double_variable_count,
                                                 vector<vector<int>>& implication_graph)
{
    if (0 <= k_inverse)
    {
        int k = double_variable_count-k_inverse-1;
        create_implication_graph_transitive_closure_rows(double_variable_count-1, k, double_variable_count,
                                                         implication_graph);
        create_implication_graph_transitive_closure(k_inverse-1, double_variable_count, implication_graph);
    }
}