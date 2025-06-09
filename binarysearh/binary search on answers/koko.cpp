#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findmax(vector<int>& piles){
        int maximum=0;
        for(int i=0;i<piles.size();i++){
            maximum=max(maximum,piles[i]);
        }
        return maximum;
    }

    long long findhours(vector<int>& piles,int mid){
        long long hours=0;
        for(int i=0;i<piles.size();i++){
            hours+=ceil((double)piles[i]/mid);
        }
        return hours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=findmax(piles);
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            long long reqhours=findhours(piles,mid);
            if(reqhours<=h){
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