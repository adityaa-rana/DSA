#include<bits/stdc++.h>
using namespace std;

int minplatform(vector<int>arr,vector<int>dep){
    if(arr.size()==0){
        return 0;
    }
    int count=1;
    vector<int>curr;
    curr.push_back(-1);
    for(int i=0;i<arr.size();i++){
        int j=0;
        while(j<curr.size()){
            if(curr[j]<arr[i]){
                curr[j]=dep[i];
                break;
            }
            j++;
        }
            
        
        if(j==curr.size()){
            count++;
            curr.push_back(dep[i]);
        }
    }
    return count;
}


// METHOD 1 : REPLACE USING RECURSION
class Solution {
    
public:
    bool check(string s,int index,int count){
        if(count<0){
            return false;
        }
        if(index==s.length()){
            return count==0;
        }
        if(s[index]=='('){
            return check(s,index+1,count+1);
        }
        else if(s[index]==')'){
            return check(s,index+1,count-1);
        }
        else{
            return check(s, index + 1, count + 1) || check(s, index + 1, count - 1) || check(s, index + 1, count);
        }
        return false;
    }
    bool checkValidString(string s) {
        int index=0;
        int count=0;
        return check(s,0,0);
    }
};