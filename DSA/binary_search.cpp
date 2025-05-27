// CONDITION : for binary search ; elements should be in monotonic order , either in ascending or descending order 
// #include<bits/stdc++.h>
// using namespace std;

// int binarysearch(int array[],int size,int key){
//     int start=0;
//     int end=size-1;
//     int mid=start+(end-start)/2;

//     while(start<=end){
//         if(key==array[mid]){
//             return mid;
//         }
//         if(key>array[mid]){
//             start=mid+1;
//         }
//         else{
//             end=mid-1;
//         }
//         mid=start+(end-start)/2;

//     }
//     return -1;
// }

// int main(){
//     int evenlist[]={12,45,36,44,78,96};
//     int oddlist[]={12,36,54,77,98};
//     int even=binarysearch(evenlist,6,71);
//     int odd=binarysearch(oddlist,5,12);
//     cout<<even<<endl;
//     cout<<odd<<endl;
//     return 0;
// }

// QUESTION : TO FIND THE FIRST AND LAST POSITION OF AN ELEMENT IN A SORTED ARRAY
// USING LINEAR SEARCH

// #include<bits/stdc++.h>
// using namespace std;

// void search(int array[],int size,int key){
//     int first,last;
//     for(int i=0;i<size;i++){
//         if(array[i]==key){
//             first=i;
//             int j=first;
//             int count=0;
//             while(array[j]==array[i]){
//                 count++;
//                 j++;
//             }
//             last=count;
//             break;
//         }
//     }
    
//     cout<<"First:"<<first<<endl;
//     cout<<"Last:"<<last<<endl;
// }
// int main(){
//     int array[]={4,12,12,12,16,22,45,78,96,99};
//     int size=sizeof(array)/sizeof(int);
//     search(array,size,12);
//     return 0;
// }

// USING BINARY SEARCH

// #include<bits/stdc++.h>
// using namespace std;

// int firstocc(int array[],int size,int key){
//     int ans;
//     int start=0;
//     int end=size-1;
//     int mid=start+(end-start)/2;
//     while(start<=end){
//         if(array[mid]>key){
//             end=mid-1;
//         }
//         else if(array[mid]<key){
//             start=mid+1;
//         }
//         else if(key==array[mid]){
//             ans=mid;
//             end=mid-1;
//         }
//         mid=start+(end-start)/2;
//     }
//     return ans;
// }

// int lastocc(int array[],int size,int key){
//     int ans;
//     int start=0;
//     int end=size-1;
//     int mid=start+(end-start)/2;
//     while(start<=end){
//         if(array[mid]>key){
//             end=mid-1;
//         }
//         else if(array[mid]<key){
//             start=mid+1;
//         }
//         else if(array[mid]==key){
//             ans=mid;
//             start=mid+1;
//         }
//         mid=start+(end-start)/2;
//     }
//     return ans;
// }


// int main(){
//     int array[8]={0,0,1,1,2,2,2,2};
//     cout<<firstocc(array,8,2)<<endl;
//     cout<<lastocc(array,8,2);
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;

// int firstocc(vector<int> arr,int size,int key){
//     int ans;
//     int start=0;
//     int end=size-1;
//     int mid=start+(end-start)/2;
//     while(start<=end){
//         if(arr[mid]==key){
//             ans=mid;
//             end=mid-1;
//         }
//         else if(arr[mid]<key){
//             start=mid+1;
//         }
//         else if(arr[mid]>key){
//             end=mid-1;
//         }
//        mid= start+(end-start)/2;
//     }
//     return ans;
// }

// int lastocc(vector<int> arr,int size,int key){
//     int ans;
//     int start=0;
//     int end=size-1;
//     int mid=start+(end-start)/2;
//     while(start<=end){
//         if(arr[mid]==key){
//             ans=mid;
//             start=mid+1;
//         }
//         else if(arr[mid]<key){
//             start=mid+1;
//         }
//         else if(arr[mid]>key){
//             end=mid-1;
//         }
//        mid= start+(end-start)/2;
//     }
//     return ans;
// }

// pair<int,int>index(vector<int>arr,int size,int key){
//     int first=firstocc(arr,size,key);
//     int last=lastocc(arr,size,key);
//     cout<<"FIRST INDEX:"<<first<<endl;
//     cout<<"LAST INDEX:"<<last<<endl;
//     cout<<"TOTAL OCCURENECES:"<<(last-first)+1;
//     return {first,last};
    
// }

// int main(){
//     vector<int> arr={0,0,1,1,2,2,2,2};
//     int size=arr.size();
//     index(arr,size,2);
//     return 0;

// }

// FINDING INDEX OF PEAK ELEMENT IN MOUNTAIN ARRAY
// #include<bits/stdc++.h>
// using namespace std;

