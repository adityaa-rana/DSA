// printing name n times using recursion

// #include<iostream>
// using namespace std;

// void print(int n,int i){
//     if(i==n){
//         return;
//     }
//     cout<<"Aditya\n";
//     print(n,++i);
// }

// int main(){
//     print(6,0);
//     return 0;
// }


// #include<iostream>
// using namespace std;
// void count(int n){
//     if(n<1){
//         return;
//     }

//     count(n-1);
//     cout<<n<<"\t";
// }
// int main(){
//     count(7);
//     return 0;
// }


// FORWARD TRACING UP COUNTING 1 TO N
// #include<iostream>
// using namespace std;
// void count(int n,int i){
//     if(i>n){
//         return;
//     }
//     cout<<i<<"\t";
//     count(n,i+1);
// }

// int main(){
//     count(6,1);
//     return 0;
// }

// FORWARD TRACING DOWN COUNTING N TO 1
// #include<iostream>
// using namespace std;
// void count(int n,int i){
//     if(i>n){
//         return;
//     }
//     count(n,i+1);
//     cout<<i<<"\t";
// }

// int main(){
//     count(6,1);
//     return 0;
// }


//  BACKTRACING COUNTING DOWN FROM N TO 1
// #include<iostream>
// using namespace std;

// void downcount(int n){
//     if(n<1){
//         return;
//     }
//     cout<<n<<"\t";
//     downcount(n-1);
// }
// int main(){
//     downcount(7);
//     return 0;
// }

//  BACKTRACING COUNTING up 1 TO N
// #include<iostream>
// using namespace std;

// void downcount(int n){
//     if(n<1){
//         return;
//     }
//     downcount(n-1);
//     cout<<n<<"\t";
    
// }
// int main(){
//     downcount(7);
//     return 0;
// }

// SUM OF N NUMBERS USING BACK TRACING

// #include<iostream>
// using namespace std;
// int summ(int N){
//     int ans=0;
//     if(N==0){
//         return ans;
//     }
//     ans=N+summ(N-1);
//     return ans;
// }

// int main(){
//     cout<<summ(10);
//     return 0;
// }

//  backtracing using another code ===== better
// #include<iostream>
// using namespace std;

// int sum(int N){
//     if(N==1){
//         return 1;
//     }
//     int ans=N+sum(N-1);
//     return ans;
// }

// int main(){
//     cout<<sum(9);
//     return 0;
// }



// using forward tracing

// #include<iostream>
// using namespace std;

// int sum(int N,int i){
//     if(N==i){
//         return N;
//     }
//     return i+sum(N,i+1);
    
// }

// int main(){
//     cout<<sum(5,1);
//     return 0;
// }

// factorial
// #include<iostream>
// using namespace std;
// int fac(int N){
//     if(N==1){
//         return 1;
//     }
//     return fac(N-1)*N;
// }
// int main(){
//     cout<<fac(7);
//     return 0;
// }

// factorial forward tracing using iterator
// #include<iostream>
// using namespace std;

// int fac(int i,int num){
//     if(i==num){
//         return num;
//     }
//     return i*fac(i+1,num);
// }

// int main(){
//     cout<<fac(1,6);
//     return 0;
// }

// reversing an array using recursion
// #include<iostream>
// using namespace std;


// void revarray(int array[],int begin,int end){
//     if(begin>=end){
//         return;
//     }
//     int t=array[begin];
//     array[begin]=array[end];
//     array[end]=t;
//     revarray(array,begin+1,end-1);
// }
// int main(){
//     int array[]={5,4,3,2,1};
//     revarray(array,0,4);
//     for(int i=0;i<5;i++){
//         cout<<array[i]<<"\t";
//     }
//     return 0;
// }



// #include<iostream>
// using namespace std;
// void revarray(int array[],int i,int n){
//     if(i>=n-i-1){
//         return;
//     }
//     int t=array[i];
//     array[i]=array[n-i-1];
//     array[n-i-1]=t;
//     revarray(array,i+1,n);
// }
// int main(){
//     int array[]={5,4,3,2,1};
//     int num=sizeof(array)/sizeof(int);
//     revarray(array,0,num);
//     for(int i=0;i<5;i++){
//         cout<<array[i]<<"\t";
//     }
//     return 0;
// }

