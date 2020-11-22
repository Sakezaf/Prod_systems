#pragma once

#include <utility>
#include <vector>
#include <memory>
#include "Job.hpp"

/**
 * Model class for defining the datastructure of a resource.
 */
class Resource
{
private:
    // unique identification number for each resource.
    int id_;
    // Jobs.
    std::vector<std::shared_ptr<Job>> Jobs_;

public:
    Resource(int id, std::vector<std::shared_ptr<Job>> Tasks);
    ~Resource();
    /* Setters and getters */

    // id

    // Set id.
    auto id() & -> int & { return id_; }
    // Get id.
    auto id() const & -> const int & { return id_; }
    // Move id.
    auto id() && -> int && { return std::move(id_); }

    // jobs

    // Set Jobs.
    auto Jobs() & -> std::vector<std::shared_ptr<Job>> & { return Jobs_; }
    // Get Jobs.
    auto Jobs() const & -> const std::vector<std::shared_ptr<Job>> & { return Jobs_; }
    // Move Jobs.
    auto Jobs() && -> std::vector<std::shared_ptr<Job>> && { return std::move(Jobs_); }
};
