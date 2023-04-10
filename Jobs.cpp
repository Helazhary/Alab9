#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

struct Job
{
    string name;
    int start_time;
    int end_time;
};

bool compare_time(const Job &job1, const Job &job2)
{
    return job1.end_time < job2.end_time;
}

vector<Job> maximize_jobs(vector<Job> jobs)
{
    vector<Job> sol;
    int prev_end = 0;

    sort(jobs.begin(), jobs.end(), compare_time); // end time sort

    for (int j = 0; j < jobs.size(); j++)
    {
        Job jb = jobs[j];

        if (jb.start_time >= prev_end)
        {
            sol.push_back(jb);
            prev_end = jb.end_time;
        }
    }

    return sol;
}

int main()
{
    vector<Job> ex1 = {
        {"job 1", 22, 30},
        {"job 2", 10, 20},
        {"job 3", 12, 25},

    };
    vector<Job> sol = maximize_jobs(ex1);

    cout << "Max " << sol.size() << " jobs:"
         << "\n";

    for (int i = 0; i < sol.size(); i++)
    {
        Job job = sol[i];
        cout << job.name << " \n";
    }
  cout<<"\n";

    vector<Job> list2 = {
        {"job 1", 1, 2},
        {"job 2", 3, 4},
        {"job 3", 0, 6},
        {"job 4", 5, 7},
        {"job 5", 8, 9},
        {"job 6", 5, 9},
    };

    vector<Job> sol2 = maximize_jobs(list2);
   cout << "Max " << sol.size() << " jobs:"
         << "\n";

    for (int i = 0; i < sol2.size(); i++)
    {
        Job job = sol2[i];
        cout << job.name << " " << endl;
    }
    cout<<"\n";
}