#pragma once

#include <utility>
#include <vector>
#include <memory>
#include "Task.hpp"

/**
 * Model class for defining the datastructure of a job.
 */
class Job
{
private:
    // unique identification number for each job.
    int id_;
    // Tasks.
    std::vector<std::shared_ptr<Task>> Tasks_;

public:
    Job(int id, std::vector<std::shared_ptr<Task>> Tasks);
    ~Job();
    /* Setters and getters */

    // id

    // Set id.
    auto id() & -> int & { return id_; }
    // Get id.
    auto id() const & -> const int & { return id_; }
    // Move id.
    auto id() && -> int && { return std::move(id_); }

    // tasks

    // Set Tasks.
    auto Tasks() & -> std::vector<std::shared_ptr<Task>> & { return Tasks_; }
    // Get Tasks.
    auto Tasks() const & -> const std::vector<std::shared_ptr<Task>> & { return Tasks_; }
    // Move Tasks.
    auto Tasks() && -> std::vector<std::shared_ptr<Task>> && { return std::move(Tasks_); }
};
