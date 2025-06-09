#include<bits/stdc++.h>
using namespace std;

// upper bound = floor(witout equals)

int upperbound(vector<int>& arr,int key){
    int low=0;
    int high=arr.size()-1;
    int ans=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid] > key){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}

// lower bound = ceil(without equals)

int lowerbound(vector<int>& arr,int key){
    int low=0;
    int high=arr.size()-1;
    int ans=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid] < key){
            high=mid-1;
        }
        else{
            ans=mid;
            low=mid+1;
        }
    }
    return ans;
}