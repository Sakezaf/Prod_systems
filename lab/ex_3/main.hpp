#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <string.h>
#include "models/Job.hpp"

/**
 * Program for demonstrating the use of scheduling in a singular manufacturing cell.
 * 
 * Goal #1: Decreasing usual inventory levels.
 * Solution #1: SPT scheduling. This includes changing the schedule by sorting by increasing processing time.
 * 
 * Goal #2: Decrease maximum Lateness.
 * Solution #2: Use EDD Earliest Due Date scheduling. This includes changing the schedule by sorting by increasing due date.
 * This optimises the schedule for reducing lateness.
 * 
 * P||Csum scheduling task with MSPT (Modified Shortest Processing Time) algorithm.
 * Using parralel execution of jobs.
 * The goal of this schedule is to minimize end times.
 */

/**
 * Simulate execution
 * Only one concurrent process is allowed on one Job.
 * Change-over time is contained in processing time.
 * 
 * @param jobs Vector of unique pointers to jobs to be processed.
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
std::array<double, 4> Evaluate(std::vector<std::unique_ptr<Job>> *jobs);

/**
 * Print out Evaluated details of the simulation.
 * 
 * @param obj_func A double std::array with the size of 3 containing the details.
 */
void print_obj_func(std::array<double, 4> obj_func);

/**
 * Create schedule using the SPT (Shortest Processing Time) rule.
 * 
 * @param jobs Vector of unique pointers to jobs to be processed.
 */
void SPT_rule(std::vector<std::unique_ptr<Job>> *jobs);

/**
 * Print jobs as a tab separated list to console.
 * 
 * @param jobs Pointer to a vector of unique pointers of jobs.
 */
void print_jobs(std::vector<std::unique_ptr<Job>> *jobs);

/**
 * Create schedule using the EDD (Earliest Due Date) rule.
 * 
 * @param jobs Vector of unique pointers to jobs to be processed.
 */
void EDD_rule(std::vector<std::unique_ptr<Job>> *jobs);