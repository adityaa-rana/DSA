#include<bits/stdc++.h>
using namespace std;

// void swap(int* a,int* b){
//     int temp=*a;
//     *a=*b;
//     *b=temp;
// }
// // print name 5 times using recursion
// void printname(int count){
//     if(count==5){
//         return;
//     }
//     cout<<"Aditya\n";
//     printname(count+1);
// }

// void upcounting(int i,int n){
//     if(i>n){
//         return;
//     }
//     cout<<i<<endl;
//     upcounting(i+1,n);
// }

// //upcounting using backtracking
// void upcount(int n){
//     if(n<1){
//         return;
//     }
//     upcount(n-1);
//     cout<<n<<endl;
// }


// void downcounting(int n){
//     if(n==0){
//         return;
//     }
//     cout<<n<<endl;
//     downcounting(n-1);
// }

// //downcounting using backtracking
// void downcount(int i,int n){
//     if(i>n){
//         return;
//     }
//     downcount(i+1,n);
//     cout<<i<<endl;
// }


// //                                                  sum of n numbers
// //method 1 non-parameterized

// int sum(int n){
//     if(n<1){
//         return n;
//     }
//     return n+sum(n-1);
// }

// //method 2 : parameterized way
// void sum2(int *ans,int n){
//     if(n<0){
//         return;
//     }
//     *ans=*ans+n;
//     sum2(ans,n-1);
// }


// //                                                  factorial of n

// //method 1 non-parameterized
// int factorial1(int n){
//     if(n<1){
//         return 1;
//     }
//     return n*factorial1(n-1);
// }

// //method 2 : parameterized way
// void factorial2(int ans,int n){
//     if(n<1){
//         cout<<ans;
//         return;
//     }
//     factorial2(ans*n,n-1);
// }

// // reverse an array using recursion
// #include <iostream>
// #include <vector>
// using namespace std;

// vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
// int len = arr.size();

// void reverse(vector<int>* arr, int i, int n) {
//     if (i > n) {
//         return;
//     }
//     swap((*arr)[i], (*arr)[n-1]); 
//     reverse(arr, i+1, n-1);
// }
// // more optimization using only one pointer
// void reverse2(vector<int>* arr, int i) {
//     if (i >= len/2) {
//         return;
//     }
//     swap((*arr)[i], (*arr)[len-i-1]); 
//     reverse2(arr, i+1);
// }

// //check if a string is palindrome using recursion
// string sample="mahham";
// int strln=sample.length();
// bool palindrome(int i){
//     if(i>=strln){
//         return true;
//     }
//     if(sample[i]!=sample[strln-i-1]){
//         return false;
//     }
//     palindrome(i+1);
// }

// // fibonacci series using recursion
// int fibb(int n){
//     if(n==0 | n==1){
//         return n;
//     }
//     return fibb(n-1)+fibb(n-2);
// }

// // print all subsequences of a given array
// vector<int>arr1={3,1,2,4};
// int n=arr1.size();
// void subseq(int index,vector<int>ans){
//     if(index==n){
//         for(int i=0;i<ans.size();i++){
//             cout<<ans[i];
//         }
//         printf("\n");
//         return;
//     }
//     ans.push_back(arr1[index]);
//     subseq(index+1,ans);
//     ans.pop_back();
//     subseq(index+1,ans);
// }

// // printing all subsequences with a given sum k

// vector<int>arr2={1,2,1};
// int n2=arr2.size();
// void subseqsum(int index,vector<int>ans,int sum,int k){
//     if(index==n2){
//         if(sum==k){
//             for(int i=0;i<ans.size();i++){
//                 cout<<ans[i];
//             }
//             printf("\n");
//         }
//         return;
//     }
    
//     ans.push_back(arr2[index]);
//     sum+=arr2[index];
//     subseqsum(index+1,ans,sum,k);
//     ans.pop_back();
//     sum-=arr2[index];
//     subseqsum(index+1,ans,sum,k);
// }

// // int  main(){
// //     vector<int>ans;
// //     subseqsum(0,ans,0,2);
// //     return 0;
// // }

// // PRINTING ONLY 1 SUBSEQUENCE
// bool subseqsum2(int index,vector<int>ans,int sum,int k){
//     if(index==n2){
//         if(sum==k){
//             for(int i=0;i<ans.size();i++){
//                 cout<<ans[i]<<'\t';
//             }
//             return true;
//         }

//         else{
//             return false;
//         }
//     }
    
//     ans.push_back(arr2[index]);
//     sum+=arr2[index];
//     if(subseqsum2(index+1,ans,sum,k)==true){
//         return true;
//     };
//     ans.pop_back();
//     sum-=arr2[index];
//     if(subseqsum2(index+1,ans,sum,k)==true){
//         return true;
//     }
//     return false;
// }



// //count the number of subsequences with sum k

// int countsubseq(int index,vector<int>ans,int sum,int k,int count){
//     if(index==n2){
//         if(sum==k){
//             return 1;
//         }
//         else{
//             return 0;
//         }
//     }
//     ans.push_back(arr2[index]);
//     sum+=arr2[index];
//     int l=countsubseq(index+1,ans,sum,k,count);

//     ans.pop_back();
//     sum-=arr2[index];
//     int r=countsubseq(index+1,ans,sum,k,count);

//     return l+r;
// }

// vector<int>arr3={2,3,6,7};
// int n3=arr3.size();


