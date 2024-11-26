#include <utility>
#include <list>
#include <vector>

using std::list;
using std::pair;
using std::vector;

void create_implication_graph(list<pair<int,int>>& disjuncts, int variable_count,
                              vector<vector<int>>& implication_graph)
{
    if (!(disjuncts.empty()))
    {
        pair<int,int> disjunct = disjuncts.front();
        int first_literal = disjunct.first;
        int second_literal = disjunct.second;

        if ((first_literal > 0) && (second_literal > 0))
        {
            implication_graph[first_literal-1+variable_count][second_literal-1] = 1;
            implication_graph[second_literal-1+variable_count][first_literal-1] = 1;
        }
        else if ((first_literal > 0) && (second_literal < 0))
        {
            implication_graph[first_literal-1+variable_count][-second_literal-1+variable_count] = 1;
            implication_graph[-second_literal-1][first_literal-1] = 1;
        }
        else if ((first_literal < 0) && (second_literal > 0))
        {
            implication_graph[-first_literal-1][second_literal-1] = 1;
            implication_graph[second_literal-1+variable_count][-first_literal-1+variable_count] = 1;
        }
        else
        {
            implication_graph[-first_literal-1][-second_literal-1+variable_count] = 1;
            implication_graph[-second_literal-1][-first_literal-1+variable_count] = 1;
        }

        disjuncts.pop_front();
        create_implication_graph(disjuncts, variable_count, implication_graph);
    }
}