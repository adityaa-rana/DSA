#include<bits/stdc++.h>
using namespace std;

void swap(int *n1,int *n2){
    int t=*n1;
    *n1=*n2;
    *n2=t;
}

void print(vector<int>array,int size){
    for(int i=0;i<size;i++){
        cout<<array[i]<<"\t";
    }
    cout<<endl;
}

// FINDING THE MISSING ELEMENT IN A CONTINUOS and SORTED ARRAY

// brute force
int find1(vector<int>arr,int size){
    for(int i=arr[0];i<arr[size-1];i++){
        for(int j=0;j<size;j++){
            if(arr[j]==i){
                break;
            }
            return i;
        }
    }
}

//better
int find2(vector<int>arr,int size){
    int hash[size+1]={0};
    for(int i=0;i<size;i++){
       hash[arr[i]]=1; 
    }
    for(int i=1;i<size;i++){
        if(hash[i]==0){
            return i;
        }
    }
}

//my solution

int find3(vector<int>arr,int size){
    for(int i=0;i<size-1;i++){
        if(arr[i+1]-arr[i]>1){
            return arr[i]+1;
        }
    }
}

// optimal : sum
int find4(vector<int>arr,int size){
    int n=arr[size-1];
    int sum1=n*(n+1)/2;
    int sum2=0;
    for(int i=0;i<size;i++){
        sum2+=arr[i];
    }
    return sum1-sum2;
}


// optimal : xor
// property 1: num(xor)num=0
// property 2: num(xor)0=num
int find5(vector<int>arr,int size){
    int exor=1;
    for(int i=0;i<size;i++){
        exor=exor^i+2;
        exor=exor^arr[i];
    }
    return exor;
}

// int main(){
//     vector<int>arr={1,2,4,5};
//     cout<<find5(arr,4);
//     return 0;
// }
//-------------------------------------------------------------------------------------------------------------------------------------------
// maximum consecutive ones
int maxones(vector<int>arr,int size){
    int temp=0;
    int max=0;
    for(int i=0;i<size;i++){
        if(arr[i]==1){
            temp++;
        }
        else{
            if(temp>max){
                max=temp;
            }
            temp=0;
        }
    }
    return max;
}

// int main(){
//     vector<int>arr={1,1,0,1,1,1,0,0,1,1,1,1,0,1,1};
//     int size=arr.size();
//     cout<<maxones(arr,size);
//     return 0;
// }

// element appearing once in an array where every element appears twice

// brute force
int single1(vector<int>arr,int size){
    for(int i=0;i<size;i++){
        int count=0;
        for(int j=0;j<size;j++){
            if(arr[j]==arr[i]){
                count++;
            }
        }
        if (count==1){
            return arr[i];
        }
    }
    return -1;
}

// better : hashing
int single2(vector<int>arr,int size){
    int hash[arr[size-1]+1]={0};
    for(int i=0;i<size;i++){
        hash[arr[i]]++;
    }
    int s=sizeof(hash)/sizeof(int);
    for(int i=0;i<s;i++){
        if(hash[i]==1){
            return i;
        }
    }
}


// optimal: xor

int single3(vector<int>arr,int size){
    int exor=0;
    for(int i=0;i<size;i++){
        exor^=arr[i];
    }
    return exor;
}
// int main(){
//     vector<int> arr={1,1,2,2,3,4,4,5,5};
//     cout<<single2(arr,9);
//     return 0;
// }

// longest subarray with sum k
#include<bits/stdc++.h>
using namespace std;
int subarray(vector<int>arr,int size,int k){
    int i=0,j=0;
    int summ=arr[0];
    int maxlen=0;
    while(j<size){
        while(summ>k && i<=j){
            summ=summ-arr[i];
            i++;
        }
        if(summ==k){
            maxlen=max(maxlen,j-i+1);
        }
        j++;
        if(j<size){
            summ+=arr[j];
        }
    }
    return maxlen;
}

// int main(){
//     vector<int>arr={1,2,3,1,1,1,1,4,2,3};
//     cout<<subarray(arr,arr.size(),3);
//     return 0;
// }

// TWO SUM :
// BRUTE FORCE

bool twosum(vector<int> arr,int k){
    for(int i=0;i<arr.size();i++){
        for(int j=i+1;j<arr.size();j++){
            if(arr[i]+arr[j]==k){
                return true;
            }
        }
    }
    return false;
}

bool twosum2(vector<int> arr,int k){
    map<int,int>mpp;
    for(int i=0;i<arr.size();i++){
        int first=arr[i];
        int req=k-first;
        if(mpp.find(req)!=mpp.end()){
            return true;
        }
        mpp[first]=i;
    }
    return false;
}

// OPTIMAL SOLUTION USING TWO POINTERS
// GREEDY METHOD
bool twosum3(vector<int> arr,int k){
    int i=0;
    int j=arr.size()-1;
    while(i<j){
        int summ=arr[i]+arr[j];
        if(summ<k){
            i++;
        }
        else if(summ>k){
            j--;
        }
        else{
            return true;
        }
    }
    return false;
}
// int main(){
//     vector<int>arr={2,6,5,8,11};
//     sort(arr.begin(),arr.end());
//     print(arr,5);
//     return 0;
// }

