#include<bits/stdc++.h>
using namespace std;

// DP_19 KNAPSNACK
int maxvalue1(int index,int vsum,vector<int>weight,vector<int>value,int n,int bag){
    if(index<0){
        if(bag>=0){
            return vsum; 
        }
        else{
            return INT_MIN;
        }
    }
    int notpick=maxvalue1(index-1,vsum,weight,value,n,bag);
    int pick=maxvalue1(index-1,vsum+value[index],weight,value,n,bag-weight[index]);
    return max(pick,notpick);
}


// little optimization
int maxvalue2(int index,int vsum,vector<int>weight,vector<int>value,int n,int bag){
    if(index<0){
        return vsum;
    }
    int notpick=maxvalue2(index-1,vsum,weight,value,n,bag);
    int pick=0;
    if(bag-weight[index]>=0){
        pick=maxvalue2(index-1,vsum+value[index],weight,value,n,bag-weight[index]);
    }
    
    return max(pick,notpick);
}


// changing from 3 changing parameters to 2 changing parameters
int maxvalue3(int index,vector<int>weight,vector<int>value,int n,int bag){
    if(index==0){
        if(bag-weight[index]>=0){
            return value[index];
        }
        else{
            return 0;
        }
    }
    int notpick=maxvalue3(index-1,weight,value,n,bag);
    int pick=0;
    if(bag-weight[index]>=0){
        pick=maxvalue3(index-1,weight,value,n,bag-weight[index])+value[index];
    }
    
    return max(pick,notpick);
}


// memoization
int n=3;
int bagsize=8;
vector<vector<int>>dp(n,vector<int>(bagsize+1,-1));
int maxvalue4(int index,vector<int>weight,vector<int>value,int n,int bag){
    if(index==0){
        if(bag-weight[index]>=0){
            return value[index];
        }
        else{
            return 0;
        }
    }
    if(dp[index][bag]!=-1){
        return dp[bag][index];
    }
    int notpick=maxvalue4(index-1,weight,value,n,bag);
    int pick=0;
    if(bag-weight[index]>=0){
        pick=maxvalue4(index-1,weight,value,n,bag-weight[index])+value[index];
    }
    
    return dp[index][bag]=max(pick,notpick);
}

vector<vector<int>>dp2(n,vector<int>(bagsize+1,0));
int maxvalue5(vector<int>weight,vector<int>value,int n,int bagsize){
    for(int j=weight[0];j<=bagsize;j++){
        dp2[0][j]=value[0];
    }
    // rest of the values in row 1 (index 1) ie from j=0 to j<weight[0]  are 0 because they have bagsize even smaller than first weight
    for(int i=1;i<n;i++){  // i denotes current index
        for(int j=0;j<=bagsize;j++){    // j denotes current bagsize
            int notpick=dp2[i-1][j]+0;
            int pick=0;
            if(weight[i]<=j){
                pick=dp2[i-1][j-weight[i]]+value[i];
            }

            dp2[i][j]=max(pick,notpick);
            
        }
    }
    return dp2[n-1][bagsize];
}

int maxvalue6(vector<int>weight,vector<int>value,int n,int bagsize){

    vector<int>prev(bagsize+1,0);
    vector<int>curr(bagsize+1,0);
    for(int j=weight[0];j<=bagsize;j++){
        prev[j]=value[0];
    }

    for(int ind=1;ind<n;ind++){  // i denotes current index
        for(int wght=0;wght<=bagsize;wght++){    // j denotes current bagsize
            int notpick=prev[wght]+0;
            int pick=0;
            if(weight[ind]<=wght){
                pick=prev[wght-weight[ind]]+value[ind];
            }

            curr[wght]=max(pick,notpick);
            
        }
        prev=curr;
    }
    return prev[bagsize];
}
int main(){
    vector<int>value={30,50,60};
    vector<int>weight={3,4,5};
    int n=3;
    int bag=8;
    cout<<maxvalue6(weight,value,n,bag);
    return 0;
}