#include<bits/stdc++.h>
using namespace std;
bool lemonadeChange(vector<int>& bills) {
        int five=0,ten=0;
        int i=0;
        bool ans=true;
        while(i<bills.size()){
            if(bills[i]==5){
                five++;
            }
            else if(bills[i]==10){
                if(five>0){
                    ten++;
                    five--;
                }
                else{
                    ans=false;
                }
            }
            else{
                if(five>0 && ten>0){
                    five--;
                    ten--;
                }
                else if(five>=3){
                    five=five-3;
                }
                else{
                    ans=false;
                }
            }
            i++;
        }
        return ans;
    }