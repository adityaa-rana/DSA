#include<bits/stdc++.h>
using namespace std;

typedef struct doubly{
    int val;
    struct doubly* next;
    struct doubly* back;

    doubly(int num){
        val=num;
        next=nullptr;
        back=nullptr;
    }
}node;

node* convert(vector<int>& arr){
    node* head=new node(arr[0]);
    node* prev=head;
    for(int i=1;i<arr.size();i++){
        node* temp=new node(arr[i]);
        prev->next=temp;
        temp->back=prev;
        prev=temp;
    }
    return head;
}

int main(){
    vector<int>arr={4,5,3,9,7};
    node* llist=convert(arr);
    return 0;
}

