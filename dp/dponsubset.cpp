#include<bits/stdc++.h>
using namespace std;

// subset with sum k in arrayt - return true or false
// approach : recursion method of PICK AND NOT PICK


// method 1: bottom up recursion
// bool sumk(int index,vector<int> subset,int sum,vector<int>arr,int k){
//     if(sum==k){
//         return true;
//     }
//     if(index==arr.size()){
//         return false;
//     }
//     if(sum>k){
//         return false;
//     }
   
//     //pick
//     subset.push_back(arr[index]);
//     sum+=arr[index];
//     int pick=sumk(index+1,subset,sum,arr,k);
    
//     subset.pop_back();
//     sum-=arr[index];
//     int notpick=sumk(index+1,subset,sum,arr,k);   
//     return (pick||notpick);
// }


// bool sumk2(int index,vector<int>arr,int target){
//     if(target==0){
//         return true;
//     }
//     if(index<0){
//         return false;
//     }
//     if(target<0){
//         return false;
//     }
//     target-=arr[index];
//     bool pick=sumk2(index-1,arr,target);

//     target+=arr[index];
//     bool notpick=sumk2(index-1,arr,target);

//     return (pick||notpick);
// }
// //other way of writing the same code

// bool sumk3(int index,vector<int>arr,int target){
//     if(target==0){
//         return true;
//     }
//     if(index<0){
//         return false;
//     }

//     bool notpick=sumk3(index-1,arr,target);
//     bool pick=false;
//     if(target>arr[index]){
//         pick=sumk3(index-1,arr,target-arr[index]);
//     }

//     return (pick||notpick);
// }
// //using memoization
// int n=4;
// int target=7;
// vector<vector<int>>dp(n,vector<int>(target,-1));
// bool sumk4(int index,vector<int>arr,int target){
//     if(target==0){
//         return true;
//     }
//     if(index<0){
//         return false;
//     }
//     if(dp[index][target]!=-1){
//         return dp[index][target];
//     }
//     bool notpick=sumk3(index-1,arr,target);
//     bool pick=false;
//     if(target>arr[index]){
//         pick=sumk3(index-1,arr,target-arr[index]);
//     }

//     return dp[index][target]=(pick||notpick);
// }

// //tabulation
// int n=4;
// int target=7;
// vector<vector<int>>dp(n,vector<int>(target,0));
// bool sumk5(vector<int>arr,int k){
//     //case when target becomes zero for any index
//     for(int ind=0;ind<n;ind++){
//         dp[ind][0]=1;
//     }

//     //case when index becomes zero and target is equal to arr[0]
//     if(arr[0]<=target){
//         dp[0][arr[0]]=1;
//     }
    

//     for(int ind=1;ind<n;ind++){
//         for(int target=1;target<=k;target++){
//             bool nottake=dp[ind-1][target];
//             bool take=false;
//             if(arr[ind]<=target){
//                 take=dp[ind-1][target-arr[ind]];
//             }
//             dp[ind][target]=(take||nottake);
//         }
//     }
//     return dp[n-1][k];
// }

// int main(){
//     vector<int>arr={2,3,6,7};
//     vector<int>subset;
//     cout<<sumk5(arr,7);
//     return 0;
// }


// partition into two subsets of equal sum

// bool partition(int index,int acc,vector<int>arr,int totalsum,vector<int>subset){
//     if(acc==totalsum/2){
//         return true;
//     }    
//     if(acc>totalsum/2 || index==arr.size()){
//         return false;
//     }
//     subset.push_back(arr[index]);
//     int pick=partition(index+1,acc+arr[index],arr,totalsum,subset);
//     subset.pop_back();
//     int notpick=partition(index+1,acc,arr,totalsum,subset);
//     return (pick||notpick);
// }

// int main(){
//     vector<int>subset;
//     vector<int>arr={2,3,3,3,4,5};
//     int ans=partition(0,0,arr,10,subset);
//     printf("\n");
//     cout<<ans;
//     return 0;
// }

// dp-16 : partition array into 2 subsets with minimum difference of their sums
// int mindiff(vector<int>arr,int index,int sum1,int totalsum,int mindif){
//     if(index==arr.size()){
//         int diff=(totalsum-sum1)-sum1>0?(totalsum-sum1)-sum1:(-1)*((totalsum-sum1)-sum1);
//         return min(diff,mindif);
//     }
//     //pick case

//     int pick=mindiff(arr,index+1,sum1+arr[index],totalsum,mindif);
//     int notpick=mindiff(arr,index+1,sum1,totalsum,mindif);
//     return mindif=min(pick,notpick);
// }

