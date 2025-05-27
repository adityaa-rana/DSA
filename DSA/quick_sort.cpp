#include<iostream>
using namespace std;

void swap(int *n1,int *n2){
    int t=*n1;
    *n1=*n2;
    *n2=t;
}

void print(int array[],int size){
    for(int i=0;i<size;i++){
        cout<<array[i]<<"\t";
    }
    cout<<endl;
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

int main(){
    int array[]={18,2,14,9,7,5,14,15};
    int size=8;
    quicksort(array,0,size-1);
    print(array,8);
    return 0;
}