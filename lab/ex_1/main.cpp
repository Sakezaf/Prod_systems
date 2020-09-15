#include "main.hpp"

/**
 * Main entry point of the program.
 */
int main(int argc, char const *argv[])
{

    int NJ;
    std::vector<std::unique_ptr<Job>> jobs;
    std::array<double, 3> obj_f;

    std::cout << "Demo program for scheduling." << std::endl;
    std::cout << "Please give me the number of jobs: ";
    std::cin >> NJ;
    jobs.reserve(NJ);

    // Ad-hoc scheduling.
    std::cout << "Ad-hoc scheduling" << std::endl;
    for (int i = 0; i < NJ; i++)
    {
        jobs.emplace_back(std::make_unique<Job>(i, 1 + rand() % 100));
    }

    Simulate(&jobs, 0);
    obj_f = Evaluate(&jobs);
    print_obj_func(obj_f);

    // SPT scheduling.
    std::cout << "SPT scheduling" << std::endl;
    SPT_rule(&jobs);
    obj_f = Evaluate(&jobs);
    print_obj_func(obj_f);

    for (auto &job : jobs)
    {
        std::cout << job->ProcT() << std::endl;
    }

    return 0;
}

void Simulate(std::vector<std::unique_ptr<Job>> *jobs, long t0)
{
    for (int pos = 0; pos < jobs->size(); pos++)
    {
        if (pos == 0)
            jobs->at(pos)->StartT() = t0;
        else
            jobs->at(pos)->StartT() = jobs->at(pos)->EndT();

        jobs->at(pos)->EndT() = jobs->at(pos)->StartT() + jobs->at(pos)->ProcT();
    }
}

std::array<double, 3> Evaluate(std::vector<std::unique_ptr<Job>> *jobs)
{
    double Na;
    double Cmax;
    double Csum = 0;

    for (int i = 0; i < jobs->size(); i++)
    {
        Csum += jobs->at(i)->EndT();

        if (i == 0)
            Cmax = jobs->at(i)->EndT();
        else if (Cmax < jobs->at(i)->EndT())
            Cmax = jobs->at(i)->EndT();
    }

    Na = Csum / Cmax;

    std::array<double, 3> obj_func = {Cmax, Csum, Na};
    return obj_func;
}

void print_obj_func(std::array<double, 3> obj_func)
{
    std::cout << "Cmax = " << obj_func[0] << std::endl;
    std::cout << "Csum = " << obj_func[1] << std::endl;
    std::cout << "WIP = " << obj_func[2] << std::endl;
}

bool cmp_by_ProcT(const std::unique_ptr<Job> &a, const std::unique_ptr<Job> &b)
{
    return a->ProcT() < b->ProcT();
}

void SPT_rule(std::vector<std::unique_ptr<Job>> *jobs)
{
    // Sort by non-descending ProcT.

    std::sort(jobs->begin(), jobs->end(), cmp_by_ProcT);
}