#include <iostream>
#include <vector>
#include <memory>
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
void Simulate(std::vector<std::unique_ptr<Job>> *jobs, std::vector<int> *s, long t0);

/**
 * Evaluate the simulation.
 * Na: Average WIP (Work In Progress). 
 * Cmax: Completion time 
 * Csum: Sum of job completion time. 
 * 
 * @param jobs Vector of unique pointers to processed jobs.
 * @param obj_func Array containing Na, Cmax and Csum.
 */
void Evaluate(std::vector<std::unique_ptr<Job>> *jobs, double obj_func[3]);

/**
 * Print out Evaluated details of the simulation.
 * 
 * @param obj_func A double array containing the details.
 */
void print_obj_func(double obj_func[3]);

/**
 * Create schedule using the SPT (Shortest Processing Time) rule.
 * 
 * @param jobs Vector of unique pointers to jobs to be processed.
 * @param s Schedule, a vector of integers, which must be the same lenght as jobs.
 */
void SPT_rule(std::vector<std::unique_ptr<Job>> *jobs, std::vector<int> *s);