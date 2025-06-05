#include<bits/stdc++.h>
using namespace std;

// approach 1 : using recursion
int findmin(vector<int>& arr,int index,int jumps){
    if(index==arr.size()-1){
        return jumps;
    }
    int mini=INT_MAX;
    for(int i=1;i<=arr[index];i++){
        mini=min(mini,findmin(arr,index+i,jumps+1));
    }
    return mini;

}
int minjumps(vector<int>& arr){
    int jumps=0;
    int index=0;
    int ans=findmin(arr,index,jumps);
    return ans;
}

// approach 2 : use dp 
class Solution {
public:

    int findmin(vector<int>& arr,int index,int jumps,vector<vector<int>>&dp){
        if(index>=arr.size()-1){
            return jumps;
        }
        if(dp[index][jumps]!=-1){
            return dp[index][jumps];
        }
        int mini=INT_MAX;
        for(int i=1;i<=arr[index];i++){
            mini=min(mini,findmin(arr,index+i,jumps+1,dp));
        }
        return dp[index][jumps]=mini;

    }
    int jump(vector<int>& nums) {
        int jumps=0;
        int index=0;
        vector<vector<int>>dp(nums.size(),vector<int>(nums.size(),-1));
        int ans=findmin(nums,index,jumps,dp);
        return ans;
    }
};


// optimum approachx
class Solution {
public:
    int jump(vector<int>& nums) {
        int l=0;
        int r=0;
        int jumps=0;
        while(r<nums.size()-1){
            int farthest=0;
            for(int i=l;i<=r;i++){
                farthest=max(farthest,i+nums[i]);
            }
            l=r+1;
            r=farthest;
            jumps++;
        }
        return jumps;
    }
};