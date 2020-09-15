#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include "models/Job.hpp"

/**
 * Program for demonstrating the use of scheduling in a singular manufacturing cell.
 * Goal: Descreasing the usual inventory level.
 * Solution: SPT scheduling.
 */

/**
 * Simulate execution
 * Only one concurrent process is allowed on one Job.
 * Change-over time is contained in processing time.
 * 
 * @param jobs Vector of unique pointers to jobs to be processed.
 * @param s Schedule, a vector of integers, which must be the same lenght as jobs.
 * @param t0 Start of processing.
 */
void Simulate(std::vector<std::unique_ptr<Job>> *jobs, long t0);

/**
 * Evaluate the simulation.
 * Na: Average WIP (Work In Progress). 
 * Cmax: Completion time 
 * Csum: Sum of job completion time. 
 * 
 * @param jobs Vector of unique pointers to processed jobs.
 * @return Array of Cmax, Csum, Na
 */
std::array<double, 3> Evaluate(std::vector<std::unique_ptr<Job>> *jobs);

/**
 * Print out Evaluated details of the simulation.
 * 
 * @param obj_func A double std::array with the size of 3 containing the details.
 */
void print_obj_func(std::array<double, 3> obj_func);

/**
 * Create schedule using the SPT (Shortest Processing Time) rule.
 * 
 * @param jobs Vector of unique pointers to jobs to be processed.
 * @param s Schedule, a vector of integers, which must be the same lenght as jobs.
 */
void SPT_rule(std::vector<std::unique_ptr<Job>> *jobs);

/**
 * Compare jobs by processing time.
 * 
 * @param a unique pointer of job "a".
 * @param b unique pointer of job "b".
 * @return Is a.ProcT smaller than b.ProcT
 */
bool cmp_by_ProcT(const std::unique_ptr<Job> &a, const std::unique_ptr<Job> &b);