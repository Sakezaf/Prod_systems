#include "main.hpp"

/**
 * Main entry point of the program.
 */
int main(int argc, char const *argv[])
{

    int NJ;
    std::vector<std::unique_ptr<Job>> jobs;
    std::vector<int> s;
    double obj_f[3];

    std::cout << "Demo program for scheduling." << std::endl;
    std::cout << "Please give me the number of jobs: ";
    std::cin >> NJ;

    // Ad-hoc scheduling.
    std::cout << "Ad-hoc scheduling" << std::endl;
    for (int i = 0; i < NJ; i++)
    {
        std::unique_ptr<Job> temp = std::make_unique<Job>();
        temp->id() = i;
        temp->ProcT() = 1 + rand() % 100;
        s.push_back(i);
        jobs.push_back(std::move(temp));
    }

    Simulate(&jobs, &s, 0);
    Evaluate(&jobs, obj_f);
    print_obj_func(obj_f);

    // SPT scheduling.
    std::cout << "SPT scheduling" << std::endl;
    SPT_rule(&jobs, &s);
    Evaluate(&jobs, obj_f);
    print_obj_func(obj_f);

    return 0;
}

void Simulate(std::vector<std::unique_ptr<Job>> *jobs, std::vector<int> *s, long t0)
{
    for (int pos = 0; pos < jobs->size(); pos++)
    {
        if (pos == 0)
            jobs->at(s->at(pos))->StartT() = t0;
        else
            jobs->at(s->at(pos))->StartT() = jobs->at(s->at(pos - 1))->EndT();

        jobs->at(s->at(pos))->EndT() = jobs->at(s->at(pos))->StartT() + jobs->at(s->at(pos))->ProcT();
    }
}

void Evaluate(std::vector<std::unique_ptr<Job>> *jobs, double obj_func[3])
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

    obj_func[0] = Cmax;
    obj_func[1] = Csum;
    obj_func[2] = Na;
}

void print_obj_func(double obj_func[3])
{
    std::cout << "Cmax = " << obj_func[0] << std::endl;
    std::cout << "Csum = " << obj_func[1] << std::endl;
    std::cout << "WIP = " << obj_func[2] << std::endl;
}

void SPT_rule(std::vector<std::unique_ptr<Job>> *jobs, std::vector<int> *s)
{
    // Sort by non-descending ProcT.

    s->clear();

    for (int i = 0; i < jobs->size(); i++)
        s->push_back(i);

    for (int i = 0; i < jobs->size() - 1; i++)
    {
        int index = i;
        for (int j = i + 1; j < jobs->size(); j++)
        {
            if (jobs->at(s->at(index))->ProcT() > jobs->at(s->at(j))->ProcT())
                index = j;
        }

        if (index != i)
        {
            // swap elements.
            std::swap(s->at(index), s->at(i));
        }
    }
}