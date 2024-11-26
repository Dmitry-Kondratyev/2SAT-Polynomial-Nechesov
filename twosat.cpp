#include <string>
#include <iostream>
#include <fstream>
#include <utility>
#include <list>
#include <vector>
#include "twosat_read.hpp"
#include "init_implication_graph.hpp"
#include "create_implication_graph.hpp"
#include "create_implication_graph_transitive_closure.hpp"
#include "twosat_solver.hpp"

using std::string;
using std::cin;
using std::cout;
using std::ifstream;
using std::ofstream;
using std::pair;
using std::list;
using std::vector;

void twosat(int argc, char* argv[])
{
    int variable_count, disjunct_count;
    list<pair<int,int>> disjuncts;
    string p = "p";
    string cnf = "cnf";
    if (argc > 1)
    {
        ifstream input(argv[1]);
        input >> p >> cnf >> variable_count >> disjunct_count;
        twosat_read(disjunct_count, input, disjuncts);
    }
    else
    {
        cin >> p >> cnf >> variable_count >> disjunct_count;
        twosat_read(disjunct_count, cin, disjuncts);
    }
    int double_variable_count = variable_count + variable_count;
    vector<vector<int>> implication_graph;
    implication_graph.resize(double_variable_count);
    init_implication_graph(double_variable_count-1, double_variable_count, implication_graph);
    create_implication_graph(disjuncts, variable_count, implication_graph);
    create_implication_graph_transitive_closure(double_variable_count-1, double_variable_count,
                                                implication_graph);
    int result = twosat_solver(variable_count-1, variable_count, implication_graph);
    if (argc > 2)
    {
        ofstream output(argv[2]);
        if (result == 1)
        {
            output << "s SATISFIABLE\n";
        }
        else
        {
            output << "s UNSATISFIABLE\n";
        }
    }
    else
    {
        if (result == 1)
        {
            cout << "s SATISFIABLE\n";
        }
        else
        {
            cout << "s UNSATISFIABLE\n";
        }
    }
}