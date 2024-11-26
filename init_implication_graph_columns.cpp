#include <vector>

using std::vector;

void init_implication_graph_columns(int column_index, int row_index,
                                    vector<vector<int>>& implication_graph)
{
    if (0 <= column_index)
    {
        implication_graph[row_index][column_index] = 0;
        init_implication_graph_columns(column_index-1, row_index, implication_graph);
    }
}