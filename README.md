# Travelling SalesMan Solver

The travelling salesman problem (also called the travelling salesperson problem[1] or TSP) asks the following question: "Given a list of cities and the distances between each pair of cities, what is the shortest possible route that visits each city and returns to the origin city?" It is an NP-hard problem in combinatorial optimization, important in operations research and theoretical computer science (from wikipedia).

The codebase solves the TSP problem in different ways :
1) Brute Force - Generates every possible path and computes the minimum path. (works for n : 1 -> 10).
Uses dynamic programming to store results of recurring states and get the minimum path. (Works for n : 1 -> 23) within 4 minutes of the time limit.
2) Uses greedy approximation using a minimum spanning tree to get an approximate minimum path such that P(using approximation) <= 2*P(actual path).
3) Uses local search algorithms like nearest neighbor and greedy nearest neighbor to solve TSP. It also uses a genetic algorithm using concepts like mutation and crossover to find the TSP path by the union graph method.