// int peak(int array[],int size){
    // int start=0;
    // int end=size-1;
    // int mid=start+(end-start)/2;
    // int ans;
    // while(start<end){
    //     if(array[mid]<array[mid+1]){
    //         start=mid+1;
    //     }
    //     else if(array[mid]<array[mid-1]){
    //         end=mid-1;
    //     }
    //     else{
    //         ans=mid;
    //         break;
    //     }
    //     mid=start+(end-start)/2;
    // }
    // return ans;
// }

// int main(){
//     int array[]={1,3,5,7,4};
//     cout<<"Peak element index:"<<peak(array,5);
//     return 0;
// }


// FINDING PIVOT IN A ROTATED SORTED ARRAY
// #include<bits/stdc++.h>
// using namespace std;

// int pivot(int array[],int size){
//     int start=0;
//     int end=size-1;
//     int mid=start+(end-start)/2;
//     while(start<end){
//         if(array[mid]>array[0]){
//             start=mid+1;
//         }
//         else{
//             end=mid;
//         }
//     mid=start+(end-start)/2;
//     }
//     return mid;
// }

// int main(){
//     int array[]={7,9,1,2,3,4,6};
//     cout<<"INDEX OF PIVOT ELEMENT:"<<pivot(array,7);
//     return 0;
// }

// now we can search an element in sorted array using binary search , but in a sorted but rotated array( which now becomes unsorted) is 
// but in two different segments separated by the pivot : so :
// #include<bits/stdc++.h>
// using namespace std;

// int pivoted(int array[],int size){
//     int s=0;
//     int e=size-1;
//     int m=s+(e-s)/2;
//     while(s<e){
//         if(array[m]>array[0]){
//             s=m+1;
//         }
//         else{
//             e=m;
//         }
//         m=s+(e-s)/2;
//     }
//     return m;
// }

// int binary_search(int array[],int size,int key,int start,int end){
//     int mid=start+(end-start)/2;
//         while(start<=end){
//             if(key<array[mid]){
//                 end=mid-1;
//             }
//             else if(key>array[mid]){
//                 start=mid+1;
//             }
//             else if(key==array[mid]){
//                 return mid;
//                 break;
//             }
//             mid=start+(end-start)/2;
//         }
//     return -1; 
// }

// int search(int array[],int size,int key){
//     int pivot=pivoted(array,size);
//     if(key<=array[size-1] && key>=array[pivot]){
//         int start=pivot;
//         int end=size-1;
//         return binary_search(array,size,key,start,end);
//     }
//     else{
//         int start=0;
//         int end=pivot-1;
//         return binary_search(array,size,key,start,end);
//     }
// }

// int main(){
//     int array[]={7,9,11,1,2,4,5,5};
//     cout<<search(array,8,1);
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;

// int sqroot(int num){
//     int start=1;
//     int end=num;
//     int mid=start+(end-start)/2;
//     int ans;
//     while(start<end){
//         if(mid*mid<=num){
//             ans=mid;
//             start=mid+1;
//         }
//         else if(mid*mid>num){
//             end=end-1;
//         }
//         mid=start+(end-start)/2;
//     }
//     return ans;
// }

// int main(){
//     cout<<sqroot(62);
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
//  BOOK ALLOCATION PROBLEM
int summ(int array[],int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum=sum+array[i];
    }
    return sum;
}
// bool possiblesolution(int arr[],int n,int m,int mid){
//     int student=1;
//     int pagesum=0;
//     for(int i=0;i<n;i++){
//         if(pagesum+arr[i]<=mid){
//             pagesum+=arr[i];
//         }
//         else{
//             student++;
//             if(arr[i]>mid || student>m){
//                 return false;
//             }
//             pagesum=arr[i];
//         }
//     }
//     return true;
// }

// int allomin(int pages[],int n,int m){
//     int e=summ(pages,n);
//     int s=0;
//     int mid=s+(e-s)/2;
//     int ans=-1;
//     while(s<=e){
//         if(possiblesolution(pages,n,m,mid)){
//             ans=mid;
//             e=mid-1;
//         }
//         else{
//             s=mid+1;
//         }
//         mid=s+(e-s)/2;
//     }
//     return ans;
    
// }
// int main(){
//     int pages[]={10,20,30,40};
//     int m=2;
//     int n=4;
//     cout<<allomin(pages,n,m);
// }



// PAINTER PARTITION PROBLEM:  there is an array no. of boards in each box and no. of boxes is array , similar to previos one, 
// now one board takes one unit of time, we have to distribute boards to k painters in such a way that time required
// to paint in minimum , means maximum no of boards distributed is minimum
// bool possiblesoln(int boards[],int size,int k,int mid){
//     int boardcount=0;
//     int painters=1;
//     for(int i=0;i<size;i++){
//         if(boardcount+boards[i]<=mid){
//             boardcount=boardcount+boards[i];
//         }
//         else{
//             painters++;
//             if(painters>k || boards[i]>mid){
//                 return false;
//             }
//             boardcount=boards[i];
//         }
//     }
//     return true;
    