// counting the majority element'
// brute force
int major1(vector<int> arr,int size){
    for(int i=0;i<size;i++){
        int count=0;
        for(int j=0;j<size;j++){
            if(arr[i]==arr[j]){
                count++;
            }
        }
        if(count>size/2){
            return count;
        }
    }
    return -1;
}

// better : hash map
int major2(vector<int> arr,int size){
    map<int,int>hash;
    for(int i=0;i<size;i++){
        hash[arr[i]]++;
    }
    for(auto i:hash){
        if(i.second>size/2){
            return i.second;
        }
    }
    return -1;
}


// moore voting algorithm

int moore(vector<int>arr,int size){
    int i=0;
    int el=arr[0];
    int count=0;
    while(i<size){
        if(el==arr[i]){
            count++;
        }
        else if(el!=arr[i]){
            count--;
        }
        if(count==0){
            el=arr[i];
            count=1;
        }
        i++;
    }
    if(count>0){
        return el;
    }
    return -1;
}
// int main(){
//     vector<int> arr={2,2,2,1,3,3,2};
//     cout<<moore(arr,arr.size());
//     return 0;
// }

// maximumm subarray sum

// int maxi(vector<int>arr,int size){
//     int j=0;
//     int summ=0;
//     int maxsum=INT_MIN;
//     while(j<size){
//         summ=summ+arr[j];
//         if(summ<0){
//             summ=0;
//         }
//         if(summ>maxsum){
//             maxsum=summ;
//         }
//         j++;
//     }
//     return maxsum;
// }


// int main(){
//     vector<int>arr={-2,-3,4,-1,-2,1,5,-3};
//     cout<<maxi(arr,arr.size());
//     return 0;
// }

// alternate numbers pos neg : brute
void alternate(vector<int>&arr,int size){
    vector<int>pos;
    vector<int>neg;
    for(int i=0;i<size;i++){
        if(arr[i]>0){
            pos.push_back(arr[i]);
        }
        else{
            neg.push_back(arr[i]);
        }
    }
    int p=0;int n=0;
    int k=0;
    while(p<pos.size() && n<neg.size()){
        arr[k]=pos[p];
        k++;
        p++;
        arr[k]=neg[n];
        k++;
        n++;
    }
    while(p<pos.size()){
        arr[k]=pos[p];
        p++;
        k++;
    }
    while(n<neg.size()){
        arr[k]=pos[n];
        n++;
        k++;
    }
}

//optimal 
vector<int> alte(vector<int>arr,int size){
    vector<int>ans(6,0);
    int j=0;
    int i=1;
    int k=0;
    while(k<size){
        if(arr[k]>0){
            ans[j]=arr[k];
            j+=2;
        }
        else{

            ans[i]=arr[k];
            i+=2;
        }
        k++;
    }
    return ans;
    
}
// int main(){
//     vector<int>arr={-5,6,-4,2,1,3};
//     alternate(arr,6);
//     print(arr,6);
//     return 0;
// }

//LEADERS IN AN ARRAY
vector<int> leaders(vector<int> arr,int size){
    vector<int>ans;
    for(int i=0;i<size;i++){
        bool leader=true;
        for(int j=i+1;j<size;j++){
            if(arr[i]<arr[j]){
                leader=false;
            }
        }
        if(leader==true){
            ans.push_back(arr[i]);
        }
    }
    return ans;
}

// two pointer approach

vector<int> leaders2(vector<int> arr,int size){
    vector<int>ans;
    int i=0,j=1;
    while(i<size){
        if(j>size-1){
            ans.push_back(arr[i]);
            i++;
            j=i+1;
        }
        if(arr[j]>arr[i]){
            i++;
            j=i+1;
        }
        else{
            j++;
        }
    }
    return ans;
}

// optimal
vector<int> leaders3(vector<int> arr,int size){
    vector<int>ans;
    int leader=INT_MIN;
    for(int i=size-1;i>=0;i--){
        if(arr[i]>leader){
            ans.push_back(arr[i]);
            leader=arr[i];
        }
    }
    return ans;
}

// int main(){
//     vector<int>arr={10,22,12,3,0,6};
//     vector<int>ans;
//     ans=leaders3(arr,6);
//     int size=ans.size();
//     print(ans,size);
//     return 0;
// }


