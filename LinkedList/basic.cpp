#include<bits/stdc++.h>
using namespace std;

typedef struct linkedlist{
    int val;
    struct linkedlist* next;
    linkedlist(int num){
        val=num;
        next=nullptr;
    }
}node;

node* create(vector<int>& arr){
    node* head=new node(arr[0]);
    node* mover=head;
    int i=1;
    while(i<arr.size()){
        node* temp=new node(arr[i]);
        mover->next=temp;
        mover=temp;
        i++;
    }
    return head;
}

void printnode(node* head){
    node* mover=head;
    while(mover){
        cout<<mover->val;
        printf("\t");
        mover=mover->next;
    }
}

int length(node* head){
    node* mover=head;
    int count=0;
    while(mover){
        count++;
        mover=mover->next;
    }
    return count;
}

// delete head 
node* deletehead(node* head){
    if(head==NULL) return head;
    node* temp=head;
    head=head->next;
    delete(temp);
    return head;
}


int main(){
    vector<int>arr={4,5,3,9,7};
    node* llist=create(arr);
    printnode(llist);
    return 0;
}