// }

// int mintime(int boards[],int size,int k){
//     int s=0;
//     int e=summ(boards,size);
//     int mid=s+(e-s)/2;
//     int ans=-1;
//     while(s<=e){
//         if(possiblesoln(boards,size,k,mid)){
//             ans=mid;
//             e=mid-1;
//         }
//         else{
//             s=mid+1;
//         }
//         mid=s+(e-s)/2;
//     }
//     return ans;
// }
// int main(){
//     int boards[]={5,5,5,5};
//     int k=2;// k= no. of painters
//     int size=4;
//     cout<<mintime(boards,4,2);
// }

// AGGRESSIVE COWS
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

bool possiblesol(int stalls[],int size,int cows,int mid){
    int cowcount=1;
    int firstpos=stalls[0];
    for(int i=0;i<size;i++){
        if(stalls[i]-firstpos>=mid){
            cowcount++;
            if(cowcount==cows){
                return true;
            }
            firstpos=stalls[i];
        }
    }
    return false;

}
int diff(int stalls[],int n,int cows){
    sel_sort(stalls,n);
    int s=0;
    int maxx=-1;
    for(int i=0;i<n;i++){
        maxx=max(maxx,stalls[i]);
    }
    int e=maxx;
    int ans=-1;
    int mid=s+(e-s)/2;
    while(s<=e){
        if(possiblesol(stalls,n,cows,mid)){
            ans=mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
        mid=s+(e-s)/2;
    }
    return ans;
}

// int main(){
//     int stalls[]={4,2,1,3,6};
//     int cows=2;
//     int n=5;
//     cout<<diff(stalls,n,cows);
//     return 0;
// }

int rotatedbinary(vector<int> arr,int size,int k){
    int l=0;
    int h=size-1;
    int mid;
    while(l<=h){
        mid=l+(h-l)/2;
        if(arr[mid]==k){
            return mid;
        }
        else if(arr[l]<=arr[mid]){
            if(arr[mid]<=arr[h] && arr[mid]>=arr[l]){
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        else if(arr[mid]<arr[h]){
            if(arr[mid]<=arr[h] && arr[mid]>=arr[l]){
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
//     vector<int>arr={7,8,9,1,2,3,4,5};
//     cout<<rotatedbinary(arr,arr.size(),8);
//     return 0;
// }


//  minimum in rotated sorted array

int min(vector<int>arr,int size){
    int h=size-1;
    int l=0;
    int mid;
    while(l<=h){
        mid=(h+l)/2;
        if(arr[l]<arr[mid] && arr[mid]<arr[h]){
            return arr[l];
        }
        else if(arr[mid]<arr[mid+1] && arr[mid]<arr[mid-1]){
            return arr[mid];
        }
        //right half is sorted
        else if(arr[mid]<arr[h]){
            h=mid-1;
        }
        else if(arr[mid]>arr[l]){
            l=mid+1;
        }
    }
    return -1;
}

// int main(){
//     vector<int>arr={6,7,0,1,2,3,4,5};
//     cout<<min(arr,arr.size());
//     return 0;
// }

int single(vector<int>arr,int size){
    int h=size-2;
    int l=1;
    int mid;
    
    if(arr[l-1]!=arr[l]){
        return arr[l-1];
    }
    if(arr[h+1]!=arr[h]){
        return arr[h+1];
    }
    while(l<=h){
        mid=(l+h)/2;
        if(arr[mid]!=arr[mid-1] && arr[mid]!=arr[mid+1] ){
            return arr[mid];
        }
        
        else if(arr[mid]==arr[mid-1]){
            if((mid-l)%2==0){
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }
        else if(arr[mid]==arr[mid+1]){
            if((h-mid)%2==0){
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
    
    }
    return -1;
}

int single2(vector<int>arr,int size){
    int h=size-2;
    int l=1;
    int mid;
    if(size==1){
        return arr[0];
    }
    if(arr[0]!=arr[1]){
        return arr[0];
    }
    if(arr[size-1]!=arr[size-2]){
        return arr[size-1];
    }
    while(l<=h){
        mid=(l+h)/2;
        if(arr[mid]!=arr[mid-1] && arr[mid]!=arr[mid+1] ){
            return arr[mid];
        }
        

        if(mid%2==1 && arr[mid-1]==arr[mid]){
            l=mid+1;
        }
        else{
            h=mid-1;
        }
    }
    return -1;
}

int main(){
    vector<int>arr={1,1,2,2,3,3,4,5,5,6,6};
    cout<<single(arr,arr.size());
    return 0;
}