// int mindiff(vector<int>arr,int n){
//     int totalsum=0;
//     for(int i=0;i<n;i++){
//         totalsum+=arr[i];
//     }
//     int k=totalsum;
//     vector<vector<int>>dp(n,vector<int>(n,-1));
//     for(int i=0;i<n;i++){
//         dp[i][0]=true;
//     }
//     if(arr[0]<k){
//         dp[0][arr[0]]=true;
//     }
//     for(int ind=1;ind<n;ind++){
//         for(int target=1;target<k;target++){
//             bool nottake=dp[ind-1][target];
//             bool take=false;
//             if(arr[ind]<=target){
//                 take=dp[ind-1][target-arr[ind]];
//                 dp[ind][target]=take||nottake;
//             }
//         }
//     }
//     int mini=INT_MIN;
//     //here i denoted running target sum 
//     for(int i=0;i<totalsum/2;i++){
//         if(dp[n-1][i]==true){
//             mini=min(mini,abs((totalsum)-i)-i);
//         }
//     }
// }
// int main(){
//     vector<int>arr={3,2,7};
//     cout<<mindiff(arr,0,0,12,INT_MAX);
//     return 0;
// }

//count no. of subsets with sum equal to k
// vector ds is not necessary

//bottom up approach

// vector<int>arr={1,2,2,3};
// int n=arr.size();
// int countsubsets(int index,vector<int>ds,int sum,int target){
//     //base case
//     if(index==n){
//         if(sum==target){
//             // for(int i=0;i<ds.size();i++){
//             //     cout<<ds[i]<<"\t";
//             // }
//             // cout<<endl;
//             return 1;
//         }
//         else{
//             return 0;
//         }
//     }
//     ds.push_back(arr[index]);
//     sum+=arr[index];
//     int pick=countsubsets(index+1,ds,sum,target);

//     ds.pop_back();
//     sum-=arr[index];
//     int notpick=countsubsets(index+1,ds,sum,target);

//     return pick+notpick;
// }

// int main(){
//     vector<int>ds;
//     cout<<countsubsets(0,ds,0,3);
//     return 0;
// }


//top down approach

// vector<int>arr={1,2,2,3};
// int n=arr.size();
// int countsubsets(int index,vector<int>ds,int sum,int target){
//     //base case
//     if(index<0){
//         if(sum==target){
//             // for(int i=0;i<ds.size();i++){
//             //     cout<<ds[i]<<"\t";
//             // }
//             // cout<<endl;
//             return 1;
//         }
//         else{
//             return 0;
//         }
//     }
//     ds.push_back(arr[index]);
//     sum+=arr[index];
//     int pick=countsubsets(index-1,ds,sum,target);

//     ds.pop_back();
//     sum-=arr[index];
//     int notpick=countsubsets(index-1,ds,sum,target);

//     return pick+notpick;
// }

// int main(){
//     vector<int>ds;
//     cout<<countsubsets(n-1,ds,0,3);
//     return 0;
// }

//using memoization

// vector<int>arr={1,2,2,3};
// int totalsum=8;
// int n=arr.size();
// vector<vector<int>>dp(n,vector<int>(totalsum,-1));
// int countsubsets(int index,int sum,int target){
//     //base case
//     if(index<0){
//         if(sum==target){
//             return 1;
//         }
//         else{
//             return 0;
//         }
//     }
//     if(dp[index][sum]!=-1){
//         return dp[index][sum];
//     }
//     sum+=arr[index];
//     int pick=countsubsets(index-1,sum,target);

//     sum-=arr[index];
//     int notpick=countsubsets(index-1,sum,target);

//     return dp[index][sum]=pick+notpick;
// }

// int main(){
//     cout<<countsubsets(n-1,0,3);
//     return 0;
// }


// vector<int>arr={1,2,2,3};
// int totalsum=8;
// int n=arr.size();
// vector<vector<int>>dp(n,vector<int>(totalsum,-1));
// int countsubsets(int index,int target){
//     //base case
//     if(index<0){
//         if(target==0){
//             return 1;
//         }
//         else{
//             return 0;
//         }
//     }
//     if(dp[index][target]!=-1){
//         return dp[index][target];
//     }
//     int pick=0;
//     if(target>=arr[index]){
//         pick=countsubsets(index-1,target-arr[index]);
//     }
//     int notpick=countsubsets(index-1,target);

//     return dp[index][target]=pick+notpick;
// }

// int main(){
//     cout<<countsubsets(n-1,3);
//     return 0;
// }


//using tabulation
// vector<int>arr={1,2,2,3};
// int totalsum=8;
// int n=arr.size();
// vector<vector<int>>dp(n,vector<int>(totalsum+1,0));

// int countsubsets(int k){

//     //cases for all index when target =0
//     for(int i=0;i<n;i++){
//         dp[i][0]=1;
//     }
//      //at index =0 , only return 1 if the first element is itself equal to target
//     if(arr[0]<=k){
//         dp[0][arr[0]]=1;
//     }
    

//     for(int ind=1;ind<n;ind++){
//         for(int target=0;target<=k;target++){
//             int notpick=dp[ind-1][target];
//             int pick=0;
//             if(target>=arr[ind]){
//                 pick=dp[ind-1][target-arr[ind]];
//             }

//             dp[ind][target]=pick+notpick;
//         }
//     }
//     return dp[n-1][k];
// }

