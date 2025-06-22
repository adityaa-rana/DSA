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

    long long trydivisor(vector<int>& nums, int mid){
        long long summ=0;
        for(int i=0;i<nums.size();i++){
            summ+=ceil((double)nums[i]/mid);
        }
        return summ;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1;
        int high=findmax(nums);
        int ans=-1;

        while(low<=high){
            int mid=low+(high-low)/2;
            long long summ=trydivisor(nums,mid);

            if(summ<=threshold){
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