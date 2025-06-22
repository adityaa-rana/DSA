#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    // basically find lower bound
    int searchInsert(vector<int>& nums, int target) {
        int low=0;
        int high=nums.size()-1;
        int ans=-1;
        while(low <= high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                ans=mid;
                break;
            }
            else if(nums[mid] > target){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        // edge cases
        if(low>nums.size()-1){
            ans=nums.size();
        }
        else if(high<0){
            ans=0;
        }
        return ans;

    }
};


