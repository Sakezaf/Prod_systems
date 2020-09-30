#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <string.h>
#include <thread>
#include "models/Job.hpp"
#include "models/Machine.hpp"

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
 * Goal #3: Decrease Cmax.
 * Solution #3: Use multiple machines concurrently with SPT scheduling.
 * 
 * Goal #4: Decrease Csum on multiple resources.
 * Solution #4: MSPT rule.
 * 
 * Goal #5: Decrease Cmax on multiple resources.
 * Solution #5: LPT+LIST scheduling.
 * This does not result in an optimal schedule because it is NP-hard,
 * but it is a good approximation.
 * 
 * Goal #6: Decrease maximum lateness on multiple resources.
 * Solution #6: EDD+LIST scheduling.
 * This does not result in an optimal schedule because it is NP-hard,
 * but it is a good approximation.
 * 
 * LIST rule:
 * We use an existing ruleset to preschedule all our jobs.
 * Then we load the resource that becomes available the soonest.
 * If multiple machines become available at the same time, we load the one with the first in line.
 * 
 */

/**
 * Simulate execution
 * Only one concurrent process is allowed on one Job.
 * Change-over time is contained in processing time.
 * 
 * @param jobs Vector of shared pointers to jobs to be processed.
 * @param t0 Start of processing.
 */
void Simulate(std::vector<std::shared_ptr<Job>> *jobs, long t0);

/**
 * Evaluate the simulation.
 * Na: Average WIP (Work In Progress). 
 * Cmax: Completion time 
 * Csum: Sum of job completion time. 
 * 
 * @param jobs Vector of shared pointers to processed jobs.
 * @return Array of Cmax, Csum, Na
 */
std::array<double, 4> Evaluate(std::vector<std::shared_ptr<Job>> *jobs);

/**
 * Print out Evaluated details of the simulation.
 * 
 * @param obj_func A double std::array with the size of 3 containing the details.
 */
void print_obj_func(std::array<double, 4> obj_func);

/**
 * Create schedule using the SPT (Shortest Processing Time) rule.
 * 
 * @param jobs Vector of shared pointers to jobs to be processed.
 */
void SPT_rule(std::vector<std::shared_ptr<Job>> *jobs);

/**
 * Create schedule using the LPT (Longest Processing Time) rule.
 * 
 * @param jobs Vector of shared pointers to jobs to be processed.
 */
void LPT_rule(std::vector<std::shared_ptr<Job>> *jobs);

/**
 * Print jobs as a tab separated list to console.
 * 
 * @param jobs Pointer to a vector of shared pointers of jobs.
 */
void print_jobs(std::vector<std::shared_ptr<Job>> *jobs);

/**
 * Create schedule using the EDD (Earliest Due Date) rule.
 * 
 * @param jobs Vector of shared pointers to jobs to be processed.
 */
void EDD_rule(std::vector<std::shared_ptr<Job>> *jobs);

/**
 * Modified Shortest Processing Time rule.
 * Creates a schedule for multiple machines using the SPT rule.
 * 
 * @param jobs Vector of jobs to be processed.
 * @param machines Vector of machines.
 */
void MSPT_rule(std::vector<std::shared_ptr<Job>> *jobs, std::vector<std::shared_ptr<Machine>> *resources);

/**
 * Simulates execution on multiple parallel machines.
 * 
 * @param machines Vector of machines.
 * @param t0 start time.
 */
void Simulation_P(std::vector<std::shared_ptr<Machine>> *resources, long t0);

/**
 * Print data of all machines/resources.
 * 
 * @param machines Vector of machines.
 */
void print_resources(std::vector<std::shared_ptr<Machine>> *resources);

/**
 * List based scheduling for concurrent resources.
 * 
 * @param jobs Vector of job ponters.
 * @param resources Vector of resource pointers.
 * @param rule Function for a prescheduling rule (e.g. EDD or LPT rule)
 */
void LIST_rule(std::vector<std::shared_ptr<Job>> *jobs,
               std::vector<std::shared_ptr<Machine>> *resources,
               void rule(std::vector<std::shared_ptr<Job>> *));
