#include<bits/stdc++.h>
using namespace std;

bool canJump(vector<int>& nums) {
        int max=0;
        int ind=0;
        if(nums[ind]==0 & nums.size()>1){
            return false;
        }
        while(ind<nums.size()){
            if(ind>max){
                return false;
            }
            if(ind+nums[ind]>max){
                max=ind+nums[ind];
            }
            ind++;
        }
        return true;
    }