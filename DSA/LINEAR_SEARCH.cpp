// SWAPPING ALTERNATE ELEMENTS OF AN ARRAY
// #include<iostream>
// using namespace std;

// void swaparray(int arr[],int s){
//     for(int i=0;i<=s-2;i+=2){
//             int t=arr[i];
//             arr[i]=arr[i+1];
//             arr[i+1]=t;
//     }
// }
// void printarray(int arr[],int s){
//     for(int i=0;i<s;i++){
//         printf("%d\t",arr[i]);
//     }
//     printf("\n");
// }
// int main(){
//     int array1[]={1,2,3,4,5,6};
//     int array2[]={1,2,3,4,5,6,7};
//     swaparray(array1,6);
//     swaparray(array2,7);
//     printarray(array1,6);
//     printarray(array2,7);
//     return 0;
// }

//FINDING UNIQUE ELEMENTS OF AN ARRAY
// #include<iostream>
// using namespace std;

// void unique(int array[],int size){
//     for(int i=0;i<size;i++){
//         int count=0;
//         for(int j=0;j<size;j++){
//             if(array[i]==array[j]){
//                 count++;
//             }
//         }
//         if(count==1){
//             cout<<array[i]<<"\t";
//         }
//     }
// }
// int main(){
//     int array[]={1,5,3,6,9,8,1,5,3,6,7,1,4};
//     int size=sizeof(array)/sizeof(int);
//     unique(array,size);
//     return 0;
// }

//          FINDING ONE UNIQUE ELEMENT IN AN ARRAY of duplicates
// #include<iostream>
// using namespace std;

// int unique(int array[],int size){
//     int i=0;
//     for(int j=0;j<size;j++){
//         i=i^array[j];
//     }
//     return i;
// }
// int main(){
//     int array[]={5,3,6,9,1,5,3,6,1};
//     int size=sizeof(array)/sizeof(int);
//     cout<<unique(array,size);
//     return 0;
// }