// // int main(){
// //     cout<<countsubsets(3);
// //     return 0;
// // }

// //subset with sum k

// int countsumk(int index,int sum,vector<int>arr,int target){
//     if(index==arr.size()){
//         if(sum==target){
//             return 1;
//         }
//         else{
//             return 0;
//         }
//     }
//     sum+=arr[index];
//     int pick=countsumk(index+1,sum,arr,target);
//     sum-=arr[index];
//     int notpick=countsumk(index+1,sum,arr,target);

//     return pick+notpick;
// }


// little optimization with top-down approach , the above one was bottom up

// int countsumk2(int index, int sum, vector<int>& arr, int target){
//     if(index < 0){
//         if(sum == target){
//             return 1;
//         }
//         return 0;
//     }
//     int pick = 0;
//     if(arr[index] <= (target - sum)){
//         pick = countsumk2(index - 1, sum + arr[index], arr, target);
//     }
//     int notpick = countsumk2(index - 1, sum, arr, target);

//     return pick + notpick;
// }

// int main(){
//     vector<int> arr = {0,0,1};
//     cout << countsumk2(arr.size() - 1, 0, arr, 1);
//     return 0;
// }


count partitions with given difference
int countdiff(int index,int sum,vector<int>arr,int diff,int total){
    if(index==arr.size()){
        if(sum-(total-sum)==diff){
            return 1;
        }
        else{
            return 0;
        }
    }
    int pick=countdiff(index+1,sum+arr[index],arr,diff,total);
    int notpick=countdiff(index+1,sum,arr,diff,total);
    return pick+notpick;
}

memoization
int totalsum=17;
int n=4;
vector<vector<int>>dp(n,vector<int>(totalsum+1,-1));
int countdiff(int index,int sum,vector<int>arr,int diff,int total){
    if(index==arr.size()){
        if(sum-(total-sum)==diff){
            return 1;
        }
        else{
            return 0;
        }
    }
    if(dp[index][sum]!=-1){
        return dp[index][sum];
    }
    int pick=countdiff(index+1,sum+arr[index],arr,diff,total);
    int notpick=countdiff(index+1,sum,arr,diff,total);
    return dp[index][sum]=pick+notpick;
}

// 0/1 knapsack DP-19
int n=3;
int knapsack(int index,int wsum,int vsum,vector<int>weight,vector<int>value,int bag){
    if(index==n){
        if(wsum<=bag){
            return vsum;
        }
        else{
            return 0;
        }
    }
    int pick=INT_MIN;
    if(wsum+weight[index]<=bag)
        pick=knapsack(index+1,wsum+weight[index],vsum+value[index],weight,value,bag);
    int notpick=knapsack(index+1,wsum,vsum,weight,value,bag);
    return max(pick,notpick);
}
// TOP DOWN
int bag=8;
int knapsack2(int index,int vsum,vector<int>weight,vector<int>value,int bag){
    if(index==0){
        if(bag>=weight[index]){
            return value[index];
        }
        else{
            return 0;
        }
    }

    int pick=INT_MIN;
    if(weight[index]<=bag){
        pick=knapsack2(index-1,vsum+value[index],weight,value ,bag-weight[index]);
    }
    int notpick=knapsack2(index-1,vsum,weight,value ,bag);
    return vsum+max(pick,notpick);
}

//using memoization
int bagsize=8;
vector<vector<int>>dp(n,vector<int>(bagsize+1,-1));

int knapsack3(int index,int vsum,vector<int>weight,vector<int>value,int bag){
    if(index==0){
        if(bag>=weight[index]){
            return value[index];
        }
        else{
            return 0;
        }
    }
    if(dp[index][bag]!=-1){
        return dp[index][bag];
    }
    int pick=INT_MIN;
    if(weight[index]<=bag){
        pick=knapsack2(index-1,vsum+value[index],weight,value ,bag-weight[index]);
    }
    int notpick=knapsack2(index-1,vsum,weight,value ,bag);
    return dp[index][bag]=vsum+max(pick,notpick);
}

// tabulation
vector<vector<int>>dpt(n,vector<int>(bagsize+1,0));
int knapsack4(vector<int>weight,vector<int>value,int bag){
    for(int i=0;i<weight[0];i++){
        dpt[0][i]=0;
    }
    for(int i=weight[0];i<=bag;i++){
        dpt[0][i]=value[0];
    }

    for(int ind=1;ind<n;ind++){
        for(int wt=0;wt<=bag;wt++){
            int notpick=0+dpt[ind-1][wt];
            int pick=INT_MIN;
            if(weight[ind]<=wt){
                pick=value[ind]+dpt[ind-1][wt-weight[ind]];
            }
            dpt[ind][wt]=max(pick,notpick);
        }
    }
    return dpt[n-1][bag];
}

int main(){
    vector<int>value={30,50,60};
    vector<int>weight={3,4,5};
    int bag=8;
    cout<<knapsack4(weight,value,bag);
    return 0;
}

