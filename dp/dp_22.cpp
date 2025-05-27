#include<bits/stdc++.h>
using namespace std;

int coinchange1(vector<int>arr,int index,int target){
    if(target==0){
        return 1;
    }                         
    if(index==arr.size()){
        return 0;
    }
    int pick=0;
    if(arr[index]<=target){
        pick=coinchange1(arr,index,target-arr[index]);
    }
    int notpick=coinchange1(arr,index+1,target);
    return pick+notpick;
} 

// using memoization
int n=3;
int target=4;
vector<vector<int>>dp(n,vector<int>(target+1,-1));
int coinchange2(vector<int>arr,int index,int target){
    if(target==0){
        return 1;
    }                         
    if(index==arr.size()){
        return 0;
    }
    if(dp[index][target]!=-1){
        return dp[index][target];
    }
    int pick=0;
    if(arr[index]<=target){
        pick=coinchange1(arr,index,target-arr[index]);
    }
    int notpick=coinchange1(arr,index+1,target);
    return dp[index][target]=pick+notpick;
}


int coinchange3(vector<int>& arr, int target) {
    int n = arr.size();
    vector<vector<int>> dp2(n, vector<int>(target + 1, 0));

    // Initialize first row: using only arr[0] to make all targets
    for (int tgt = 0; tgt <= target; tgt++) {
        if (tgt % arr[0] == 0) {
            dp2[0][tgt] = 1;
        }
    }

    // Fill the DP table
    for (int ind = 1; ind < n; ind++) {
        for (int tgt = 0; tgt <= target; tgt++) {
            int nottake = dp2[ind - 1][tgt];
            int take = 0;
            if (arr[ind] <= tgt) {
                take = dp2[ind][tgt - arr[ind]];
            }
            dp2[ind][tgt] = take + nottake;
        }
    }

    return dp2[n - 1][target];
}
int main(){
    vector<int>arr={1,2,3};
    int target=4;
    cout<<coinchange3(arr,target);


}