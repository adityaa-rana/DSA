#include<bits/stdc++.h>
using namespace std;

// minimize the maximum distance between stations by inserting k values
int gastation(vector<int>& station,int k){
    vector<int> inserted(station.size(),0);
    for(int i=0;i<k;i++){
        int maxgap=-1;
        int maxind=-1;
        int j;
        for(j=0;j<station.size()-1;j++){
            int gap=station[j+1]-station[j];
            int modified=gap/inserted[j]+1;
            if(modified>maxgap){
                maxgap=modified;
                maxind=j;
            }
        }
        inserted[j]++;
    }
    int ans=-1;
    for(int i=0;i<station.size()-1;i++){
        int gap=(station[i+1]-station[i])/inserted[i];
        ans=max(ans,gap);
    }
    return ans;
}

// reducing time complexity using heap 
// store gap and index in priority queuemed
int gastation2(vector<int>& station,int k){
    vector<int> inserted(station.size(),0);
    priority_queue<pair<long double,int>>pq;
    for(int i=0;i<station.size();i++){
        pq.push({station[i],i});
    }
    for(int i=0;i<k;i++){
        //popping the largest element (on top of priority queue)
        auto topp=pq.top();
        pq.pop();
        int ind=topp.second;
        inserted[ind]++;
        long double gap=station[ind+1]-station[ind];
        long double modified=gap/(long double)(inserted[ind]+1);
        pq.push({modified,ind});
    }
    return pq.top().first;
}