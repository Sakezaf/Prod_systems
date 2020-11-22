#include "main.hpp"

auto max_l = [](long a, long b) { return a >= b ? a : b; };

int main(int argc, char const *argv[])
{
    // Write tables to console.
    bool table = false;
    // number of jobs
    int NJ;
    // number of resources
    int NR;

    // seed rand with time
    srand(time(NULL));

    std::vector<std::shared_ptr<Resource>> resources;

    if (argc > 1)
    {
        for (int i = 1; i < argc; i++)
        {
            if (strcmp(argv[i], "-t") == 0)
                table = true;
        }
    }

    std::cout << "Demo program for scheduling." << std::endl;
    std::cout << "Please give me the number of jobs: ";
    std::cin >> NJ;
    std::cout << "Please give me the number of resources: ";
    std::cin >> NR;
    resources.reserve(NR);

    for (int i = 0; i < NR; i++)
    {
        std::vector<std::shared_ptr<Job>> jobs;
        jobs.reserve(NJ);
        for (int j = 0; j < NJ; j++)
        {
            jobs.emplace_back(std::make_shared<Job>(j, 1 + rand() % 100));
        }
        resources.emplace_back(std::make_unique<Resource>(i, std::move(jobs)));
    }

    std::cout << "Ad-hoc schedule" << std::endl;
    Simulation_FS(&resources, 0);
    if (table)
    {
        print_Resource_Gantt(&resources);
        print_Job_Gantt(&resources);
    }

    std::cout << "Cmax: " << Evaluate(resources) << std::endl;

    if (NR == 2)
    {
        std::cout << "Johnson algorithm (F2)" << std::endl;
        Johnson_algorithm({resources[0], resources[1]});
        Simulation_FS(&resources, 0);
        if (table)
        {
            print_Resource_Gantt(&resources);
            print_Job_Gantt(&resources);
        }
        std::cout << "Cmax: " << Evaluate(resources) << std::endl;
    }
    if (NR == 3)
    {
        std::cout << "Johnson algorithm extended (F3)" << std::endl;
        if (Johnson_algorithm_ext({resources[0], resources[1], resources[2]}))
        {
            std::cout << "Optimal solution" << std::endl;
        }
        Simulation_FS(&resources, 0);
        if (table)
        {
            print_Resource_Gantt(&resources);
            print_Job_Gantt(&resources);
        }
        std::cout << "Cmax: " << Evaluate(resources) << std::endl;
    }

    return 0;
}

void print_Job_Gantt(std::vector<std::shared_ptr<Resource>> *resources)
{
    for (unsigned int j = 0; j < resources->at(0)->Jobs().size(); j++)
    {
        std::cout << "job id: " << resources->at(0)->Jobs()[j]->id() << std::endl;
        std::cout << "#\trid\tStartT\tProcT\tEndT" << std::endl;
        for (auto &resource : *resources)
        {
            std::cout << j << "\t"
                      << resource->id() << "\t"
                      << resource->Jobs()[j]->StartT() << "\t"
                      << resource->Jobs()[j]->ProcT() << "\t"
                      << resource->Jobs()[j]->EndT() << std::endl;
        }
    }
}

void print_Resource_Gantt(std::vector<std::shared_ptr<Resource>> *resources)
{
    // resources
    for (unsigned int r = 0; r < resources->size(); r++)
    {
        auto currResource = *resources->at(r);
        std::cout << "resource id: " << currResource.id() << std::endl;
        std::cout << "#\tjob\tstart\tproc_t\tend" << std::endl;
        // jobs
        for (unsigned int i = 0; i < currResource.Jobs().size(); i++)
        {
            auto currJob = resources->at(r)->Jobs()[i];
            std::cout << i << "\t"
                      << currJob->id() << "\t"
                      << currJob->StartT() << "\t"
                      << currJob->ProcT() << "\t"
                      << currJob->EndT() << std::endl;
        }
    }
}

void Simulation_FS(std::vector<std::shared_ptr<Resource>> *resources, long t0)
{
    // jobs
    for (unsigned int i = 0; i < resources->size(); i++)
    {
        // resources
        for (unsigned int r = 0; r < resources->at(i)->Jobs().size(); r++)
        {
            // create reference to current task
            auto currJob = std::shared_ptr<Job>(resources->at(i)->Jobs()[r]);
            // first job
            if (i == 0)
            {
                // first resource
                if (r == 0)
                {
                    currJob->StartT() = t0;
                }
                else
                {
                    currJob->StartT() = resources->at(i)->Jobs()[r - 1]->EndT();
                }
            }
            else
            {
                // first resource
                if (r == 0)
                {
                    currJob->StartT() = resources->at(i - 1)->Jobs()[r]->EndT();
                }
                else
                {
                    currJob->StartT() = max_l(resources->at(i)->Jobs()[r - 1]->EndT(), resources->at(i - 1)->Jobs()[r]->EndT());
                }
            }
            // set End time.
            currJob->EndT() = currJob->StartT() + currJob->ProcT();
        }
    }
}

