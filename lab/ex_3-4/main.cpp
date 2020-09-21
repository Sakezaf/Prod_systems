#include "main.hpp"

/**
 * Main entry point of the program.
 */
int main(int argc, char const *argv[])
{

    int NJ;
    bool table = false;
    std::vector<std::unique_ptr<Job>> jobs;
    std::array<double, 4> obj_f;

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
    jobs.reserve(NJ);

    // Ad-hoc scheduling.
    std::cout << "\nAd-hoc scheduling" << std::endl;
    for (int i = 0; i < NJ; i++)
    {
        jobs.emplace_back(std::make_unique<Job>(i, 1 + rand() % 100, 1 + (NJ - i) * 5 + rand() % 50));
    }

    Simulate(&jobs, 0);
    obj_f = Evaluate(&jobs);
    print_obj_func(obj_f);
    if (table)
        print_jobs(&jobs);

    // SPT scheduling.
    std::cout << "\nSPT scheduling" << std::endl;
    SPT_rule(&jobs);
    Simulate(&jobs, 0);
    obj_f = Evaluate(&jobs);
    print_obj_func(obj_f);
    if (table)
        print_jobs(&jobs);

    // EDD scheduling.
    std::cout << "\nEDD scheduling" << std::endl;
    EDD_rule(&jobs);
    Simulate(&jobs, 0);
    obj_f = Evaluate(&jobs);
    print_obj_func(obj_f);
    if (table)
        print_jobs(&jobs);

    return 0;
}

void EDD_rule(std::vector<std::unique_ptr<Job>> *jobs)
{
    // Sort by non-descending Due date.
    std::sort(jobs->begin(), jobs->end(), [](const std::unique_ptr<Job> &a, const std::unique_ptr<Job> &b) {
        return a->Due() < b->Due();
    });
}

void Simulate(std::vector<std::unique_ptr<Job>> *jobs, long t0)
{
    for (std::vector<std::unique_ptr<Job>>::iterator job = jobs->begin(); job != jobs->end(); job++)
    {
        if (std::distance(jobs->begin(), job) == 0)
            job->get()->StartT() = t0;
        else
            job->get()->StartT() = jobs->at(std::distance(jobs->begin(), job) - 1)->EndT();

        job->get()->EndT() = job->get()->StartT() + job->get()->ProcT();
    }
}

std::array<double, 4> Evaluate(std::vector<std::unique_ptr<Job>> *jobs)
{
    double Na;
    double Cmax;
    double Csum = 0;
    double Lmax;

    for (int i = 0; i < jobs->size(); i++)
    {
        Csum += jobs->at(i)->EndT();

        if (i == 0)
            Cmax = jobs->at(i)->EndT();
        else if (Cmax < jobs->at(i)->EndT())
            Cmax = jobs->at(i)->EndT();

        jobs->at(i)->Lateness() = jobs->at(i)->EndT() - jobs->at(i)->Due();

        if (i == 0)
            Lmax = jobs->at(i)->Lateness();
        else if (Lmax < jobs->at(i)->Lateness())
            Lmax = jobs->at(i)->Lateness();
    }

    Na = Csum / Cmax;

    std::array<double, 4> obj_func = {Cmax, Csum, Na, Lmax};
    return obj_func;
}

void print_obj_func(std::array<double, 4> obj_func)
{
    std::cout << "Cmax = " << obj_func[0] << std::endl;
    std::cout << "Csum = " << obj_func[1] << std::endl;
    std::cout << "WIP = " << obj_func[2] << std::endl;
    std::cout << "Lmax = " << obj_func[3] << std::endl;
}

void SPT_rule(std::vector<std::unique_ptr<Job>> *jobs)
{
    // Sort by non-descending ProcT.
    std::sort(jobs->begin(), jobs->end(), [](const std::unique_ptr<Job> &a, const std::unique_ptr<Job> &b) {
        return a->ProcT() < b->ProcT();
    });
}

void print_jobs(std::vector<std::unique_ptr<Job>> *jobs)
{
    std::cout << "\n#\tid\tstart\ttime\tend\tdue\tlateness" << std::endl;
    for (std::vector<std::unique_ptr<Job>>::iterator job = jobs->begin(); job != jobs->end(); job++)
    {
        std::cout << std::distance(jobs->begin(), job) + 1 << "\t"
                  << job->get()->id() << "\t"
                  << job->get()->StartT() << "\t"
                  << job->get()->ProcT() << "\t"
                  << job->get()->EndT() << "\t"
                  << job->get()->Due() << "\t"
                  << job->get()->Lateness() << std::endl;
    }
}