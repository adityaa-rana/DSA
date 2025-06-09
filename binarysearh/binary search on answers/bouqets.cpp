#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    
    int findmax(vector<int>& arr){
        int maximum=1;
        for(int i=0;i<arr.size();i++){
            maximum=max(maximum,arr[i]);
        }
        return maximum;
    }
    int findmin(vector<int>& arr){
        int minimum=INT_MAX;
        for(int i=0;i<arr.size();i++){
            minimum=min(minimum,arr[i]);
        }
        return minimum;
    }
    
    int findnum(vector<int>& arr, int mid, int k){
        int boquets=0;
        int count=0;
        for(int i=0;i<arr.size();i++){
            if(mid>=arr[i]){
                count++;
            }
            else if(mid<arr[i]){
                count=0;
            }
            if(count==k){
                boquets++;
                count=0;
            }
        }
        return boquets;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low=findmin(bloomDay);
        int high=findmax(bloomDay);
        int ans=-1;

        while(low<=high){
            int mid=low+(high-low)/2;
            int numboquets=findnum(bloomDay,mid,k);

            if(numboquets>=m){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};