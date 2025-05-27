#include<bits/stdc++.h>
using namespace std;

// // FROG JUMP
// //using only recursion
// int minenergy1(int index,vector<int>sample){
//     if(index==0){
//         return 0;
//     }
//     int onestep=minenergy1(index-1,sample)+abs(sample[index]-sample[index-1]);
//     int twostep=INT_MAX;
//     if(index>1){
//         twostep=minenergy1(index-2,sample)+abs(sample[index]-sample[index-2]);
//     }                                                                            
//     return min(onestep,twostep);
// }

// int n=6;
// // ADDING MEMORIZATION
// vector<int>dp(n,-1);
// int minenergy2(int index,vector<int>sample,vector<int>dp){
//     if(index==0){
//         return 0;
//     }
//     //we are not checking if the function already has a value but rather checking if the index for which we have called the function already has a valur or not,  if it does, that is the value to be returned
//     if(dp[index]!=-1){
//         return dp[index];
//     }
//     int onestep=minenergy2(index-1,sample,dp)+abs(sample[index]-sample[index-1]);
//     int twostep=INT_MAX;
//     if(index>1){
//         twostep=minenergy2(index-2,sample,dp)+abs(sample[index]-sample[index-2]);
//     }  
//     return dp[index]=min(onestep,twostep);
// }

// // adding tabulation
// //baat smjho hum yahan basically kr kya rhe hein, yahan recursion nhi ho rha
// //yahan hum at each step minimum energy required to reach that step nikaalte jaa rhe hein aur usko store krte jaa rhe hein current mein jo ki fir change hoti jaa rhi hai prev me aur prev2 me kyuki hume finally n ki value chahiye
// int minenergy(int index,vector<int>sample){
//     int prev1=0;
//     int prev2=0;
//     for(int i=0;i<n;i++){
//         // agar hum pichle step se ek step lekr aayein to ye energy hogi
//         int one=prev1+abs(sample[index]-sample[index-1]);
//         int two=INT_MAX;
//         if(index>1){
//             //agr hum 2 step peeche se 2 step ka jump marke aayein to ye energy hogi
//             two=prev2+abs(sample[index]-sample[index-2]);
//         } 
//         //ab hum dekh rhe hein current step ke liye konsi energy minimum hai dono me se, usko lenge
//         //agar hum double step le rhe hein iska ye mtlb nhi ki 2 step aage ka calculate krege ab next
//         //hume basically harr step ke liye dekhna ki uske pichle step se single jump krege wo km energy lega ya uske 2 peeche steps se double jump krege wo km energy lega
//         int current=min(one,two);
//         prev2=prev1;
//         prev1=current;
//     }
//     return prev2;
// }

// // FROG JUMP 2
// //here not just 1 or 2 steps, frog can take any of 1 to k steps , so we use a loop
// int frog1(int index,vector<int>sample,int k){
//     if(index==0){
//         return 0;
//     }
//     int minenergy=INT_MAX;    
//     for(int j=1;j<k;j++){
//         if(index-j>=0){
//             int jump=frog1(index-j,sample,k)+abs(sample[index]-sample[index-j]);
//             minenergy=min(minenergy,jump);
//         }
//     }
//     return minenergy;
// }

// // maximum sum in non-adjacent elements in array

//  int maxsum_nonadj(int index,vector<int>sample){
//     if(index<0){
//         return 0;
//     }
//     if(index==0){
//         return sample[index];
//     }
//     int pick=sample[index]+maxsum_nonadj(index-2,sample);
//     int notpick=0+maxsum_nonadj(index-1,sample);
//     return max(pick,notpick);
//  }

 //using memoization
//  vector<int>sample={2,1,4,9};
//  int nsample=sample.size();
// vector<int>dp(nsample,-1);
//  int maxsum_nonadj(int index,vector<int>sample){
//     if(index<0){
//         return 0;
//     }
//     if(index==0){
//         return sample[index];
//     }
//     if(dp[index]!=-1){
//         return dp[index];
//     }
//     int pick=sample[index]+maxsum_nonadj(index-2,sample);
//     int notpick=0+maxsum_nonadj(index-1,sample);
//     return dp[index]=max(pick,notpick);
//  }

//  //tabulation using dp array

//  int maxsum(int index,vector<int>sample,vector<int>dp){
//     if(index==0){
//         dp[index]=sample[index];
//     }

