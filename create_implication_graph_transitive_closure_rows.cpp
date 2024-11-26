#pragma once

#include <vector>
#include "create_implication_graph_transitive_closure_columns.hpp"

using std::vector;

void create_implication_graph_transitive_closure_rows(int i_inverse, int k, int double_variable_count,
                                                      vector<vector<int>>& implication_graph)
{
    if (0 <= i_inverse)
    {
        int i = double_variable_count-i_inverse-1;
        create_implication_graph_transitive_closure_columns(double_variable_count-1, i, k,
                                                            double_variable_count, implication_graph);
        create_implication_graph_transitive_closure_rows(i_inverse-1, k, double_variable_count,
                                                         implication_graph);
    }
}