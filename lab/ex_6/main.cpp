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

    std::vector<std::unique_ptr<Job>> jobs;

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
    jobs.reserve(NJ);

    for (int i = 0; i < NJ; i++)
    {
        std::vector<std::shared_ptr<Task>> tasks;
        tasks.reserve(NR);
        for (int r = 0; r < NR; r++)
        {
            tasks.emplace_back(std::make_shared<Task>(1 + rand() % 100));
        }
        jobs.emplace_back(std::make_unique<Job>(i, std::move(tasks)));
    }

    Simulation_FS(&jobs, 0);
    if (table)
    {
        print_Resource_Gantt(&jobs, NR);
        print_Job_Gantt(&jobs, NR);
    }
    return 0;
}

void print_Job_Gantt(std::vector<std::unique_ptr<Job>> *jobs, int NR)
{
    // jobs
    for (int i = 0; i < jobs->size(); i++)
    {
        std::cout << "job nr." << i << std::endl;
        std::cout << "#\tmachine\tstart\tproc_t\tend" << std::endl;
        // resources
        for (int r = 0; r < NR; r++)
        {
            auto currTask = std::make_shared<Task>(*jobs->at(i)->Tasks().at(r));
            std::cout << r << "\t"
                      << r << "\t"
                      << currTask->StartT() << "\t"
                      << currTask->ProcT() << "\t"
                      << currTask->EndT() << std::endl;
        }
    }
}

void print_Resource_Gantt(std::vector<std::unique_ptr<Job>> *jobs, int NR)
{
    // resources
    for (int r = 0; r < NR; r++)
    {
        std::cout << "resource nr." << r << std::endl;
        std::cout << "#\tjob\tstart\tproc_t\tend" << std::endl;
        // jobs
        for (int i = 0; i < jobs->size(); i++)
        {
            auto currTask = std::make_shared<Task>(*jobs->at(i)->Tasks().at(r));
            std::cout << i << "\t"
                      << jobs->at(i)->id() << "\t"
                      << currTask->StartT() << "\t"
                      << currTask->ProcT() << "\t"
                      << currTask->EndT() << std::endl;
        }
    }
}

void Simulation_FS(std::vector<std::unique_ptr<Job>> *jobs, long t0)
{
    // jobs
    for (int i = 0; i < jobs->size(); i++)
    {
        // resources
        for (int r = 0; r < jobs->at(i)->Tasks().size(); r++)
        {
            // create reference to current task
            auto currTask = std::shared_ptr<Task>(jobs->at(i)->Tasks().at(r));
            // first job
            if (i == 0)
            {
                // first resource
                if (r == 0)
                {
                    currTask->StartT() = t0;
                }
                else
                {
                    currTask->StartT() = jobs->at(i)->Tasks().at(r - 1)->EndT();
                }
            }
            else
            {
                // first resource
                if (r == 0)
                {
                    currTask->StartT() = jobs->at(i - 1)->Tasks().at(r)->EndT();
                }
                else
                {
                    currTask->StartT() = max_l(jobs->at(i)->Tasks().at(r - 1)->EndT(), jobs->at(i - 1)->Tasks().at(r)->EndT());
                }
            }
            // set End time.
            currTask->EndT() = currTask->StartT() + currTask->ProcT();
        }
    }
}