//     for(int i=1;i<sample.size();i++){
//         int pick=sample[index];
//         if(i>1){
//             pick+=sample[i-2];
//         }
//         int notpick=0+sample[i-1];
//         dp[i]=max(pick,notpick);
//     }
//  }

//  //replacing dp array with previous
//  int maxsum2(int index,vector<int>sample,vector<int>dp){
//     int prev=0;
//     int prev2=0;

//     for(int i=1;i<sample.size();i++){
//         int pick=sample[index];
//         if(i>1){
//             pick+=prev2;
//         }
//         int notpick=0+prev;
//         int curr=max(pick,notpick);
//         prev2=prev;
//         prev=curr;
//     }
//     return prev;
//  }


// circular max non-adjacent sum
//  vector<int>sample={2,1,4,9};
//  int nsample=sample.size();
// vector<int>dp(nsample,-1);
// int maxsum_nonadj(int index,vector<int>sample,bool flag){
//    if(index<0){
//        return 0;
//    }
//    if(index==0){
//     if(flag==false){
//         return sample[index];
//     }
//     else{
//         return 0;
//     }   
//    }
//    if(dp[index]!=-1){
//        return dp[index];
//    }
//    int pick=sample[index]+maxsum_nonadj(index-2,sample,flag);
//    int notpick=0+maxsum_nonadj(index-1,sample,flag);
//    int el=max(pick,notpick);
//    if(index==nsample-1 && el==sample[nsample-1]){
//     flag=true;
//    }
//    return dp[index]=el;
// }


// vector<vector<int>>points;
// // ninja training
// int col=3;
// int maxpoints(int day,int prev){
//     if(day==0){
//         int maxi=0;
//         for(int i=0;i<col;i++){
//             maxi=max(maxi,points[day][i]);
//         }
//         return maxi;
//     }

//     int maxi=0;
//     for(int i=0;i<col;i++){
//         if(i!=prev){
//             int currentpoints=points[day][i]+maxpoints(day-1,i);
//             maxi=max(currentpoints,maxi);
//         }
//     }
//     return maxi;
// }

// //using memoization
// int col=3;
// int days=4;
// vector<vector<int>> dp(days,vector<int>(4,-1));
// vector<vector<int>>points;
// int maxpoints(int day,int prev,vector<vector<int>>&dp){
//     if(day==0){
//         int maxi=0;
//         for(int i=0;i<col;i++){
//             if(i!=prev)
//             maxi=max(maxi,points[day][i]);
//         }
//         dp[day][prev]=maxi;
//         return maxi;
//     }
//     if(dp[day][prev]!=-1) return dp[day][prev];
//     int maxi=0;
//     for(int i=0;i<col;i++){
//         if(i!=prev){
//             int currentpoints=points[day][i]+maxpoints(day-1,i);
//             maxi=max(currentpoints,maxi);
//         }
//     }
//     dp[day][prev]=maxi;
//     return maxi;
// }

// total unique paths in 2-D grid using Recursion (before DP)
// int totalpath1(int si,int ei,int sj,int ej){
//     if(si==ei && sj==ej){
//         return 1;
//     }
//     if(si<0 || sj<0){
//         return 0;
//     }
//     int up=totalpath1(si-1,ei,sj,ej);
//     int left=totalpath1(si,ei,sj-1,ej);
//     return up+left;
// }  

// // //using memoization
// int n=3,m=3;
// vector<vector<int>>dp(m,vector<int>(n,-1));
// int totalpath2(int si,int ei,int sj,int ej){
//     if(si==ei && sj==ej){
//         return 1;
//     }
//     if(si<0 || sj<0){
//         return 0;
//     }
//     if(dp[si][sj]!=-1){
//         return dp[si][sj];
//     }
//     int up=totalpath2(si-1,ei,sj,ej);
//     int left=totalpath2(si,ei,sj-1,ej);
//     return dp[si][sj]=up+left;
// } 

// //using tabulation
// int totalpath3(int si,int sj,int ei,int ej){
//     dp[si][sj]=1;
//     for(int i=0;i<=ei;i++){
//         for(int j=0;j<=ej;j++){
//             if(i==0 &&j==0) continue;
//             int up,left;
//             if(i>=1){
//                 up=dp[i-1][j];
//             }
//             else{
//                 up=0;
//             }
//             if(j>=1){
//                 left=dp[i][j-1];
//             }
//             else{
//                 left=0;
//             }
//             dp[i][j]=up+left;
//         }
//     }
//     return dp[ei][ej];
// }

