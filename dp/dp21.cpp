#include<bits/stdc++.h>
using namespace std;

int targetsum1(vector<int>arr,int index,int sum,int target){
    if(index==arr.size()){
        if(sum==target){
            return 1;
        }
        else{
            return 0;
        }
    }

    int pos=targetsum1(arr,index+1,sum+(arr[index]),target);
    int neg=targetsum1(arr,index+1,sum+(arr[index]*(-1)),target);
    return pos+neg;
}

int main(){
    vector<int>arr={1,2,3,1};
    int target=3;
    cout<<targetsum1(arr,0,0,target);
    return 0;
}