#include<bits/stdc++.h>
using namespace std;
int find(int mid,int n,int m){
    long long ans=1;
    for(int i=1;i<=n;i++){
        ans=ans*mid;
        if(ans>m){
            return 2;
        }
    }
    if(ans==m){
        return 1;
    }
    return 0;
}
int nthroot(int m,int n){
    int low=0;
    int high=m;
    int mid=-1;
    while(low<=high){
        mid=low+(high-low)/2;
        int findmid=find(mid,n,m);
        if(findmid==1){
            return mid;
        }
        else if(findmid==2){
            high=mid-1;
        }
        else{
            high=mid+1;
        }
    }
    return mid;
}