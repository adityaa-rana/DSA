#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low=0;
        int high=nums.size()-1;
        int mid;

        while(low<=high){
            mid=low+(high-low)/2;
            if(low==high){
                break;
            }
            if(mid>0 && nums[mid]==nums[mid-1]){
                if((mid-low)%2==1){
                    low=mid+1;
                }
                else{
                    high=mid-2;
                }
            }
            else if(mid < nums.size() - 1 && nums[mid]==nums[mid+1]){
                if((high-mid)%2==1){
                    high=mid-1;
                }
                else{
                    low=mid+2;
                }
            }
            else{
                break;
            }
        }
        return nums[mid];
    }
};


// method 2
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        if(nums[0]!=nums[1]){
            return nums[0];
        }
        if(nums[nums.size()-1]!=nums[nums.size()-2]){
            return nums[nums.size()-1];
        }
        int low=1;
        int high=nums.size()-2;
        int mid;
        while(low<=high){
            mid=low+(high-low)/2;
            if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]){
                return nums[mid];
            }
            if(nums[mid]==nums[mid-1]){
                if(mid%2==1){
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
            if(nums[mid]==nums[mid+1]){
                if(mid%2==1){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
        }
        return nums[mid];
    }
};