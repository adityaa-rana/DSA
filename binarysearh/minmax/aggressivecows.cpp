#include<bits/stdc++.h>
using namespace std;

bool find(vector<int>& arr,int cows,int mid){
    int count=0;
    for(int i=1;i<arr.size();i++){
        if(arr[i]-arr[i-1]>=mid){
            count++;
        }
    }
    return count>=cows;
}
int aggressivecows(vector<int>& arr,int cows){
    int low=1;
    int high=arr[arr.size()-1]-arr[0];

    int ans;
    while(low<=high){
        int mid=low+(high-low)/2;
        bool possible=find(arr,cows,mid);
        if(possible){
            ans=mid;
            low=mid+1;
        }
        else{
            high=high-1;
        }
    }
}