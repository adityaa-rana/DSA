#include<bits/stdc++.h>
using namespace std;class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int>left;
        vector<int> right;
        int lcount=0;
        int rcount=0;

        int lvalue=-1;
        int rvalue=-1;
        for(int i=0;i<ratings.size();i++){
            if(ratings[i] > lvalue){
                lcount++;
            }
            else if(ratings[i] <= lvalue){
                lcount=1;
            }
            left.push_back(lcount);
            lvalue=ratings[i];
        }
        for(int i=ratings.size()-1;i>=0;i--){
            if(ratings[i] > rvalue){
                rcount++;
            }
            else if(ratings[i] <= rvalue){
                rcount=1;
            }
            right.insert(right.begin(),rcount);
            rvalue=ratings[i];
        }

        int sum=0;
        for(int i=0;i<ratings.size();i++){
            sum+=max(left[i],right[i]);
        }
        return sum;
    }
};



// slope approach
int candy(vector<int>& ratings) {
    int sum=1;
    int i=1;
    int n=ratings.size();
    while(i<n){
        if(ratings[i]==ratings[i-1]){
            sum+=1;
            i++;
            continue;
        }
        int peak=1;
        while(i<n && ratings[i] > ratings[i-1]){
            peak+=1;
            sum+=peak;
            i++;
        }

        int down=1;
        while(i<n && ratings[i] < ratings[i-1]){
            sum+=down;
            down++;
            i++;
        }

        if(peak < down){
            sum+=down-peak;
        }
    }
    return sum;
}