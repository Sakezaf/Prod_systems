#pragma once

#include <utility>

/**
 * Model class for defining the datastructure of a job.
 */
class Job
{
private:
    // unique identification number for each job.
    int id_;
    // Processing time.
    long ProcT_;
    // Start time.
    long StartT_;
    // End Time.
    long EndT_;
    // Due date
    long Due_;
    // Lateness
    long Lateness_;

public:
    Job(int id, long ProcT, long Due);
    ~Job();
    /* Setters and getters */

    // id

    // Set id.
    auto id() & -> int & { return id_; }
    // Get id.
    auto id() const & -> const int & { return id_; }
    // Move id.
    auto id() && -> int && { return std::move(id_); }

    // ProcT

    // Set Processing time.
    auto ProcT() & -> long & { return ProcT_; }
    // Get Processing time.
    auto ProcT() const & -> const long & { return ProcT_; }
    // Move Processing time.
    auto ProcT() && -> long && { return std::move(ProcT_); }

    // StartT

    // Set Start time.
    auto StartT() & -> long & { return StartT_; }
    // Get Start time.
    auto StartT() const & -> const long & { return StartT_; }
    // Move Start time.
    auto StartT() && -> long && { return std::move(StartT_); }

    // EndT

    // Set End time.
    auto EndT() & -> long & { return EndT_; }
    // Get End time.
    auto EndT() const & -> const long & { return EndT_; }
    // Move End time.
    auto EndT() && -> long && { return std::move(EndT_); }

    // Due date

    // Set Due date.
    auto Due() & -> long & { return Due_; }
    // Get Due date.
    auto Due() const & -> const long & { return Due_; }
    // Move Due date.
    auto Due() && -> long && { return std::move(Due_); }

    // Lateness

    // Set Lateness.
    auto Lateness() & -> long & { return Lateness_; }
    // Get Lateness.
    auto Lateness() const & -> const long & { return Lateness_; }
    // Move Lateness.
    auto Lateness() && -> long && { return std::move(Lateness_); }
};
