#include<bits/stdc++.h>
using namespace std;

bool comp(vector<int> a, vector<int> b) {
    return (1.0 * a[0] / a[1]) > (1.0 * b[0] / b[1]);
}

double maxweight(vector<vector<int>>& units, int maxweight) {
    sort(units.begin(), units.end(), comp);
    double ans = 0.0;
    int i = 0;
    while(i < units.size()) {
        if(units[i][1] <= maxweight) {
            maxweight -= units[i][1];
            ans += units[i][0];
        } else {
            ans += (1.0 * units[i][0] / units[i][1]) * maxweight;
            break;
        }
        i++;
    }
    return ans;
}
