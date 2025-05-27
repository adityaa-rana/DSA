#include<bits/stdc++.h>
using namespace std;

int infinteknap(vector<int>weight,vector<int>value,int index,int bagsize){
    if(index==0){   
        if(weight[index]<=bagsize){
            return value[index]*(bagsize/weight[0]);
        }
        else{
            return INT_MIN;
        }
    }
    
    int pick=INT_MIN;
    if(weight[index]<bagsize){
        pick=value[index]+infinteknap(weight,value,index,bagsize-weight[index]);
    }
    int notpick=0+infinteknap(weight,value,index-1,bagsize);
    return max(pick,notpick);
}

// USING MEMOIZATIOn
int n=3;
int bagsize=10;
vector<vector<int>>dp(n,vector<int>(bagsize+1,-1));
int infinteknap2(vector<int>weight,vector<int>value,int index,int bagsize){
    if(index==0){   
        if(weight[index]<=bagsize){
            return value[index]*(bagsize/weight[0]);
        }
        else{
            return INT_MIN;
        }
    }
    if(dp[index][bagsize]!=-1){
        return dp[index][bagsize];
    }
    int pick=INT_MIN;
    if(weight[index]<bagsize){
        pick=value[index]+infinteknap2(weight,value,index,bagsize-weight[index]);
    }
    int notpick=0+infinteknap2(weight,value,index-1,bagsize);
    return dp[index][bagsize]=max(pick,notpick);
}



int infinteknap3(vector<int>weight,vector<int>value,int bagsize){
    int n = weight.size();
    vector<vector<int>>dp2(n,vector<int>(bagsize+1,0));
    for(int w=0;w<=bagsize;w++){
        dp2[0][w]=(w/weight[0])*value[0];
    }
    for(int ind=1;ind<n;ind++){
        for(int wt=0;wt<=bagsize;wt++){
            int notpick=0+dp2[ind-1][wt];
            int pick=INT_MIN;
            if(weight[ind]<=wt) {
                pick=value[ind]+dp2[ind][wt-weight[ind]];
            }
            dp2[ind][wt]=max(pick,notpick);
        }
    }
    return dp2[n-1][bagsize];
}


// 2row optimization
int infinteknap4(vector<int>weight,vector<int>value,int bagsize){
    int n = weight.size();
    vector<int>prev(bagsize+1,0);
    vector<int>curr(bagsize+1,0);
    for(int w=0;w<=bagsize;w++){
        prev[w]=(w/weight[0])*value[0];
    }
    for(int ind=1;ind<n;ind++){
        for(int wt=0;wt<=bagsize;wt++){
            int notpick=0+prev[wt];
            int pick=INT_MIN;
            if(weight[ind]<=wt) {
                pick=value[ind]+curr[wt-weight[ind]];
            }
            curr[wt]=max(pick,notpick);
        }
        prev=curr;
    }
    return prev[bagsize];
}

int main(){
    vector<int>weight={2,4,6};
    vector<int>value={5,11,13};
    cout<<infinteknap4(weight,value,10);
    return 0;
}