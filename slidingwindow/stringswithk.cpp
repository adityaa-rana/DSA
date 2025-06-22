#include<bits/stdc++.h>
using namespace std;
// brute force
class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans=0;
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                if(count(s.begin()+i, s.begin()+j+1, 'a') > 0 && count(s.begin()+i, s.begin()+j+1, 'b') > 0 && count(s.begin()+i, s.begin()+j+1, 'c') > 0){
                    ans++;
                }
            }
        }
        return ans;
    }
};

// better 
class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans=0;
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                if(count(s.begin()+i, s.begin()+j+1, 'a') > 0 && count(s.begin()+i, s.begin()+j+1, 'b') > 0 && count(s.begin()+i, s.begin()+j+1, 'c') > 0){
                    ans+=s.size()-j;
                    break;
                }
            }
        }
        return ans;
    }
};