#pragma once

#include <utility>
#include <vector>
#include <memory>
#include "Job.hpp"

/**
 * Model class defining the datastructure of Reasources/Machines.
 */
class Machine
{
private:
    // id
    int id_;
    // Jobs
    std::vector<std::shared_ptr<Job>> jobs_;
    // C
    long c_;

public:
    Machine(int id);
    ~Machine();

    /* Getters and Setters */

    // Set id.
    auto id() & -> int & { return id_; }
    // Get id.
    auto id() const & -> const int & { return id_; }
    // Move id.
    auto id() && -> int && { return std::move(id_); }

    // Set Jobs.
    auto jobs() & -> std::vector<std::shared_ptr<Job>> & { return jobs_; }
    // Get Jobs.
    auto jobs() const & -> const std::vector<std::shared_ptr<Job>> & { return jobs_; }

    // Set C.
    auto c() & -> long & { return c_; }
    // Get C.
    auto c() const & -> const long & { return c_; }
    // Move C.
    auto c() && -> long && { return std::move(c_); }
};