// //COMBINATION SUM
// void combination(int index,vector<int>ans,int target){
//     if(index==n3){
//         if(target==0){
//             for(int i=0;i<ans.size();i++){
//                 cout<<ans[i]<<'\t';
//             }
//             printf("\n");
//         }
//         return;
//     }
//     if(target>=arr3[index]){
//         ans.push_back(arr3[index]);
//         target-=arr3[index];
//         combination(index,ans,target);
//         ans.pop_back();
//         target+=arr3[index];
//     }
//     combination(index+1,ans,target);
// }
// // int  main(){
// //     vector<int>ans;
// //     combination(0,ans,7);
// //     return 0;
// // } 




// // combonation sum 2
// //BRUTE FORCE   

// void combination2(int index,vector<int>temp,int target,set<vector<int>> ans){
//     if(index==n3){
//         if(target==0){
//             ans.insert(temp);
//         }
//         return;
//     }
//     if(target>=arr3[index]){
//         temp.push_back(arr3[index]);
//         target-=arr3[index];
//         combination2(index+1,temp,target,ans);
//         temp.pop_back();
//         target+=arr3[index];
//     }
//     combination2(index+1,temp,target,ans);
// }

// // int main(){
// //     vector<int>temp;
// //     int target=8;
// //     set<vector<int>>ans;
// //     combination2(0,temp,target,ans);
// //     return 0;
// // }

// // combination sum 2
// // optimal approach
// vector<int>sample={1,1,1,2,2};
// int n =sample.size();
// void combsum2(int index,vector<int>ds,int target,vector<vector<int>>ans){
//     if(target==0){
//         ans.push_back(ds);
//         return;

//     }
//     for(int i=index;i<n-1;i++){
//         if(i>index && sample[i]==sample[i-1]){
//             continue;
//         }
//         if(sample[i]>target){
//             break;
//         }

//         ds.push_back(sample[index]);
//         target-=sample[index];
//         combsum2(index+1,ds,target,ans);

//         ds.pop_back();
//         target+=(sample[index]);
//     }
// }

// // SUBSET SUM 1
// vector<int>array1={3,1,2};
// int narr=array1.size();
// void subsum1(int index,int sum){
//     if(index==narr){
//         cout<<sum<<"\t";
//         return;
//     }
//     sum+=array1[index];
//     subsum1(index+1,sum);
//     sum-=array1[index];
//     subsum1(index+1,sum);
// }

// // to also print the subset : we can slightly modify the code as 
// void subsum1ndp(int index,vector<int>temp,int sum){
//     if(index==narr){
//         for(int i=0;i<temp.size();i++){
//             cout<<temp[i]<<' ';
//         }
//         cout<<":"<<sum<<"\n";
//         return;
//     }
//     temp.push_back(array1[index]);
//     sum+=array1[index];
//     subsum1ndp(index+1,temp,sum);

//     temp.pop_back();
//     sum-=array1[index];
//     subsum1ndp(index+1,temp,sum);
// }
// // int main(){
// //     vector<int>temp;
// //     subsum1ndp(0,temp,0);
// //     return 0;
// // }

// //subset 2 : to generate all unique subsets

// void findsubsets(int ind,vector<int> &nums,vector<int>ds,vector<vector<int>>ans){
//     ans.push_back(ds);
//     for(int i=ind;i<nums.size()-1;i++){
//         if(ind!=i && nums[i]==nums[i-1]){
//             continue;
//         }
//         ds.push_back(nums[i]);
//         findsubsets(i+1,nums,ds,ans);
//         ds.pop_back();
//     }
// }
// vector<vector<int>>subsets(vector<int>& nums){
//     vector<vector<int>>ans;
//     vector<int>ds;
//     sort(nums.begin(),nums.end());
//     findsubsets(0,nums,ds,ans);
//     return ans;
// } 

// vector<int> given2={1,2,2,2,3,3};
// int n2=given2.size();
// void subset2(int index,vector<int>ds){
//     if(index==n2){
//         for(int i=0;i<ds.size();i++){
//             cout<<ds[i]<<' ';
//         }
//         return;
//     }

//     for(int i=index;i<n2;i++){
//         if(i!=index && given2[i]==given2[i-1]){
//             continue;
//         }

//         ds.push_back(given2[i]);
//         subset2(i+1,ds);
//         ds.pop_back();
//     }
// }
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=*a;
}
// // PRINT ALL PERMUTATIONS OF A GIVEN ARRAY/STRING USING RECURSION
vector<int> a1={1,2,3};
int na1=a1.size();
// approach 1 without using map : USING SWAPPING

void permu1(int index){
    if(index==na1){
        for(int i=0;i<na1;i++){
            cout<<a1[i]<<' ';
        }
        printf("\n");
        return;
    }
    for(int i=index;i<na1;i++){
        swap(a1[index],a1[i]);
        permu1(index+1);

        //swapping back so that the other permutations in loop can start with the original array
        swap(a1[index],a1[i]);
    }
}


// approach 2 using a map
void permu2(vector<int>ds,int freq[]){
    if(ds.size()==na1){
        for(int i=0;i<ds.size();i++){
            cout<<ds[i]<<' ';
        }
        printf("\n");
        return;
    }
   for(int i=0;i<na1;i++){
    if(freq[i]==0){
        ds.push_back(a1[i]);
        freq[i]=1;
        permu2(ds,freq);
        freq[i]=0;
        ds.pop_back();
    }
   }
}
int main(){
    
    permu1(0);
    return 0;
}