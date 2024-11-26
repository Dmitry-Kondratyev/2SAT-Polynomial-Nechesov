#pragma once

#include <utility>
#include <list>
#include <iostream>

void twosat_read(int disjunct_count, std::istream& input_stream, std::list<std::pair<int,int>>& disjuncts);