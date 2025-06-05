#include<bits/stdc++.h>
using namespace std;


typedef struct room{
    long long freetime;
    int count;
    room(){
        freetime=-1;
        count=0;
    }
}room;
bool compareByFirstElement(const vector<int>& a, const vector<int>& b) {
    return a[0] < b[0];
}
class Solution {
public:
    
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end(), compareByFirstElement);
        vector<room>rooms(n);
        for(int i=0;i<meetings.size();i++){
            int minfree=INT_MAX;
            int minfreeindex=-1;
            int j;
            for(j=0;j<n;j++){
                if(rooms[j].freetime < minfree){
                    minfree=rooms[j].freetime;
                    minfreeindex=j;
                }
                if(rooms[j].freetime <= meetings[i][0]){
                    if(rooms[j].freetime==-1){
                        rooms[j].freetime=meetings[i][1];
                    }
                    else if(rooms[j].freetime < meetings[i][0]){
                        rooms[j].freetime=meetings[i][1];
                    }
                    else{
                        rooms[j].freetime+=(long long)(meetings[i][1]-meetings[i][0]);
                    }
                    rooms[j].count++;
                    break;
                }
            }
            if(j==n && minfreeindex != -1){

                if(rooms[minfreeindex].freetime < meetings[i][0]){
                    rooms[minfreeindex].freetime=meetings[i][1];
                }
                else{
                    rooms[minfreeindex].freetime+=(long long)(meetings[i][1]-meetings[i][0]);
                }
                rooms[minfreeindex].count++;
            }
        }
        int ans=-1;
        int max=0;
        for(int i=0;i<rooms.size();i++){
            if(rooms[i].count>max){
                max=rooms[i].count;
                ans=i;
            }
        }
        return ans;
    }
};