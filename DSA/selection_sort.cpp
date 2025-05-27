#include<bits/stdc++.h>
using namespace std;

void print(int array[],int size){
    for(int i=0;i<size;i++){
        cout<<array[i]<<"\t";
    }
    cout<<endl;
}

// selection sort : very large time complexity
// TO SORT AN ARRAY in ascending order


void sel_sort(int array[],int size){
    for(int i=0;i<size;i++){
        int min=array[i];
        for(int j=i+1;j<size;j++){
            if(array[j]<min){
                int t=array[i];
                array[i]=array[j];
                array[j]=t;
            }
        }
    }
}

// int main(){
//     int array[]={13,46,24,52,20,9};
//     sel_sort(array,6);
//     print(array,6);
//     return 0;    
// }

// BUBBLE SORT: same very large time complexity like selection sort

void bubble_sort(int array[],int size){
    for(int i=0;i<size;i++){
        // int count=0; 
        for(int j=0;j<size-i-1;j++){
            if(array[j]>array[j+1]){
                int t=array[j];
                array[j]=array[j+1];
                array[j+1]=t;
                // count++; 
            }
        }
        // if(count==0){
        //      break;
        //  }


    }
}
// int main(){
//     int array[]={13,46,24,52,20,9};
//     sel_sort(array,6);
//     print(array,6);
//     return 0;    
// }



// INSERTION SORT

void insertion_sort(int array[],int size){
    for(int i=0;i<size;i++){
        int j=i;
        while(j>0 && array[j]<array[j-1]){
            int t=array[j];
            array[j]=array[j-1];
            array[j-1]=t;
            j--;
        }
    }
}
    


// int main(){
//     int array[]={13,46,24,52,20,9};
//     insertion_sort(array,6);
//     print(array,6);
//     return 0;    
// }

// sorting an array using selection sort
// void sort(int array[],int size){
//     for(int i=0;i<size;i++){
//         int min=array[i];
//         for(int j=i+1;j<size;j++){
//             if(array[j]<min){
//                 min=array[j];
//                 int temp=array[i];
//                 array[i]=array[j];
//                 array[j]=temp;
//             }
//              print(array,size);
//         }
       
//     }
// }

// int main(){
//     int array[]={12,6,5,7};
//     int size=sizeof(array)/sizeof(int);
//     sort(array,size);
//     return 0;
// }

// sorting using bubble sort


// void bubble(int array[],int size){
//     for(int i=1;i<size;i++){
//         int count=0;
//         for(int j=0;j<size-i;j++){
//             if(array[j]>array[j+1]){
//                 int t=array[j];
//                 array[j]=array[j+1];
//                 array[j+1]=t;
//                 count++; 
//             }
//         }
//         print(array,size);
//         if(count==0){
//             break;
//         }
//     }
// }
// int main(){
//     int array[]={12,8,14,9,16,21};
//     bubble(array,sizeof(array)/sizeof(int));
//     return 0;
    
// }

// void insertion(int array[],int size){
//     for(int i=1;i<size;i++){
//         int temp=array[i];
//         int j=i-1;
//         while(j>=0){

//             if(array[j]>temp){
//                 array[j+1]=array[j];
//             }
//             else{
//                 break;
//             }
//         }
//         array[j+1]=temp;
//         print(array,4);
//     }
// }

// int main(){
//     int array[]={7,12,4,3};
//     insertion(array,4);
//     return 0;
// }

// counting sort
void count_sort(int arr[],int size){
    int max=-1;
    // finding max
    for(int i=0;i<size;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    int freq[max+1]={0};
    for(int j=0;j<size;j++){
        freq[arr[j]]++;
    }
    int afreq[max+1];
    for(int i=0;i<max+1;i++){
        int sum=0;
        for(int j=0;j<=i;j++){
            sum+=freq[j];
        }
        afreq[i]=sum;
    }
    int ans[size];
    for(int i=size-1;i>=0;i--){
        int el=arr[i];
        ans[--afreq[el]]=el;
    }
    for(int i=0;i<size;i++){
        printf("%d ",ans[i]);
    }
}

int main(){
    int arr[]={1,6,5,8,3,2,5,5,4,3,6,4,0,1};
    count_sort(arr,14);
}
