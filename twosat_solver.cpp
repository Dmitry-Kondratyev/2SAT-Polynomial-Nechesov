#include <vector>

using std::vector;

bool twosat_solver(int variable_inverse, int variable_count,
                   vector<vector<int>>& implication_graph_transitive_closure)
{
    if (0 <= variable_inverse)
    {
        int x = variable_count-variable_inverse-1;
        if ((implication_graph_transitive_closure[x][x+variable_count] == 1) &&
            (implication_graph_transitive_closure[x+variable_count][x] == 1))
        {
            return false;
        }
        return twosat_solver(variable_inverse-1, variable_count, implication_graph_transitive_closure);
    }
    return true;
}