// check if a string is palindrome or not using recursion



// #include<string>
// #include<string.h>
// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;

// bool palindrome(char sample[],int i,int n){
//    if(i>=n-i-1){
//     return true;
//    }
//    if(sample[i]==sample[n-i-1]){
//     palindrome(sample,i+1,n);
//    }
//    else{
//         return false;
//    }
// }
// int main(){
//     char sample[]="adiida";
//     cout<<palindrome(sample,0,6);
//     return 0;
// }

// fibbonacci
// #include<iostream>
// using namespace std;

// int fibb(int n){
//     if(n==1){
//         return 0;
//     }
//     if(n==2){
//         return 1;
//     }
//     return fibb(n-1)+fibb(n-2);
// }

// #include<iostream>
// #include<string>
// using namespace std;

// void givename(int num,string array[]){
//     if(num<=0){
//         return;
//     }
//     givename(num/10,array);
//     int rem=num%10;
//     cout<<array[rem]<<" ";
    
// }

// int main(){
//     int num=36578;
//     string array[]={"zero","one","two","three","four","five","six","seven","eight","nine"};
//     givename(num,array);
//     return 0;
// }


#include<iostream>
using namespace std;
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

// LINEAR SEARCH USING RECURSION

// int search(int array[],int size,int target){
//     int index=size-1;
//     if(index<0){
//         return -1;
//     }
//     if(array[index]==target){
//         return index;
//     }
//     else{
//         search(array,--size,target);
//     }
// }

// int main(){
//     int array[]={4,3,6,98,8,5,2};
//     cout<<search(array,7,11);
//     return 0;
// }


// BINARY SEARCH USING RECURSION

// int binary(int array[],int s,int e,int target){
    
//     int mid=s+(e-s)/2;

//     if(s>e){
//         return -1;
//     }
//     if(array[mid]==target){
//         return mid;
//     }
//     else if(array[mid]>target){
//         return binary(array,s,mid-1,target);
//     }
//     else{
//         return binary(array,mid+1,e,target);
//     }
// }

// int main(){
//     int array[]={2,5,6,9,44,102,256};
//     cout<<binary(array,0,6,256);
//     return 0;
// }

// REVERSING A STRING USING RECUSRION
void swapchar(char* a,char* b){
    char temp=*a;
    *a=*b;
    *b=temp;
}
// void reverse(char sample[],int s,int e){
//     if(s>=e){
//         return;
//     }
//     swapchar(&sample[s],&sample[e]);
//     reverse(sample,s+1,e-1);
// }

// int main(){
//     char sample[]="heroine";
//     reverse(sample,0,6);
//     cout<<sample;
//     return 0;
// }

// checking palindrome

// int palindrome(char sample[],int s,int e){
//     if(s>=e){
//         return 1;
//     }
//     if(sample[s]!=sample[e]){
//         return 0;
//     }
//     palindrome(sample,s+1,e-1);
// }

// int main(){
//     char sample[]="opo";
//     cout<<palindrome(sample,0,2);
//     return 0;
// }


// power to the base

// int expo(int base,int power){

//     if(power==1){
//         return base;
//     }
//     base=base*expo(base,power-1);
// }

// int main(){
//     int base=6;
//     int power=3;
//     cout<<expo(base,power);
//     return 0;
// }

// BUBBLE SORT USING RECURSION

// void bubble(int array[],int size){
//     if(size<=1){
//         return;
//     }
//     for(int i=0;i<size-1;i++){
//         if(array[i]>array[i+1]){
//             swap(array[i],array[i+1]);
//         }
//     }
//     bubble(array,size-1);
// }

// int main(){
//     int array[]={4,5,9,3,2,4,1,5,2};
//     bubble(array,9);
//     print(array,9);
//     return 0;
// }


// SELECTION SORT USING RECURSION
// void selection(int array[],int size,int i){
//     if(i==size){
//         return;
//     }
//     for(int j=i;j<size;j++){
//         if(array[j]<array[i]){
//             swap(array[j],array[i]);
//         }
//     }
//     selection(array,size,i+1);
// }

// int main(){
//     int array[]={4,5,9,3,2,4,1,5,2};
//     selection(array,9,0);
//     print(array,9);
//     return 0;
// }
