#include <utility>
#include <list>
#include <iostream>
#include <string>

using std::pair;
using std::list;
using std::istream;
using std::make_pair;
using std::string;
using std::cout;

void twosat_read(int disjunct_count, istream& input_stream, list<pair<int, int>>& disjuncts)
{
    if (0 < disjunct_count)
    {
        string zero = "0";
        int first_literal, second_literal;
        input_stream >> first_literal >> second_literal >> zero;
        disjuncts.push_back(make_pair(first_literal, second_literal));
        twosat_read(disjunct_count-1,input_stream, disjuncts);
    }
}