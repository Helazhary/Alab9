#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Job
{
    int start_time;
    int end_time;
};

void swap(Job *a, Job *b)
{

    Job temp = *a;

    *a = *b;

    *b = temp;
}
void heapify(vector<Job> arr, int N, int i)
{

    int largest = i;

    int left = 2 * i + 1;

    int right = 2 * i + 2;

    if (left < N && arr[left].end_time > arr[largest].end_time)

        largest = left;

    if (right < N && arr[right].end_time > arr[largest].end_time)

        largest = right;

    if (largest != i)
    {

        swap(&arr[i], &arr[largest]);

        heapify(arr, N, largest);
    }
}

void heapSort(vector<Job> arr, int N)
{

    for (int i = N / 2 - 1; i >= 0; i--)

        heapify(arr, N, i);

    for (int i = N - 1; i >= 0; i--)
    {

        swap(&arr[0], &arr[i]);

        heapify(arr, i, 0);
    }
}

vector<Job> maximize_jobs(vector<Job> jobs)
{
    heapSort(jobs, jobs.size());
    vector<Job> sol;
    sol.push_back(jobs[0]);

    for (int i = 1; i < jobs.size(); i++)
    {
        if (sol[sol.size() - 1].end_time <= jobs[i].start_time)
        {
            sol.push_back(jobs[i]);
        }
    }
    return sol;
}

int main()
{
    vector<Job> jobs{
        {10, 20},
        {22, 30},
        {12, 25}};

    cout << " Example 1: \n";
    vector<Job> solution_set = maximize_jobs(jobs);
     for (int j = 0; j < solution_set.size(); j++)
    {
        cout << " from " << solution_set[j].start_time << " to " << solution_set[j].end_time << endl;
    }


    vector<Job> jobs2 = {
        {1, 2},
        {3, 4},
        {0, 6},
        {5, 7},
        {8, 9},
        {5, 9}};

    cout << "\n\n Example 2: \n";
    vector<Job> solution_set2 = maximize_jobs(jobs2);
    for (int j = 0; j < solution_set2.size(); j++)
    {
        cout << " from " << solution_set2[j].start_time << " to " << solution_set2[j].end_time << endl;
    }

    return 0;
}
