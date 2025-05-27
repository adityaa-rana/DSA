#include<iostream>
using namespace std;
int rev(int num){
    int revnum=0;
    while(num>0){
        int rem=num%10;
        revnum=revnum*10+rem;
        num=num/10;
    }
    return revnum;
}

int main(){
    cout<<rev(4012000);
    return 0;
}