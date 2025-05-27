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
#include<iostream>
using namespace std;

void print(int array[],int size){
    for(int i=0;i<size;i++){
        cout<<array[i]<<"\t";
    }
}

void merge(int array[],int s,int e){
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

void mergesort(int array[],int s,int e){
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


int partition(int array[],int s,int e){
    int pivot=array[s];
    int count=0;
    for(int i=s+1;i<=e;i++){
        if(array[i]<=pivot){
            count++;
        }
    }
    int pindex=s+count;
    swap(array[pindex],array[s]);
    
    int j=s;
    int k=e;
    while(k>pindex && j<pindex){
        while(array[j]<=pivot){
            j++;
        }
        while(array[k]>pivot){
            k--;
        }
        if(k>pindex && j<pindex){
            swap(array[k],array[j]);
            k--;
            j++;
        }
    }
    return pindex;
}
void quicksort(int array[],int s,int e){
    if(s>=e){
        return;
    }

    int p=partition(array,s,e);
    quicksort(array,s,p-1);
    quicksort(array,p+1,e);
}


// QUESTIONS
// MAXIMUM ELEMENT OF AN ARRAY

// int main(){
//     int array[]={4,7,5,12,0,1,36,78,51,25,44,4};
//     int size=sizeof(array)/sizeof(int);
//     quicksort(array,0,size-1);
//     cout<<array[size-1];
//     return 0;
// }

// int largest(int array[],int size){
//     int max=INT_MIN;
//     for(int i=0;i<size;i++){
//         if(array[i]>max){
//             max=array[i];
//         }
//     }
//     return max;
// }
// int main(){
//     int array[]={4,7,5,12,0,1,36,78,51,25,44,4};
//     int size=sizeof(array)/sizeof(int);
//     cout<<largest(array,size);
//     return 0;
// }

// SECOND LARGEST

int secondlar(int array[],int size){
    quicksort(array,0,size-1);
    int i=size-2;
    while(array[i]==array[size-1]){
        i=i-1;
    }
    return array[i];
}

int secondlar2(int array[],int size){
    int max=INT_MIN;
    int second=INT_MIN;
    for(int i=0;i<size;i++){
        if(array[i]>max){
            max=array[i];
        }
    }
    for(int i=0;i<size;i++){
        if(array[i]>second && array[i]<max){
            second=array[i];
        }
    }
    return second;
}

int secondlar3(int array[],int size){
    int max=array[0];
    int secmax=array[0];
    for(int i=0;i<size;i++){
        if(array[i]>max){
            secmax=max;
            max=array[i];
        }
        else if(array[i]>secmax && array[i]<max){
            secmax=array[i];
        }
    }
    return secmax;
}

// int main(){
//     int array[]={1,7,5,2,7,6,7};
//     int size=sizeof(array)/sizeof(int);
//     cout<<secondlar3(array,size);
//     return 0;
// }

// CHECK IS ARRAY IS SORTED
bool check(int array[],int size){
    for(int i=1;i<size;i++){
        if(array[i-1]>array[i]){
            return false;
        }
    }
    return true;
}
// int main(){
//     int array[]={1,2,3,4,8,6,7,8,10};
//     cout<<check(array,9);
//     return 0;
// }

vector<int> removedup(vector<int>&arr){
    int size=arr.size();
    vector<int>ans;
    int el=-1;
    for(int i=0;i<size;i++){
        if(arr[i]!=el){
            el=arr[i];
            ans.push_back(el);
        }
    }
    return ans;
}
void removedup2(vector<int>&arr){
    int i=0;
    int count=1;
    for(int j=1;j<arr.size();j++){
        if(arr[j-1]!=arr[j]){
            arr[i+1]=arr[j];
            i++;
            count++;
        }
    }
    cout<<count;
}

// int main(){
//     vector<int> arr={1,1,2,3,4,4,4,5,6,7,7,8};
//     removedup2(arr);
//     print(arr,arr.size());
//     return 0;
// }

//LEFT SHIFT BY K PLACES
void leftshift(vector<int>&arr,int k){
    for(int i=0;i<k;i++){
        int temp=arr[0];
        for(int j=1;j<arr.size();j++){
            arr[j-1]=arr[j];
        }
        arr[arr.size()-1]=temp;
    }
}

void leftshift2(vector<int>&arr,int k){
    vector<int>temp;
    for(int i=0;i<k;i++){
        temp.push_back(arr[i]);
    }
    for(int i=k+1;i<arr.size();i++){
        arr[i-k]=arr[i];
    }
    for(int j=0;j<k;j++){
        arr[arr.size()-k+j]=temp[j];
    }
}
// int main(){
//     vector<int> arr={1,2,3,4,5,6,7,8,9};
//     leftshift2(arr,3);
//     print(arr,9);
//     return 0;
// }

//MOVE ZEROES TO END
void movezeroes(vector<int>&arr,int size){
    vector<int>temp;
    for(int i=0;i<size;i++){
        if(arr[i]!=0){
            temp.push_back(arr[i]);
        }
    }
    for(int i=0;i<temp.size();i++){
        arr[i]=temp[i];
    }
    for(int j=temp.size();j<size;j++){
        arr[j]=0;
    }
}

void movezeroes2(vector<int>&arr,int size){
    int j=1;
    for(int i=j+1;i<size;i++){
        if(arr[i]!=0){
            swap(&arr[i],&arr[j]);
            j++;
        }
    }
}

// int main(){
//     vector<int>arr={1,0,2,3,2,0,0,4,5,1};
//     movezeroes2(arr,10);
//     print(arr,10);
//     return 0;
// }

// FIND MISSING NUMBER
int missing(vector<int>arr,int size){
    for(int i=1;i<size;i++){
        if(arr[i]-arr[i-1]!=1){
            return arr[i]-1;
        }
    }
    return -1;
}

int missing2(vector<int>arr,int size){
    int sum=0;
    for(int i=0;i<size;i++){
        sum+=arr[i];
    }
    int n=arr[size-1];
    return n*(n+1)/2-sum;
}

int missing3(vector<int>arr,int size){
    int exor=0;
    for(int i=0;i<size;i++){
        exor=exor^(i+1)^arr[i];
    }
    return exor^arr[size-1];

}
// int main(){
//     vector<int>array={1,2,3,5,6};
//     cout<<missing3(array,5);
//     return 0;
// }

int consone(vector<int>arr,int size){
    int count=0;
    int max=0;
    for(int i=0;i<size;i++){
        if(arr[i]==1){
            count++;
        }
        else{
            count=0;
        }
        if(count>max){
            max=count;
        }
    }
    return max;
}
// int main(){
//     vector<int> arr={1,1,0,0,1,1,1,0,1,1};
//     cout<<consone(arr,10);
//     return 0;
// }

/// finding the number that appear once in an array containing duplets
// int single(vector<int> arr,int size){
//     map<int,int> mpp;
//     for(int i=0;i<6;i++){
//         mpp[i+1]=0;
//     }
//     for(int i=0;i<size;i++){
//         mpp[arr[i]]++;
//     }
//     for(auto it:mpp){
//         if(it.second==1){
//             return it.first;
//         }
//     }
//     return -1;
// }
// int main(){
//     vector<int>arr={1,1,2,2,3,3,4,5,5,6,6};
//     int size=arr.size();
//     cout<<single(arr,size);
//     return 0;
// }

int longest(vector<int>array,int size,int k){
    int i=0;
    int j=0;
    int sum=array[i];
    int len=1;
    int glen=0;
    while(i<size){
        if(sum<k){
            i++;
            sum=sum+array[i];
        }
        else if(sum>k){
            sum=sum-array[j];
            j++;
        }
        else{
            len=i-j+1;
            sum=sum-array[j];
            j++;
        }
        if(len>glen){
            glen=len;
        }
    }
    return glen;
}
int longest2(vector<int>array,int size,int k){
    int len=0;
    int glen=0;
    for(int i=0;i<size;i++){
        int sum=0;
        for(int j=i;j<size;j++){
            sum+=array[j];
            if(sum==k){
                len=j-i+1;
            }
            if(len>glen){
                glen=len;
            }
        }
    }
    return glen;
}
// int main(){
//     vector<int>array={1,2,3,1,1,1,1,4,2,3};
//     cout<<longest2(array,array.size(),7);
//     return 0;
// }

// two sum :brute
bool twosum(vector<int>array,int size,int k){
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            if(array[i]+array[j]==k){
                cout<<i<<"and"<<j<<"\n";
                return true;
            }
        }
    }
    return false;
}
vector<int> twosum2(int array[],int size,int k){
   
    mergesort(array,0,size-1);
    int i=0;
    int j=size-1;
    while(i<=j){
        if(array[i]+array[j]>k){
            j--;
        }
        else if(array[i]+array[j]<k){
            i++;
        }
        else if(array[i]+array[j]==k){
            return {--i,++j};
        }
    }
    return {-1,-1};
}

