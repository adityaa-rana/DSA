#include<stdio.h>
int close(int arr[],int size,int k){
    int l=0;
    int h=size-1;
    int mid;
    int mindif=__INT_MAX__;
    int ans;
    while(l<=h){
        mid=(l+h)/2;
        int dif=arr[mid]-k;
        int diff=dif>0?dif:(-1)*dif;
        if(diff<mindif){
            mindif=diff;
            ans=arr[mid];
        }
        else if(arr[mid]<k){
            l=mid+1;
        }
        else{
            h=mid-1;
        }
    }
    return ans;
}

int main(){
    int arr[]={2,4,6,8,10,12,14,16,18};
    printf("%d",close(arr,9,5));
    return 0;

}
