#include "Resource.hpp"

Resource::Resource(int id, std::vector<std::shared_ptr<Job>> Jobs)
    : id_(id), Jobs_(Jobs)
{
}

Resource::~Resource()
{
}