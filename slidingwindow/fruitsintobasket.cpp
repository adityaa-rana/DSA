#include<bits/stdc++.h>
using namespace std;

// approach 1 : notebook
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int i=0,j=0;
        int count=0;
        int num1=fruits[0],num2=-1;
        while(j<fruits.size()){
            if(fruits[j]!=num1 && num2==-1){
                num2=fruits[j];
                j++;
            }
            else if(fruits[j]==num1 || fruits[j]==num2){
                j++;
            }
            else{
                num2=fruits[j];
                i=j-1;
                num1=fruits[i];
                
                int prev=num1;
                while(i>0 && fruits[i-1]==prev){
                    i=i-1;
                }
            }
            count=max(count,j-i);
        }
        return count;
    }
};

//approach 2 : using map
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        map<int,int>mpp;
        int i=0,j=0;
        int count=0;
        while(i<=j && j<fruits.size()){
            mpp[fruits[j]]++;
            j++;
            
            while(mpp.size()>2){
    
                mpp[fruits[i]]--;
                if(mpp[fruits[i]]==0){
                    mpp.erase(fruits[i]);   
                }
                i++;
            }
            if(mpp.size()<=2){
                count=max(count,j-i);
            }
            
        }
        return count;
    }
};

// approach 3 : using map
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        map<int,int>mpp;
        int i=0,j=0;
        int count=0;
        while(i<=j && j<fruits.size()){
            mpp[fruits[j]]++;
            j++;
            
            if(mpp.size()>2){
    
                mpp[fruits[i]]--;
                if(mpp[fruits[i]]==0){
                    mpp.erase(fruits[i]);   
                }
                i++;
            }
            if(mpp.size()<=2){
                count=max(count,j-i);
            }
            
        }
        return count;
    }
};

// longest substring with atmost k different characters : using hashmap
int longestsubstring(string s,int k){
    int i=0,j=0;
    int count=0;
    map<char,int>mpp;
    while(i<=j && j<s.length()){
        mpp[s[j]]++;
        j++;

        if(mpp.size()>k){
            mpp[s[i]]--;
            if(mpp[s[i]]==0){
                mpp.erase(s[i]);
            }
            i++;
        }
        if(mpp.size()<=k){
            count=max(count,j-i+1);
        }
    }
    return count; 
}

// without hashmap : only work if k=2
int longestsubstring(string s,int k){
    int i=0,j=0;
    int count=0;
    int num1=s[0];
    int num2=-1;
    while(j<s.size()){
        if(s[j]!=num1 && num2==-1){
            num2=s[j];
            j++;
        }
        else if(s[j]==num1 || s[j]==num2){
            j++;
        }
        else{
            num1=s[j];
            i=j-1;
            num2=s[i];
            int prev=num2;
            while(i>0 && s[i-1]==prev){
                i=i-1;
            }
        }
        count=max(count,j-i);
    }
    return count;
}
