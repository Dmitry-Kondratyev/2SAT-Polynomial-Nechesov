#pragma once

#include <utility>
#include <list>
#include <vector>

void create_implication_graph(std::list<std::pair<int,int>>& disjuncts, int variable_count,
                              std::vector<std::vector<int>>& implication_graph);