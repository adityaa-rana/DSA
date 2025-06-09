#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1){
            return 0;
        }
        if(nums[0]>nums[1]){
            return 0;
        }
        if(nums[nums.size()-1]>nums[nums.size()-2]){
            return nums.size()-1;
        }

        int low=1;
        int high=nums.size()-2;
        int mid;
        while(low<=high){
            mid=low+(high-low)/2;
            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
                return mid;
            }
            //increasing slope
            else if(nums[mid]>nums[mid-1]){
                low=mid+1;
            }
            //decreasing slope
            else if(nums[mid]>nums[mid+1]){
                high=mid-1;
            }
            //dig element : move to any side
            else{
                low=mid+1;
            }
        }
        return -1;
    }
};