// maze obstacles
// int maze1(int si,int ei,int sj,int ej,vector<vector<int>>matrix){
//     if(si==ei && sj==ej){
//         return 1;
//     }
//     if(si<0 || sj<0){
//         return 0;
//     }
//     if(matrix[si][sj]==-1){
//         return 0;
//     }
//     int up=maze1(si-1,ei,sj,ej,matrix);
//     int left=maze1(si,ei,sj-1,ej,matrix);
//     return up+left;
// } 

// int n=3,m=3;
// vector<vector<int>>dp(m,vector<int>(n,-1));
// //using memoization
// int maze2(int si,int ei,int sj,int ej,vector<vector<int>>matrix){
//     if(si==ei && sj==ej){
//         return 1;
//     }
//     if(si<0 || sj<0){
//         return 0;
//     }
//     if(matrix[si][sj]==-1){
//         return 0;
//     }
//     if(dp[si][sj]!=-1){
//         return dp[si][sj];
//     }
//     int up=maze1(si-1,ei,sj,ej,matrix);
//     int left=maze1(si,ei,sj-1,ej,matrix);
//     return dp[si][sj]=up+left;
// } 

// using tabulation

// int n=3,m=3;
// vector<vector<int>>dp(m,vector<int>(n,-1));
// int maze3(int si,int sj,int ei,int ej,vector<vector<int>>matrix){
    
//     for(int i=0;i<=ei;i++){
//         for(int j=0;j<=ej;j++){
            
//             if(matrix[i][j]==-1){
//                 dp[i][j]=0;
//             }
//             else if(i==0 && j==0){
//                 dp[i][j]=1;
//             }
//             else{
//                 int up,left;
//                 if(i>=1){
//                     up=dp[i-1][j];
//                 }
//                 else{
//                     up=0;
//                 }
//                 if(j>=1){
//                     left=dp[i][j-1];
//                 }
//                 else{
//                     left=0;
                    
//                 }
//                 dp[i][j]=up+left;
//             }
            
            
//         }
//     }
//     return dp[ei][ej];
// }

// int main(){
//     vector<vector<int>>matrix={{0,0,0},{0,-1,0},{0,0,0}};
//     cout<<maze3(0,0,2,2,matrix);
//     return 0;
// }

// minimum path sum in 2-D grid using DP
// int minpath1(int si,int ei,int sj,int ej,vector<vector<int>>matrix){
//     if(si==ei && sj==ej){                                                   
//         return matrix[si][sj];
//     }
//     if(si<0 || sj<0){
//         return INT_MAX;
//     }
    
//     int up=minpath1(si-1,ei,sj,ej,matrix);
//     int left=minpath1(si,ei,sj-1,ej,matrix);
//     return matrix[si][sj]+min(left,up);
// }

// // memoization
// int n=3,m=3;
// vector<vector<int>>dp(m,vector<int>(n,-1));
// int minpath2(int si,int ei,int sj,int ej,vector<vector<int>>matrix){
//     if(si==ei && sj==ej){
//         return matrix[si][sj];
//     }
//     if(si<0 || sj<0){
//         return INT_MAX;
//     }
//     if(dp[si][sj]!=-1){
//         return dp[si][sj];
//     }
//     int up=minpath2(si-1,ei,sj,ej,matrix);
//     int left=minpath2(si,ei,sj-1,ej,matrix);
//     return dp[si][sj]=matrix[si][sj]+min(left,up);
// }


// // tabulation
// int n=3,m=3;
// vector<vector<int>>dp(m,vector<int>(n,-1));
// int minpath3(int si,int ei,int sj,int ej,vector<vector<int>>matrix){
//     for(int i=si;i<=ei;i++){
//         for(int j=sj;j<=ej;j++){
//             if(i==si && j==sj){
//                 dp[i][j]=matrix[i][j];
//             }
//             else{
//                 int up=INT_MAX,left=INT_MAX;
//                 if(i>=1){
//                     up=dp[i-1][j];
//                 }
//                 if(j>=1){
//                     left=dp[i][j-1];
//                 }
//                 dp[i][j]=matrix[i][j]+min(up,left);
//             }
//         }
//     }
//     return dp[ei][ej];
// }

// int main(){
//     vector<vector<int>>matrix={{10,8,2},{10,5,100},{1,1,2}};
//     cout<<minpath3(0,2,0,2,matrix);
//     return 0;
// }

