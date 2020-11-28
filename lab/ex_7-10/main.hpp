#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <string.h>
#include <thread>
#include "models/Job.hpp"
#include "models/Resource.hpp"

/**
 * Flow shop model program.
 * Simulating workplaces connected in series,
 * demonstrating a scheduling task for one way, multiple operation jobs.
 * 
 * Part 1: Modeling and simulation.
 * The Simulation_FS function calculates the start and end times of each process 
 * using the processing time and the schedule.
 * 
 * Part 2: Creating an optimal schedule for F2 | perm | Cmax using
 * the Johnson algorithm.
 * 
 * Part 3: Expanding the Johnson algorithm for F3 | perm | Cmax.
 * For this we use a virtual F2 environment.
 * The optimal solution can only be guaranteed if
 * the first resouce's minimum processing time is longer than the
 * second resource's max processing time or
 * the third resource's minimum processing time is longer than the
 * second resource's max processing time.
 * 
 * Part 4: Expanding algorithms for Fm | perm | Cmax; m > 3.
 * For this we can use the Palmer and Dannenbring algorithms.
 * The optimum cannot be guaranteed.
 * These problems are NP hard.
 * 
 * Part 5: More algorithms for Fm | perm | Cmax; m > 3:
 * - CDS (Heuristic and Interative correction) Campbell-Dudek-Schnith
 * - Search algorithm
 */

/* -------------------------------------------------------------------------- */
/*                                  Part one                                  */
/* -------------------------------------------------------------------------- */

/**
 * Simulate using processing time and schedule with Floor Shop model. 
 * 
 * @param resources A vector of shared pointers referencing resources. 
 * The vector's order provides the schedule. 
 * @param t0 Start time. 
 */
void Simulation_FS(std::vector<std::shared_ptr<Resource>> *resources, long t0);

/**
 * Print a resource oriented Gantt to the console. 
 * 
 * @param resources Vector of shared pointers to resources. 
 * The vector's order provides the schedule. 
 */
void print_Resource_Gantt(std::vector<std::shared_ptr<Resource>> *resources);

/**
 * Print a job oriented Gantt to the console. 
 * 
 * @param resources Vector of shared pointers to resources. 
 * The vector's order provides the schedule. 
 */
void print_Job_Gantt(std::vector<std::shared_ptr<Resource>> *resources);

/**
 * Calculate Cmax from Flow Shop model. 
 * 
 * @param resources Vector of shared pointers to resources. 
 * The vector's order provides the schedule. 
 */
long Evaluate(std::vector<std::shared_ptr<Resource>> resources);

/* -------------------------------------------------------------------------- */
/*                                  Part two                                  */
/* -------------------------------------------------------------------------- */

/**
 * Johnson algorithm for two machines in a Flow Shop model. 
 * This provides an optimal solution for F2 | perm | Cmax scheduling problems. 
 * 
 * @param resources An array with the two resources. 
 */
void Johnson_algorithm(std::array<std::shared_ptr<Resource>, 2> resources);

/* -------------------------------------------------------------------------- */
/*                                 Part three                                 */
/* -------------------------------------------------------------------------- */

/**
 * Extention of Johnson algorithm for three machines in a Flow Shop model, 
 * by creating a virtual F2 environment. 
 * This provides an optimal solution if the first resouce's minimum processing 
 * time is longer than the second resource's max processing time or 
 * the third resource's minimum processing time is longer than the 
 * second resource's max processing time. 
 * 
 * @param resources An array with the three resources. 
 * 
 * @returns True, if the algorithm provides an optimal solution. 
 */
bool Johnson_algorithm_ext(std::array<std::shared_ptr<Resource>, 3> resources);

/* -------------------------------------------------------------------------- */
/*                                  Part four                                 */
/* -------------------------------------------------------------------------- */

/**
 * Create schedule in {Fm | perm | Cmax} using the Palmer Algorithm: 
 * 1.) Create Palmer-index 
 * 2.) Sort by non-ascending Palmer Index 
 * 
 * The algorithm cannot provide an optimal solution in all cases, because 
 * {Fm | perm | Cmax} is NP hard. 
 * 
 * @param resources Vector of shared pointers to resources. 
 */
void Palmer_algorithm(std::vector<std::shared_ptr<Resource>> resources);

/**
 * Create schedule in {Fm | perm | Cmax} using the Dannenbring Algorithm: 
 * 1.) Create a virtual F2 environment from Fm. 
 * 2.) Use the Johnson algorithm on the F2 environment to create schedule. 
 * 
 * The algorithm cannot provide an optimal solution in all cases, because 
 * {Fm | perm | Cmax} is NP hard. 
 * 
 * @param resources Vector of shared pointers to resources.
 */
void Dannenbring_algorithm(std::vector<std::shared_ptr<Resource>> resources);

/* -------------------------------------------------------------------------- */
/*                                  Part five                                 */
/* -------------------------------------------------------------------------- */

/**
 * Create schedule in {Fm | perm | Cmax} using the CDS algorithm: 
 * 1.) Create virtual F2 resource pairs. 
 * 2.) Create schedule on F2 pairs with the Johnson algorithm. 
 * 3.) Find the best F2 schedule by calculating Cmax for every F2 schedule. 
 * 4.) Use the best schedule to sort all jobs. 
 * 
 * The algorithm cannot provide an optimal solution in all cases, because 
 * {Fm | perm | Cmax} is NP hard. 
 * 
 * @param resources Vector of shared pointers to resources.
 */
void CDS_algorithm(std::vector<std::shared_ptr<Resource>> resources);