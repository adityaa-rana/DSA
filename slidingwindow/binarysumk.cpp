#include<bits/stdc++.h>
using namespace std;
// brute force
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int count=0;
        for(int i=0;i<nums.size();i++){
            int isum=0;
            for(int j=i;j<nums.size();j++){
                isum+=nums[j];
                if(isum==goal){
                    count++;
                }
                else if(isum>goal){
                    break;
                }
            }
        }
        return count;
    }
};


// optimum
class Solution {
public:
    int findcount(vector<int>& nums,int goal){
        if(goal<0){
            return 0;
        }
        int i=0,j=0,count=0,summ=0;
        while(j<nums.size()){
            summ+=nums[j];
            while(summ>goal){
                summ-=nums[i];
                i++;
            }
            count+=(j-i+1);     
            j++;
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int goall=findcount(nums,goal);
        int goalminusone=findcount(nums,goal-1);
        return goall-goalminusone;
    }
};