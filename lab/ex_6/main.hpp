#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <string.h>
#include <thread>
#include "models/Job.hpp"
#include "models/Task.hpp"

/**
 * Flow shop model program.
 * Simulating workplaces connected in series,
 * demonstrating a scheduling task for one way, multiple operation tasks.
 * 
 * Part 1: Modeling and simulation.
 * The Simulation_FS function calculates the start and end times of each process 
 * using the processing time and the schedule.
 */

/**
 * Simulate using processing time and schedule.
 * 
 * @param jobs Vector of unique pointers to jobs. The vector's order gives the schedule.
 * @param NR The number of resources
 */
void Simulation_FS(std::vector<std::unique_ptr<Job>> *jobs, long t0);

/**
 * Print a resource oriented Gantt to the console.
 * 
 * @param jobs Vector of unique pointers to jobs. The vector's order gives the schedule.
 * @param NR The number of resources
 */
void print_Resource_Gantt(std::vector<std::unique_ptr<Job>> *jobs, int NR);

/**
 * Print a job oriented Gantt to the console.
 * 
 * @param jobs Vector of unique pointers to jobs. The vector's order gives the schedule.
 * @param NR The number of resources
 */
void print_Job_Gantt(std::vector<std::unique_ptr<Job>> *jobs, int NR);
