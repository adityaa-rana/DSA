#include<bits/stdc++.h>
using namespace std;

int mincoins1(int index,vector<int>values,int target){

    // at the end we have to take all the values of this last remaining coin only
    // if it is possible then number of values of the last coin are returned to be added to total coins
    // otherwise a large value is returned so that this answer is not considered
    if(index==0){
        if(target%values[index]==0){
            return target/values[index];
        }
        else{
            return 1e9;
        }
    }

    int notpick=0+mincoins1(index-1,values,target);
    int pick=1e9;

    // note we can take multiple values of same coin, don't go back in index, stay at same index 
    // it won't go in infinte because index it won't be taken when values[index]>target as target is decreasing with each take
    if(values[index]<=target){
        pick=1+mincoins1(index,values,target-values[index]);
    }
    return min(pick,notpick);
}

//using memoizarion
int n=4;
int target=11;
vector<vector<int>>dp(n,vector<int>(target+1,-1));
int mincoins2(vector<int>values,int index,int target){
    if(index==0){
        if(target%values[index]==0){
            return target/values[index];
        }
        else{
            return 1e9;
        }
    }
    if(dp[index][target]!=-1){
        return dp[index][target];
    }

    int notpick=0+mincoins2(values,index-1,target);
    int pick=1e9;
    if(values[index]<=target){
        pick=mincoins2(values,index,target-values[index])+1;
    }
    return dp[index][target]=min(pick,notpick);
}

//using tabulation
vector<vector<int>>dp2(n,vector<int>(target+1,0));
int mincoins3(vector<int>values){
    for(int i=0;i<target;i++){
        if(target%values[0]==0){
            dp2[0][i]=target/values[0];
        }
        else{
            dp2[0][i]=1e9;
        }
    }

    for(int ind=0;ind<values.size();ind++){
        for(int tgt=0;tgt<=target;tgt++){
            int notpick=0+dp2[ind-1][tgt];
            int pick=1e9;
            if(values[ind]<=tgt){
                pick=1+dp2[ind][tgt-values[ind]];
            }
            dp2[ind][tgt]=min(pick,notpick);
        }
    }
    return dp2[values.size()-1][target];
}
int main(){
    vector<int>values={9,6,5,1};
    int target=11;
    cout<<mincoins3(values);
}

