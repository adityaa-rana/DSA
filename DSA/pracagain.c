#include<stdio.h>
void swap(int *n1,int *n2){
    int t=*n1;
    *n1=*n2;
    *n2=t;
}
void quicksort(int arr[],int l,int h){
    int pivot=l;
    int s=pivot+1;
    int b=h;
    int flag=-1;
    while(flag==-1){
        if(arr[s]>arr[pivot] && arr[b]<arr[pivot]){
            if(s>=b){
                swap(&arr[pivot],&arr[s]);
                flag=1;
            }
            else{
                swap(&arr[s],&arr[b]);
                s++;
                b--;
            }
        }
        else if(arr[s]>arr[pivot] ){
            b--;
        }
        else if(arr[b]<arr[pivot]){
            s++;
        }
    }

    pivot=s;
    quicksort(arr,l,pivot-1);
    quicksort(arr,pivot+1,h);
}
void print(int array[],int size){
    for(int i=0;i<size;i++){
        printf("%d",array[i]);
    }
    printf("\n");
}
int main(){
    int arr[]={8,6,9,7,1,2,3,5};
    quicksort(arr,0,7);
    print(arr,8);
}