vector<int> twosum3(vector<int>arr,int size,int k){
    map<int,int> hash;
    for(int i=0;i<size;i++){
        int el=arr[i];
        int req=k-el;
        if(hash.find(req)!=hash.end()){
            return {hash[req],i};
        }
        else{
            hash[el]=i;
        }
    }
    return {-1,-1};
}

// int main(){
//     int arr[]={2,6,5,11,8};
//     vector<int>ans=twosum2(arr,5,14);
//     print(ans,2);
//     return 0;
// }


// number appearing more than n/2 times
//brute
int num(vector<int>array,int size){
    for(int i=0;i<size;i++){
        int count=0;
        for(int j=0;j<size;j++){
            if(array[i]==array[j]){
                count++;
            }
        }
        if(count>size/2){
            return array[i];
        }
    }
    return -1;
}


// better hashing
int num2(vector<int>array,int size){
    map<int,int>hash;
    for(int i=0;i<size;i++){
        hash[array[i]]++;
    }
    for(auto it:hash){
        if(it.second>size/2){
            return it.first;
        }
    }
    return -1;
}
// int main(){
//     vector<int> arr={2,2,1,3,1,1,3,1,1};
//     cout<<num2(arr,9);
//     return 0;
// }

// sort am array containing 0,1,2 only

