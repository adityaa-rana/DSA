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


// int main(){
//     int sample[4][4]={{1,1,1,1},{1,0,0,1},{1,1,0,1},{1,1,1,1}};
//     set<int>row;
//     set<int>col;
//     for(int i=0;i<4;i++){
//         for(int j=0;j<4;j++){
//             if(sample[i][j]==0){
//                 row.insert(i);
//                 col.insert(j);
//             }
//         }
//     }
//     for(auto it=row.begin();it!=row.end();it++){
//         for(int i=0;i<4;i++){
//             sample[*it][i]=0;
//         }
//     }
//     for(auto it=col.begin();it!=col.end();it++){
//         for(int i=0;i<4;i++){
//             sample[i][*it]=0;
//         }
//     }

//     for(int i=0;i<4;i++){
//         for(int j=0;j<4;j++){
//             cout<<sample[i][j]<<" ";
//         }
//         cout<<endl;
//     }

// }

// int main(){
//     int sample[4][4]={{1,1,1,1},{1,0,0,1},{1,1,0,1},{1,1,1,1}};
//     for(int i=0;i<4;i++){
//         for(int j=0;j<4;j++){
//             if(sample[i][j]==0){
//                 for(int k=0;k<4;k++){
//                     if(sample[i][k]!=0){
//                         sample[i][k]=-1;
//                     }
//                 }
//                 for(int k=0;k<4;k++){
//                     if(sample[k][j]!=0){
//                         sample[k][j]=-1;
//                     }
//                 }
//             }
//         }
//     }
//     for(int i=0;i<4;i++){
//         for(int j=0;j<4;j++){
//             if(sample[i][j]==-1){
//                 sample[i][j]=0;
//             }
//         }
//     }
//     for(int i=0;i<4;i++){
//         for(int j=0;j<4;j++){
//             cout<<sample[i][j]<<" ";
//         }
//         cout<<endl;
//     }
    
// }


// ROTATE MATRIX BY 90 DEGREE CLOCKWISE
void rotate(int arr[][4],int r,int c){
    int ans[r][c];
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            ans[i][j]=arr[4-j-1][i];
        }
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            printf("%d ",ans[i][j]);
        }
        cout<<endl;
    }
}
void rotate2(int arr[][4],int r,int c){
    for(int i=0;i<2;i++){
        for(int j=i+1;j<4;j++){
            if(i!=j){
                swap(arr[i][j],arr[j][i]);
            }
        }
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            printf("%d ",arr[i][j]);
        }
        cout<<endl;
    }
}
// int main(){
//     int arr[4][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
//     rotate2(arr,4,4);

// }

