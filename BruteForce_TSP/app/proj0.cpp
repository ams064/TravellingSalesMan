#include "proj0.hpp"
#include <algorithm>
#include <iostream>

// NOTE:  This is a sample designed to show you one way to generate all 
// permutations in a graph.  It is NOT a correct answer.
// I encourage you to read this code, understand what it does, 
// and ask questions if you have any.
// Then, your understanding should help you finish the assignment. 
std::vector<unsigned> tsp_bruteforce(const std::vector<std::vector<long>> & graph, unsigned n)
{

	unsigned i;
	std::vector<unsigned> perms(n); 
	for (i = 0; i < n; i++)
	{
		perms[i] = i;
	}
    long min_cost = LONG_MAX;
    std::vector<unsigned> journey;
	do
	{
        long cost = costOfJourney(graph, perms);
        if(min_cost > cost) {
            journey = perms;
            min_cost = cost;
        }
	} while( std::next_permutation(perms.begin(), perms.end()));
	return journey;
}


long costOfJourney(const std::vector<std::vector<long>> & graph, const std::vector<unsigned> & journey)
{
    long cost  = 0;
    for(int i = 0 ; i < journey.size(); i++) {
        if(i-1 >= 0) {
            cost += graph[journey[i-1]][journey[i]];
        }
    }

    cost += graph[journey[journey.size()-1]][journey[0]];

	return cost; // this is a stub and is unlikely to be the right answer for most cases. 
}