void Johnson_algorithm(std::array<std::shared_ptr<Resource>, 2> resources)
{
    auto jobCount = resources[0]->Jobs().size();

    // Pre-schedule vector.
    std::vector<std::array<std::shared_ptr<Job>, 2>> jobsTemp;

    // Init values in ad-hoc order.
    for (unsigned int i = 0; i < jobCount; i++)
    {
        jobsTemp.push_back({resources[0]->Jobs()[i], resources[1]->Jobs()[i]});
    }

    // Sort by min value for each job's processing time over both resources.
    std::sort(jobsTemp.begin(), jobsTemp.end(),
              [](std::array<std::shared_ptr<Job>, 2> a, std::array<std::shared_ptr<Job>, 2> b) {
                  return std::min(a[0]->ProcT(), a[1]->ProcT()) < std::min(b[0]->ProcT(), b[1]->ProcT());
              });

    // Final schedule vector.
    std::vector<std::array<std::shared_ptr<Job>, 2>> jobs(jobCount);
    // Index of "first" element.
    int first = 0;
    // Index of "last" element.
    int last = jobCount - 1;
    // Put pre-scheduled jobs into the final schedule.
    for (auto &job : jobsTemp)
    {
        if (job[0]->ProcT() < job[1]->ProcT())
        {
            jobs[first] = job;
            first++;
        }
        else
        {
            jobs[last] = job;
            last--;
        }
    }

    // remove any schedule from resources.
    resources[0]->Jobs().clear();
    resources[1]->Jobs().clear();

    // Push new schedule.
    resources[0]->Jobs().reserve(jobs.size());
    resources[1]->Jobs().reserve(jobs.size());
    for (auto &job : jobs)
    {
        resources[0]->Jobs().emplace_back(std::move(job[0]));
        resources[1]->Jobs().emplace_back(std::move(job[1]));
    }
}

bool Johnson_algorithm_ext(std::array<std::shared_ptr<Resource>, 3> resources)
{
    auto jobCount = resources[0]->Jobs().size();

    // Init virtual F2 resources array.
    std::array<std::shared_ptr<Resource>, 2> virtual_resources;
    virtual_resources[0] = std::make_shared<Resource>(0, std::vector<std::shared_ptr<Job>>());
    virtual_resources[1] = std::make_shared<Resource>(1, std::vector<std::shared_ptr<Job>>());
    virtual_resources[0]->Jobs().reserve(jobCount);
    virtual_resources[1]->Jobs().reserve(jobCount);

    // Calculate virtual F2 jobs.
    for (unsigned int i = 0; i < jobCount; i++)
    {
        // vpi1 = pi1 + pi2
        virtual_resources[0]->Jobs().emplace_back(std::make_shared<Job>(i, resources[0]->Jobs()[i]->ProcT() + resources[1]->Jobs()[i]->ProcT()));
        // vpi2 = pi2 + pi3
        virtual_resources[1]->Jobs().emplace_back(std::make_shared<Job>(i, resources[1]->Jobs()[i]->ProcT() + resources[2]->Jobs()[i]->ProcT()));
    }

    // Call Johnson alg. with virtual F2 machines.
    Johnson_algorithm(virtual_resources);

    // Create F3 schedule from virtual F2 schedule.
    std::vector<std::array<std::shared_ptr<Job>, 3>> schedule;
    schedule.reserve(jobCount);
    for (unsigned int i = 0; i < jobCount; i++)
    {
        auto job = virtual_resources[0]->Jobs()[i]->id();
        schedule.push_back({std::move(resources[0]->Jobs()[job]), std::move(resources[1]->Jobs()[job]), std::move(resources[2]->Jobs()[job])});
    }

    // Memory manageme
    for (auto resource : virtual_resources)
    {
        resource.reset();
    }
    for (auto resource : resources)
    {
        resource->Jobs().clear();
    }

    // push F3 schedule into rescource->Jobs(); for each resource.
    for (auto job : schedule)
    {
        for (unsigned int i = 0; i < resources.size(); i++)
        {
            resources[i]->Jobs().emplace_back(std::move(job[i]));
        }
    }

    // Determine if the algorithm provides an optimal solution
    auto min_pi0 = std::min_element(resources[0]->Jobs().begin(), resources[0]->Jobs().end(), [](std::shared_ptr<Job> a, std::shared_ptr<Job> b) { return a->ProcT() < b->ProcT(); })->get()->ProcT();
    auto min_pi2 = std::min_element(resources[2]->Jobs().begin(), resources[2]->Jobs().end(), [](std::shared_ptr<Job> a, std::shared_ptr<Job> b) { return a->ProcT() < b->ProcT(); })->get()->ProcT();
    auto max_pi1 = std::max_element(resources[1]->Jobs().begin(), resources[1]->Jobs().end(), [](std::shared_ptr<Job> a, std::shared_ptr<Job> b) { return a->ProcT() < b->ProcT(); })->get()->ProcT();

    if (min_pi0 >= max_pi1 || min_pi2 >= max_pi1)
        return true;

    return false;
}

long Evaluate(std::vector<std::shared_ptr<Resource>> resources)
{
    // Get Cmax with one operation because of Flow Shop
    return resources.back()->Jobs().back()->EndT();
}
