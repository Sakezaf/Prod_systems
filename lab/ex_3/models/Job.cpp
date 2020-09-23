#include "Job.hpp"

Job::Job(int id, long ProcT, long Due)
    : id_(id), ProcT_(ProcT), Due_(Due)
{
}

Job::~Job()
{
}