// triangle using dp first RECURSION
// int mintri1(int si,int sj,vector<vector<int>>matrix){
//     if(si==matrix.size()-1){
//         return matrix[si][sj];
//     }
//     int down=mintri1(si+1,sj,matrix);
//     int diagonal=mintri1(si+1,sj,matrix);
//     return matrix[si][sj]+min(down,diagonal);
// }

// // using memoization
// int n=4,m=4;
// vector<vector<int>>dp(m,vector<int>(n,-1));
// int mintri2(int si,int sj,vector<vector<int>>matrix){
//     if(si==matrix.size()-1){
//         return matrix[si][sj];
//     }
//     if(dp[si][sj]!=-1){
//         return dp[si][sj];
//     }
//     int down=mintri2(si+1,sj,matrix);
//     int diagonal=mintri2(si+1,sj+1,matrix);
//     return dp[si][sj]=matrix[si][sj]+min(down,diagonal);
// }
//tabulation
// int n=4,m=4;
// vector<vector<int>>dp(m,vector<int>(n,-1));
// int mintri3(vector<vector<int>>matrix){
//     //declaring 4 columns of base case row
//     for(int j=0;j<n;j++){
//         dp[n-1][j]=matrix[n-1][j];
//     }
//     for(int i=n-2;i>=0;i--){
//         for(int j=i;j>=0;j--){
//             int down=dp[i+1][j];
//             int diagonal=dp[i+1][j+1];
//             dp[i][j]=matrix[i][j]+min(down,diagonal);
//         }
//     }
//     return dp[0][0];
// }
// int main(){
//     vector<vector<int>>matrix={{1},{2,3},{3,6,7},{8,9,6,10}};
//     cout<<mintri3(matrix);
//     return 0;
// }

// STARTING WITH VARIABLE POINT AND ENDING AT VARIABLE POINT
//max path , using multiple starting points for recursion
// int n=4;
// int maxpath1(int srow,int scol,vector<vector<int>>matrix){
//     if(srow==0){
//         return matrix[srow][scol];
//     }
//     if(scol<0 || scol>n-1){
//         return 0;
//     }
//     int dialeft=maxpath1(srow-1,scol-1,matrix);
//     int diaright=maxpath1(srow-1,scol+1,matrix);
//     int down=maxpath1(srow-1,scol,matrix);
//     return matrix[srow][scol]+max(dialeft,max(diaright,down));
// }

// int main(){
//     int max_answer=INT_MIN;
//     vector<vector<int>>matrix={{1,2,10,4},{100,3,2,1},{1,1,20,2},{1,2,2,1}};
//     for(int j=0;j<4;j++){
//         int pathsum=maxpath1(n-1,j,matrix);
//         max_answer=max( pathsum,max_answer);
//     }
//     cout<<max_answer;
//     return 0;
// }


// using memoization : here i will have to create dp array in the loop, as for each starting point recursion path, a new dp array is required
// int n=4;
// int m=4;
// int maxpath1(int srow,int scol,vector<vector<int>>matrix,vector<vector<int>>dp){
//     if(srow==0){
//         return matrix[srow][scol];
//     }
//     if(scol<0 || scol>=n){
//         return 0;
//     }
//     if(dp[srow][scol]!=-1){
//         return dp[srow][scol];
//     }
//     int dialeft=maxpath1(srow-1,scol-1,matrix,dp);
//     int diaright=maxpath1(srow-1,scol+1,matrix,dp);
//     int down=maxpath1(srow-1,scol,matrix,dp);
//     return dp[srow][scol]=matrix[srow][scol]+max(dialeft,max(diaright,down));
// }

// int main(){
//     int max_answer=INT_MIN;
//     vector<vector<int>>matrix={{1,2,10,4},{100,3,2,1},{1,1,20,2},{1,2,2,1}};
//     for(int j=0;j<4;j++){
//         vector<vector<int>>dp(m,vector<int>(n,-1));
//         int pathsum=maxpath1(n-1,j,matrix,dp);
//         max_answer=max( pathsum,max_answer);
//     }
//     cout<<max_answer;
//     return 0;
// }

