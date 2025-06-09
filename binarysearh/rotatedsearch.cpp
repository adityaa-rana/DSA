#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int ans=-1;
        int low=0;
        int high=nums.size()-1;

        while(low<=high){
            int mid=low+(high-low)/2;
            
            if(nums[mid]==target){
                ans=mid;
                break;
            }

            //identify the sorted half

            //right half is sorted
            if(nums[mid] <= nums[high]){
                // if in the sorted range
                if(target>=nums[mid] && target<=nums[high]){
                    low=mid+1;
                }
                // if not in the sorted range
                else{
                    high=mid-1;
                }
            }
            //left half is sorted
            else if(nums[mid] >= nums[low]){
                // if in the sorted range
                if(target<=nums[mid] && target>=nums[low]){
                    high=mid-1;
                }
                // if not in the sorted range
                else{
                    low=mid+1;
                }
            }
        }
        return ans;
    }
};


// search in sorted rotated array 2class Solution {

bool search(vector<int>& nums, int target) {
    int low=0;
    int high=nums.size()-1;
    bool ans=false;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(nums[mid]==target){
            ans=true;
            break;
        }
        if(nums[mid]==nums[low] && nums[high]==nums[mid]){
            low++;
            high--;
            continue;
        }
        else if(nums[mid] <= nums[high]){
            if(nums[mid]<=target && nums[high]>=target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        else if(nums[mid] >= nums[low]){
            if(nums[mid]>=target && nums[low]<=target){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
    }
    return ans;
}

