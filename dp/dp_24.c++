#include<bits/stdc++.h>
using namespace std;

int rodpieces(vector<int>arr,int index,int lenallowed){
    if(index==0){
        return lenallowed*arr[0];
    }

    
    int pick=INT_MIN;
    if(lenallowed>=index+1){
        pick=arr[index]+rodpieces(arr,index,lenallowed-(index+1));
    }
    int notpick=rodpieces(arr,index-1,lenallowed);
    return max(pick,notpick);
}

// memoization
int n=5;
int lenallowed=5;
vector<vector<int>>dp(n,vector<int>(lenallowed+1,-1));
int rodpieces2(vector<int>arr,int index,int lenallowed){
    if(index==0){
        return lenallowed*arr[0];
    }
    if(dp[index][lenallowed]!=-1){
        return dp[index][lenallowed];
    }
    
    int pick=INT_MIN;
    if(lenallowed>=index+1){
        pick=arr[index]+rodpieces2(arr,index,lenallowed-(index+1));
    }
    int notpick=rodpieces2(arr,index-1,lenallowed);
    return dp[index][lenallowed]=max(pick,notpick);
}


// tabulation
int rodpieces3(vector<int>arr,int lenallowed){
    vector<vector<int>>dp(n,vector<int>(lenallowed+1,0));
    for(int lenallow=0;lenallow<=lenallowed;lenallow++){
        dp[0][lenallow]=lenallow*arr[0];
    }
    for(int ind=1;ind<arr.size();ind++){
        for(int lenallow=0;lenallow<=lenallowed;lenallow++){
            int nottake=0+dp[ind-1][lenallow];
            int take=INT_MIN;
            if(lenallow>=ind+1){
                take=arr[ind]+dp[ind][lenallow-(ind+1)];
            }
            dp[ind][lenallow]=max(take,nottake);
        }
    }
    return dp[arr.size()-1][lenallowed];
}
int main(){
    vector<int>arr={2,5,7,8,10};
    int lenallowed=5;
    cout<<rodpieces3(arr,lenallowed);
}