//using tabulation
// int n=4;
// int m=4;
// vector<vector<int>>dp(m,vector<int>(n,-1));
// int maxpath3(vector<vector<int>>matrix){
//     for(int i=0;i<n;i++){
//         dp[0][i]=matrix[0][i];
//     }    
//     for(int i=1;i<=n-1;i++){
//         for(int j=0;j<=m-1;j++){
//             int dialeft=0,diaright=0;
//             if(j>=1){
//                 dialeft=dp[i-1][j-1];
//             }
//             if(j<n-1){
//                 diaright=dp[i-1][j+1];
//             }
//             int down=dp[i-1][j];

//             dp[i][j]=matrix[i][j]+max(down,max(dialeft,diaright));
//         }
//     }
//     int maxpath=INT_MIN;
//     for(int i=0;i<n;i++){
//         if(maxpath<dp[n-1][i]){
//             maxpath=dp[n-1][i];
//         }
//     }
//     return maxpath;
// }

// int main(){
//     vector<vector<int>>matrix={{1,2,10,4},{100,3,2,1},{1,1,20,2},{1,2,2,1}};
//     cout<<maxpath3(matrix);
//     return 0;
// }

// cherry pickup : using two recursions in one
int n=3,m=4;
// int maxcherry1(int i,int j1,int j2,vector<vector<int>>cherries){
//     if(j1<0 || j1>m-1 || j2<0 ||j2>m-1){
//         return -1;
//     }
//     if(i==n-1){
//         if(j1==j2){
//             return cherries[i][j1];
//         }
//         else{
//             return cherries[i][j1]+cherries[i][j2];
//         }
//     }
//     int maxi=0;
//     for(int dj1=-1;dj1<=1;dj1++){
//         for(int dj2=-1;dj2<=1;dj2++){
//             int value=0;

//             //we are calculating step values for all movements and then adding them to previous path and finding the max of them all
//             if(j1==j2){
//                 value=cherries[i][j1];
//             }
//             else{
//                 value=cherries[i][j1]+cherries[i][j2];
//             }
//             value+=maxcherry1(i+1,j1+dj1,j2+dj2,cherries);
//             maxi=max(maxi,value);
//         }
//     }
//     return maxi;
// }

//using memoization
vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));

// int maxcherry2(int i,int j1,int j2,vector<vector<int>>cherries){
//     if(j1<0 || j1>m-1 || j2<0 ||j2>m-1){
//         return -1;
//     }
//     if(i==n-1){
//         if(j1==j2){
//             return cherries[i][j1];
//         }
//         else{
//             return cherries[i][j1]+cherries[i][j2];
//         }
//     }
//     if(dp[i][j1][j2]!=-1){
//         return dp[i][j1][j2];
//     }
//     int maxi=0;
//     for(int dj1=-1;dj1<=1;dj1++){
//         for(int dj2=-1;dj2<=1;dj2++){
//             int value=0;

//             //we are calculating step values for all movements and then adding them to previous path and finding the max of them all
//             if(j1==j2){
//                 value=cherries[i][j1];
//             }
//             else{
//                 value=cherries[i][j1]+cherries[i][j2];
//             }
//             value+=maxcherry2(i+1,j1+dj1,j2+dj2,cherries);
//             maxi=max(maxi,value);
//         }
//     }
//     dp[i][j1][j2]=maxi;
//     return maxi;
// }

//using tabulation
// int maxcherry3(vector<vector<int>>cherries){
//     for(int j1=0;j1<m;j1++){
//         for(int j2=0;j2<m;j2++){
//             if(j1==j2){
//                 dp[n-1][j1][j2]=cherries[n-1][j1];
//             }
//             else{
//                 dp[n-1][j1][j2]=cherries[n-1][j1]+cherries[n-1][j1][j2];
//             }
//         }
//     }

//     for(int i=n-1;i>=0;i--){
//         for(int j1=0;j1<m;j1++){
//             for(int j2=0;j2<m;j2++){
//                 int value=0;

//                 //we are calculating step values for all movements and then adding them to previous path and finding the max of them all
//                 if(j1==j2){
//                     value=cherries[i][j1];
//                 }
//                 else{
//                     value=cherries[i][j1]+cherries[i][j2];
//                 }
//                 if(j1>0 ){
//                     value+=dp[i+1][j1];
//                 }
                
//                 maxi=max(maxi,value);
//             }
//         }
//     }
// }
// int main(){
//     vector<vector<int>>cherries={{2,3,1,2},{3,4,2,2},{5,6,3,5}};
//     cout<<maxcherry3(0,0,3,cherries);
//     return 0;
// }