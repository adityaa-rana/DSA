#include<bits/stdc++.h>
using namespace std;

// brute force : combine and return mid/2 ;
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<double> combined;
        int i=0;
        int j=0;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]<=nums2[j]){
                combined.push_back(nums1[i]);
                i++;
            }
            else{
                combined.push_back(nums2[j]);
                j++;
            }
        }
        while(i<nums1.size()){
            combined.push_back(nums1[i]);
                i++;
        }
        while(j<nums2.size()){
            combined.push_back(nums2[j]);
                j++;
        }
        int size=combined.size();
        int mid=size/2;
        if(size%2==0){
            return (combined[mid-1]+combined[mid])/2;
        }
        else{
            return combined[mid];
        }
    }

    // better solution
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();
        int total = size1 + size2;
        
        int i = 0, j = 0, count = 0;
        int prev = 0, curr = 0;

        while (count <= total / 2) {
            prev = curr;

            if (i < size1 && (j >= size2 || nums1[i] <= nums2[j])) {
                curr = nums1[i++];
            } else if (j < size2) {
                curr = nums2[j++];
            }

            count++;
        }

        if (total % 2 == 0)
            return (prev + curr) / 2.0;
        else
            return curr;
    }