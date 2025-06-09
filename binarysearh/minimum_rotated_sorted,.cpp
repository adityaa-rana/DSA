#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0;
        int high=nums.size()-1;
        int ans=INT_MAX;

        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[low]<=nums[mid]){
                ans=min(ans,nums[low]);
                low=mid+1;
            }
            else{
                ans=min(ans,nums[mid]);
                high=mid-1;
            }
        }
        return ans;
    }
};

// minimum in rotated sorted array 2
class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0;
        int high=nums.size()-1;
        int ans=INT_MAX;

        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==nums[low] && nums[mid]==nums[high]){
                ans=min(nums[mid],ans);
                low++;
                high--;
                continue;
            }

            if(nums[mid]<=nums[high]){
                ans=min(ans,nums[mid]);
                high=mid-1;
            }
            else{
                ans=min(ans,nums[low]);
                low=mid+1;
            }
        }
        return ans;
    }
};