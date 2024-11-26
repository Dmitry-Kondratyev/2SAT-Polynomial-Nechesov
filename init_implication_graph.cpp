#include <vector>
#include "init_implication_graph_columns.hpp"

using std::vector;

void init_implication_graph(int row_index, int double_variable_count,
                            vector<vector<int>>& implication_graph)
{
    if (0 <= row_index)
    {
        implication_graph[row_index].resize(double_variable_count);
        init_implication_graph_columns(double_variable_count-1, row_index, implication_graph);
        init_implication_graph(row_index-1, double_variable_count, implication_graph);
    }
}