#include "Job.hpp"

Job::Job(int id, std::vector<std::shared_ptr<Task>> Tasks)
    : id_(id), Tasks_(Tasks)
{
}

Job::~Job()
{
}