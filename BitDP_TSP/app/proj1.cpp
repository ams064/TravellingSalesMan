#include "proj1.hpp"
#include <iostream> // for debug purposes, see project description for a suggestion.
#include <limits> // for UINT_MAX


// Solve TSP exactly, using dynamic programming.
// The grading script will use this exact function signature, so do not change it!
// The graph is given as an adjacency matrix, HOWEVER, no edges have a cost of '0'.
// The value graph[i][j] tells you the cost of an edge from i TO j.  This graph is directed.
// 		However, if graph[i][j]==0, this means there is no edge from i to j, instead of having one of that cost.
std::vector<unsigned> tsp_dynamic_program(const std::vector<std::vector<long>> & graph, unsigned n)
{
	std::vector<unsigned> journey;

    unsigned int mem_limit = (1<<n) - 1;
    Mem mem(n, vector<pair<long,unsigned>>(mem_limit+1, {LONG_MAX, n+1}));
    mem[0][0].first = 0;
    mem[0][1].first = LONG_MAX;
    for(int i = 1 ; i < n ; i++) {
        if(graph[i][0] != 0)
            mem[i][mem_limit].first = graph[i][0];
        else
            mem[i][mem_limit].first = LONG_MAX;
    }


    unsigned int mem_limit_2 = (1 << (n-1)) - 1;
    bool flag = true;
    for (unsigned int i = mem_limit_2; i >= 0 && flag ; i--) {
        if(i == 0) flag = false;

        for(unsigned int j = 0; j < n-1 ; j++) {
            if((i & (1 << j)) != 0) continue;

            for(unsigned int k = 0; k < n-1 ; k++) {
                if(graph[j+1][k+1] == 0 || (i & (1 << k)) != 0) continue;

                unsigned int tempMask = (i << 1);
                tempMask |= (1 << 0);
                tempMask |= (1 << (j+1));
                unsigned int tm = tempMask;
                tempMask |= (1 << (k+1));
                long cost = mem[k+1][tempMask].first == LONG_MAX ? LONG_MAX : mem[k+1][tempMask].first + graph[j+1][k+1];
                if(mem[j+1][tm].first > cost) {
                    mem[j+1][tm].first = cost;
                    mem[j+1][tm].second = k+1;
                }
            }
        }
    }

    int minSecond = -1;
    for(int i = 1; i < n ; i++) {
        if( graph[0][i] != 0 && mem[i][1 | (1<<i)].first != LONG_MAX) {
           if(mem[0][1].first > mem[i][1 | (1<<i)].first + (unsigned)graph[0][i]) {
               minSecond = i;
               mem[0][1].first = mem[i][1 | (1<<i)].first + graph[0][i];
            }
        }
    }

    if(minSecond == -1) {
        return journey;
    }

    journey.push_back(0);
    journey.push_back(minSecond);
    unsigned m = 1;
    for(int i = 2; i < n; i++) {
        unsigned p = journey[i-1];
        journey.push_back(mem[p][m | (1 << p)].second);
        m |= (1 << p);
    }

    return journey;
}


// Returns the cost of the journey described here.s
long costOfJourney(const std::vector<std::vector<long>> & graph, const std::vector<unsigned> & journey)
{
    long cost  = 0;
    for(int i = 0 ; i < journey.size(); i++) {
        if(i-1 >= 0) {
            if(graph[journey[i-1]][journey[i]] == 0) return LONG_MAX;
            cost += graph[journey[i-1]][journey[i]];
        }
    }

    cost += graph[journey[journey.size()-1]][journey[0]];
    return cost;
}