// longest sequence
void merge(vector<int>&array,int s,int e){
    int mid=s+(e-s)/2;

    int len1=mid-s+1;
    int len2=e-mid;

    // making 2 new arrays
    int *first=new int(len1);
    int *second=new int(len2);

    // copying the array sorted elements into new arrays
    int mainarrayindex=s;
    for(int i=0;i<len1;i++){
        first[i]=array[mainarrayindex];
        mainarrayindex++;
    }

    mainarrayindex=mid+1;
    for(int i=0;i<len2;i++){
        second[i]=array[mainarrayindex];
        mainarrayindex++;
    }

    // merging the two sorted arrays
    int index1=0;
    int index2=0;
    mainarrayindex=s;
    while(index1<len1 && index2<len2){
        if(first[index1]<second[index2]){
            array[mainarrayindex]=first[index1];
            mainarrayindex++;
            index1++;
        }
        else{
            array[mainarrayindex]=second[index2];
            mainarrayindex++;
            index2++;
        }
    }
    while(index1<len1){
        array[mainarrayindex]=first[index1];
        mainarrayindex++;
        index1++;
    }
    while(index2<len2){
        array[mainarrayindex]=second[index2];
        mainarrayindex++;
        index2++;
    }

}

void mergesort(vector<int>&array,int s,int e){
    int mid=s+(e-s)/2;

    //base case
    if(s>=e){
        return;
    }

    //sorting left part of array
    mergesort(array,s,mid);
    mergesort(array,mid+1,e);
    merge(array,s,e);
}

int lngseq(vector<int>array,int size){
    mergesort(array,0,size-1);
    int cd=array[1]-array[0];
    int diff;
    int max=1;
    int count=1;
    for(int i=0;i<size-1;i++){
        diff=array[i+1]-array[i];
        if(diff==cd){
            count+=1;
        }
        else if(diff>cd){
            cd=diff;
            count=2;
        }
        if(count>max){
            max=count;
        }
    }
    return max;
}


// longest consecutive sequence : consecutive means diffference of 1
int lngconseq(vector<int>array,int size){
    mergesort(array,0,size-1);
    int cd=1;
    int count=1;
    int max=1;
    for(int i=0;i<size-1;i++){
        int diff=array[i+1]-array[i];
        if(diff==cd){
            count+=1;
        }
        else if(diff>cd){
            count=0;
        }
        if(count>max){
            max=count;
        }
    }
    return max;
}




// int main(){
//     vector<int> arr={102,4,100,1,101,3,2,2,1,1};
//     int size=arr.size();
//     int ans=lngconseq(arr,size);
//     cout<<"Longest sequence:"<<ans;
//     return 0;
// }

// REMOVE DUPLICATES FROM AN ARRAY: TWO POINTER APPROACH
void removedup(vector<int>&array){
    int i=0,j;
    for(int j=1;j<array.size();j++){
        if(array[j]!=array[j-1]){
            array[i+1]=array[j];
            i++;
        }
    }
}
// int main(){
//     vector<int>array={1,2,4,5,5,7,7,7};
//     removedup(array);
//     print(array,10);
// }

void movezeroes(vector<int>&arr){
    for(int i=0;i<arr.size();i++){
        if(arr[i]==0){
            for(int j=i+1;j<arr.size();j++){
                arr[j-1]=arr[j];
            }
            arr[arr.size()-1]=0;
        }
    }
}
// int main(){
//     vector<int>arr={1,0,2,3,2,0,0,4,5,1};
//     movezeroes(arr);
//     print(arr,10);
//     return 0;
// }

// union of two arrays
vector<int> unionarr(vector<int>&arr1,vector<int>arr2){
    int i=0,j=0;
    vector<int> un;
    while(i<arr1.size() && j<arr2.size()){
        if(arr1[i]<=arr2[j]){
            if(un.back()!=arr1[i] || un.size()==0){
                un.push_back(arr1[i]);
            }
            i++;
        }
        else{
            if(un.back()!=arr2[j]|| un.size()==0){
                un.push_back(arr2[j]);
            }
            j++;
        }
    }
    while(i<arr1.size()){
            if(un.back()!=arr1[i] || un.size()==0){
                un.push_back(arr1[i]);
            }
            i++;
    }
    while(j<arr2.size()){
            if(un.back()!=arr2[j] || un.size()==0){
                un.push_back(arr2[j]);
            }
            j++;
    }
    return un;
}
// int main(){
//     vector<int>arr1={1,1,2,3,4,5};
//     vector<int>arr2={2,3,4,4,5,6};
//     vector<int>ans=unionarr(arr1,arr2);
//     print(ans,ans.size());
//     return 0;
// }
vector<int> intersect(vector<int>&arr1,vector<int>arr2){
    vector<int>ans;
    int l1=arr1.size();
    int l2=arr2.size();
    int i=0,j=0;
    while(i<l1 && j<l2){
        if(arr1[i]<arr2[j]){
            i++;
        }
        else if(arr1[i]>arr2[j]){
            j++;
        }
        else{
            int el=arr1[i];
            ans.push_back(el);
            i++;
            j++;
        }
    }
    return ans;
}
int main(){
    vector<int>arr1={1,2,2,3,3,4,5,6};
    vector<int>arr2={2,3,3,5,6,6,7};
    vector<int>ans=intersect(arr1,arr2);
    print(ans,ans.size());
}

// count subarrays with xor value as k
class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        long ans=0;
        for(int i=0;i<arr.size();i++){
            int xorr=0;
            for(int j=i;j<arr.size();j++){
                xorr^=arr[j];
                if(xorr==k){
                    ans++;
                }
            }
        }
        return ans;
    }
};