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


// void mergesort2(int array[],int s,int e){
//     if(s>=e){
//         return;
//     }
//     int mid=s+(e-s)/2;
//     mergesort2(array,s,mid);
//     mergesort2(array,mid+1,e);
//     merge2(array,s,e);
// }

int main(){
    int array[]={38,27,43,3,9,82,10};
    int size=7;
    mergesort(array,0,size-1);
    print(array,size);
}