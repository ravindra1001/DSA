#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Job{
    public:
    char id;
    int deadline;
    int profit;
    Job(char id, int deadline, int profit){
        this->id = id;
        this->deadline = deadline;
        this->profit = profit;
    }
};

class Comp{
    public:
    bool operator()(const Job & a, const Job & b){
        return a.profit > b.profit;
    }
};

void schedule_job(vector<Job> jobs){
    sort(jobs.begin(),jobs.end(),Comp());
    int n = jobs.size();
    vector<int>result(n,-1);

    for(int i=0;i<n;i++){
        //cout<<jobs[i].profit<<endl;
        for(int j = min(n, jobs[i].deadline)-1; j>=0; j--){
            if(result[j] == -1){
                result[j] = i;
                break;
            }
        }
    }

    

    for(int i=0;i<n;i++){
        if(result[i] != -1){
            cout<<jobs[result[i]].id<<endl;
        }
    }

}

int main(){
    vector<Job> jobs;
    jobs.push_back(*(new Job('a', 2, 100)));
    jobs.push_back(*(new Job('b', 1, 19)));
    jobs.push_back(*(new Job('d', 1, 25)));
    jobs.push_back(*(new Job('e', 3, 15)));
    jobs.push_back(*(new Job('c', 2, 27)));

    schedule_job(jobs);
    return 0;
}