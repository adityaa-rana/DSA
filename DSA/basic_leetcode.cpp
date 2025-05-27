// PROBLEM 7
// #include<iostream>
// using namespace std;
// int main(){
//     int num;
//     cout<<"enter number:";
//     cin>>num;
//     int rev=0;
//     while(num>0){
//         int rem=num%10;
//         rev=rev*10+rem;
//         num=num/10;
//     }
//     cout<<"Reversed number:"<<rev;
//     return 0;
// }

// #include<iostream>
// using namespace std;

// int main(){
//     for(int i=0;i<5;i++){
//         for(int i=0;i<5;i++){
//             cout<<"*";
//         }
//         cout<<endl;
//     }
//     return 0;
// }

// #include<iostream>
// using namespace std;

// int main(){
//     int num=1;
//     for(int i=0;i<5;i++){
//         for(int j=0;j<i+1;j++){
//             cout<<num;
//         }
//         cout<<endl;
//         num++;
//     }
//     return 0;
// }

// #include<iostream>
// using namespace std;
// int main(){
//     for(int i=0;i<5;i++){
//         int num=1;
//         for(int j=0;j<5-i;j++){
//             cout<<num;
//             num++;
//         }
//         cout<<endl;
//     }
//     return 0;
// }


//triangle
// #include<iostream>
// using namespace std;
// int main(){
//     for(int i=0;i<5;i++){
//         for(int j=0;j<5-i;j++){
//             cout<<" ";
//         }
//         for(int k=0;k<(2*i)+1;k++){
//             cout<<"*";
//         }
//         cout<<endl;
//     }
//     return 0;
// }

// inverted triangle

// #include<iostream>
// using namespace std;
// int main(){
//     for(int i=4;i>=0;i--){
//         for(int k=0;k<5-i;k++){
//             cout<<" ";
//         }
//         for(int j=0;j<(2*i)+1;j++){
//             cout<<"*";
//         }
//         cout<<endl;
//     }
//     return 0;
// }

// #include<iostream>
// using namespace std;
// int main(){
//     int num=1;
//     for(int i=0;i<5;i++){
//         for(int j=0;j<i+1;j++){
//             cout<<num;
//             if(num==1){
//                 num=0;
//             }
//             else if(num==0){
//                 num=1;
//             }
//         }
//         cout<<endl;
//     }
//     return 0;
// }

// #include<iostream>
// using namespace std;
// int main(){
//     long int num;
//     cout<<"Enter number:";
//     cin>>num;
//     int count=0;
//     while(num>0){
//         num=num/10;
//         count++;
//     }
//     cout<<count;
//     return 0;
// }

// #include<iostream>
// using namespace std;
// int main(){
//     long int num;
//     cin>>num;
//     long int dup=num;
//     long int rev=0;
//     while(num>0){
//         int rem=num%10;
//         rev=rev*10+rem;
//         num=num/10;
//     }
//     cout<<rev<<endl;
//     if(rev==dup){
//         cout<<"palindrome";
//     }
//     else{
//         cout<<"not a palindrome";
//     }
//     return 0;
// }

// checking prime number or not using shorter algorithm

// #include<iostream>
// using namespace std;
// int main(){
//     int num;
//     cin>>num;
//     for(int i=2;i*i<=num;i++){
//         if(num%i==0){
//             cout<<"Not a prime";
//             return 0;
//         }
//     }
//     cout<<"Prime number";
//     return 0;
// }

// PATTERN 12 STRIVER
// #include<iostream>
// using namespace std;

// int main(){
//     for(int i=0;i<4;i++){
//         int num=1;
//         for(int j=0;j<i+1;j++){
//             cout<<num;
//             num++;
//         }
//         for(int k=0;k<(3-i)*2;k++){
//             cout<<" ";
//         }
//         for(int p=0;p<i+1;p++){
//             num--;
//             cout<<num;
//         }
//         cout<<endl;
//     }
//     return 0;

// }

// #include<iostream>
// using namespace std;

// int main(){
//     for(int i=0;i<5;i++){
//         char word='A';
//         for(int j=0;j<5-i;j++){
//             cout<<word<<" ";
//             word++;
//         }
//         cout<<endl;
//     }
//     return 0;
// }

// GCD USING RECURSION
#include<iostream>
using namespace std;

int hcf(int n1,int n2){
    if(n1==0){
        return n2;
    }
    else if(n2==0){
        return n2;
    }
    else{
        if(n1>n2){
            hcf(n1-n2,n2);
        }
        else{
            hcf(n2-n1,n1);
        }
    }
}

int main(){
    cout<<hcf(25,5);
    return 0;
}