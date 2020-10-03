#ifndef TASK
#define TASK
#include <memory>

/**
 * Model class for defining the datastructure of a Task.
 */
class Task
{
private:
    // Proccessing time.
    long ProcT_;
    // Start time.
    long StartT_;
    // End time.
    long EndT_;

public:
    Task(long ProcT);
    ~Task();

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
};
#endif
