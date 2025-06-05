
#include <bits/stdc++.h>
using namespace std;

typedef struct job {
    int id;
    int deadline;
    int profit;
} job;

bool comp(job j1, job j2) {
    return j1.profit > j2.profit;
}

int maxprofit(vector<job>& jobs) {
    sort(jobs.begin(), jobs.end(), comp);

    int maxdeadline = 0;
    for (int i = 0; i < jobs.size(); i++) {
        maxdeadline = max(maxdeadline, jobs[i].deadline);
    }

    vector<int> slot(maxdeadline + 1, -1); // slots from 1 to maxdeadline
    int totalprofit = 0;

    for (int i = 0; i < jobs.size(); i++) {
        // Try to find a free slot from jobs[i].deadline to 1
        for (int d = jobs[i].deadline; d > 0; d--) {
            if (slot[d] == -1) {
                slot[d] = jobs[i].id;
                totalprofit += jobs[i].profit;
                break;
            }
        }
    }

    return totalprofit;
}
