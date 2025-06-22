#include<bits/stdc++.h>
using namespace std;

// brute force
class Solution {
public:
    int characterReplacement(string s, int k) {
        int count=0;
        for(int i=0;i<s.size();i++){
            map<char,int>mpp;
            int maxfreq=0;
            for(int j=i;j<s.size();j++){
                mpp[s[j]]++;
                maxfreq=max(maxfreq,mpp[s[j]]);
                int changes=(j-i+1)-maxfreq;

                if(changes<=k){
                    count=max(j-i+1,count);
                }
                else{
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
    int characterReplacement(string s, int k) {
        int i=0;
        int j=0;
        int ans=0;
        map<char,int>mpp;
        int mostfreq=0;
        while(j<s.size()){
            mpp[s[j]]++;
            mostfreq=max(mostfreq,mpp[s[j]]);
            int changes=(j-i+1)-mostfreq;

            if(changes<=k){
                ans=max(j-i+1,ans);
            }
            else{
                mpp[s[i]]--;
                i++;
            }
            j++;
        } 
        return ans;
    }
};