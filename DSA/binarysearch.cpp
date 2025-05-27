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


void printa(int array[],int size){
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

//  binary search

// iterative method
int binarysearch1(vector<int>arr,int size,int k){
    int l=0;
    int h=size-1;
    int mid=l+(h-l)/2;
    while(l<=h){
        if(arr[mid]==k){
            return  mid;
        }
        else if(k>arr[mid]){
            l=mid+1;
        }
        else{
            h=mid-1;
        }
        mid=l+(h-l)/2;
    }
    return -1;
}

// recursive method
int binarysearch2(vector<int>arr,int l,int h,int k){
   
    if(l>h){
        return -1;
    }
     int mid=l+(h-l)/2;
    if(arr[mid]==k){
        return mid;
    }
    else if(k>arr[mid]){
        return binarysearch2(arr,mid+1,h,k);
    }
    else{
        return binarysearch2(arr,l,mid-1,k);
    }
}


// int main(){
//     vector<int>arr={3,4,6,7,9,12,16,17};
//     cout<<binarysearch2(arr,0,arr.size(),6);
//     return 0;
// }

int lowbound(vector<int>arr,int size,int num){
    int l=0;
    int h=size-1;
    int mid=l+(h-l)/2;
    int lbound=0;
    while(l<=h){
        if(arr[mid]<num){
            l=mid+1;
        }
        else{
            lbound=mid;
            h=mid-1;
        }
        mid=l+(h-l)/2;
    }
    return lbound;
}

// int main(){
//     vector<int>arr={1,2,3,3,7,8,9,9,11};
//     cout<<lowbound(arr,arr.size(),4);
//     }

// floor and ceil using binary search

int ceil(vector<int>arr,int size,int num){
    int l=0;
    int h=size-1;
    int mid=l+(h-l)/2;
    int ans=-1;
    while(l<=h){
        if(arr[mid]<num){
            l=mid+1;
        }
        else{
            ans=mid;
            h=mid-1;
        }
        mid=l+(h-l)/2;
    }
    return ans;
}

int floor(vector<int>arr,int size,int num){
    int l=0;
    int h=size-1;
    int mid=l+(h-l)/2;
    int ans=-1;
    while(l<=h){
        if(arr[mid]>num){
            h=mid-1;
        }
        else{
            ans=mid;
            l=mid+1;
        }
        mid=l+(h-l)/2;
    }
    return ans;
}

// int main(){
//     vector<int>arr={0,10,20,30,40,50,60};
//     cout<<ceil(arr,arr.size(),-5);
//     return 0;
// }

vector<int> firstandlast(vector<int>arr,int size,int num){
    vector<int>ans;
    int first,el,last;
    int count=0;
    for(int i=0;i<size;i++){
        if(arr[i]==num){
            el=i;
            count++;
        }
    }
    if(count==1){
        first=el;
        last=el;
    }
    else if(count==0){
        first=-1;
        last=-1;
    }
    else{
        last=el;
        first=el-count+1;
    }
    
    ans.push_back(first);
    ans.push_back(last);
    return ans;
}
// int main(){
//     vector<int> arr={2,4,6,8,8,8,11,13};
//     vector<int>ans=firstandlast(arr,arr.size(),8);
//     print(ans,2);
//     return 0;
// }

int firstocc(vector<int>arr,int size,int num){
    vector<int>ans;
    int first,mid;
    int l=0;
    int h=size-1;
    while(l<=h){
        mid=l+(h-l)/2;
        if(arr[mid]>num){
            h=mid-1;
        }
        else if(arr[mid]<num){
            l=mid+1;
        }
        else{
            first=mid;
            h=mid-1;
        }
    }
    return first;
}

// int main(){
//     vector<int> arr={2,4,6,8,8,8,11,13};
//     cout<<firstocc(arr,arr.size(),8);
//     return 0;
// }

// find element in a rotated sorted array using binary search

int searchi(vector<int>arr,int size,int num){
    int l=0;
    int h=size-1;
    while(l<=h){
        int mid=l+(h-l)/2;
        if(arr[mid]==num){
                return mid;
            }
        // left half sorted
        if(arr[mid]>=arr[l]){
            if(arr[mid]>=num && num>=arr[l]){
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        else if(arr[mid]<=arr[h]){
            if(arr[mid]<=num && num<=arr[h]){
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }
    }
    return -1;
}

// int main(){
//     vector<int> arr={7,8,9,1,2,3,4,5,6};
//     cout<<searchi(arr,arr.size(),1);
//     return 0;
// }


