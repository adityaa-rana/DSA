#include<bits/stdc++.h>
using namespace std;

typedef struct meet{
    int start;
    int end;
    int pos;
}meet;

bool comp(meet m1,meet m2){
    return m1.end < m2.end;
}

vector<int>order(vector<meet>& m){
    sort(m.begin(),m.end(),comp);
    vector<int>timeline;
    int totalmeets=0;
    int time=-1;
    for(int i=0;i<m.size();i++){
        if(m[i].start > time){
            timeline.push_back(m[i].pos);
            totalmeets++;
            time=m[i].end;
        }
    }
    return timeline;
}