void sort(vector<int>&array,int size){
    int mid=0;
    int low=0;
    int high=size-1;
    while(high>=mid){
        if(array[mid]==0){
            swap(array[mid],array[low]);
            low++;
            mid++;
        }
        else if(array[mid]==1){
            mid++;
        }
        else{
            swap(array[mid],array[high]);
            high--;
        }
    }
}
// int main(){
//     vector<int>arr={0,1,1,0,1,2,1,2,0,0,0};
//     sort(arr,arr.size());
//     print(arr,arr.size());
//     return 0;
// }

int maxsum(vector<int> arr,int n){
    int sum=arr[0];
    int maxx=INT_MIN;
    int start=-1,end=-1;
    for(int i=1;i<n;i++){
        if(sum==0){
            start=i;
        }
        sum+=arr[i];
        if(sum<0){
            sum=0;
        }
        if(sum>maxx){
            maxx=sum;
            end=i;
        }
    }
    for(int i=start;i<=end;i++){
        cout<<arr[i]<<",";
    }
    cout<<endl;
    return maxx;

}

// int main(){
//     vector<int>arr={-2,-3,4,-1,-2,1,5,-3};
//     cout<<maxsum(arr,arr.size());
//     return 0;
// }

// leaders in an array

vector<int>leaders(vector<int>arr,int size){
    vector<int>ans;
    for(int i=0;i<size;i++){
        bool flag=true;
        for(int j=i+1;j<size;j++){
            if(arr[j]>arr[i]){
                flag=false;
            }
        }
        if(flag==true){
            ans.push_back(arr[i]);
        }
    }
    return ans;
}

vector<int> leaders2(vector<int>arr,int size){
    vector<int>ans;
    int max=INT_MIN;
    for(int i=size-1;i>=0;i--){
        if(arr[i]>max){
            max=arr[i];
            ans.push_back(max);
        }
    }
    return ans;
}

// int main(){
//     vector<int>arr={10,22,12,3,0,6};
//     vector<int>ans=leaders2(arr,arr.size());
//     print(ans,ans.size());
//     return 0;
// }

// rearrange elements by sign
 
// void rearrange(vector<int>&arr,int size){
//     vector<int>pos;
//     vector<int>neg;
//     for(int i=0;i<size;i++){
//         if(arr[i]>0){
//             pos.push_back(arr[i]);
//         }
//         else{
//             neg.push_back(arr[i]);
//         }
//     }
//     for(int i=0;i<size/2;i++){
//         arr.push_back(pos[i]);
//         arr.push_back(neg[i]);
//     }
//     for(int i=0;i<size;i++){
//         cout<<arr[i];
//     }
// }

vector<int> rearrange(vector<int>arr,int size){
    vector<int>ans(size);
    int k=0,j=1;
    for(int i=0;i<size;i++){
        if(arr[i]>0){
            ans[k]=arr[i];
            k+=2;
        }
        else{
            ans[j]=arr[i];
            j+=2;
        }
    }
    return ans;
}

// int main(){
//     vector<int>arr={3,1,-2,-5,2,-4};
//     vector<int>ans=rearrange(arr,arr.size());
//     print(ans,6);
//     return 0;
// }

// unequal num of pos and neg

// void rearrange2(vector<int>&arr,int size){
//     vector<int>pos;
//     vector<int>neg;
//     for(int i=0;i<size;i++){
//         if(arr[i]>0){
//             pos.push_back(arr[i]);
//         }
//         else{
//             neg.push_back(arr[i]);
//         }
//     }
//     int n=min(pos.size(),neg.size());
//     int i;
//     for(i=0;i<n;i++){
//         arr[2*i]=pos[i];
//         arr[2*i+1]=neg[i];
//     }
//     while(i<pos.size()){
//         arr[i]=pos[i];
//         i++;
//     }
//     while(i<neg.size()){
//         arr[i]=neg[i];
//         i++;
//     }
// }

// // int main(){
// //     vector<int>arr={3,7,-2,-5,2,6};
// //     rearrange2(arr,arr.size());
// //     print(arr,6);
// //     return 0;
// // }


// // element > n/3 times
// vector<int> max3(vector<int> arr,int size){
//     vector<int>ans;
//     for(int i=0;i<size;i++){
//         int k=0;
//         int count=0;
//         if(ans.size()==0 || ){
//             for(int j=0;j<size;j++){
//                 if(arr[j]==arr[i]){
//                     count++;
//                 }
//             }
//             if(count>size/3){
//                 ans.push_back(arr[i]);
//                 k+=1;
//             }
//         }
        
        
    
    
//     }
//     return ans;
// }

vector<int>max3(vector<int>arr,int size){
    map<int,int>hash;
    vector<int>ans;
    for(int i=0;i<size;i++){
        int el=arr[i];
        hash[el]++;
        if(hash[el]>size/3){
            ans.push_back(el);
        }
    }
    return ans;
    
}

int main(){
    vector<int>arr={1,1,1,3,2,2,2,2};
    vector<int>ans=max3(arr,arr.size());
    print(ans,ans.size());
    return 0;
}