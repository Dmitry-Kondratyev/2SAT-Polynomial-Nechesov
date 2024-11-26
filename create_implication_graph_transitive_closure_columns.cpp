#pragma once

#include <vector>

using std::vector;

void create_implication_graph_transitive_closure_columns(int j_inverse, int i, int k, int double_variable_count,
                                                      vector<vector<int>>& implication_graph)
{
    if (0 <= j_inverse)
    {
        int j = double_variable_count-j_inverse-1;
        if ((implication_graph[i][j] == 0) && (implication_graph[i][k] == 1) && (implication_graph[k][j] == 1))
        {
            implication_graph[i][j] = 1;
        }
        create_implication_graph_transitive_closure_columns(j_inverse-1, i, k,
                                                            double_variable_count, implication_graph);
    }
}