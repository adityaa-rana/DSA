#include<bits/stdc++.h>
using namespace std;

typedef struct doubly{
    int val;
    struct doubly* next;
    struct doubly* prev;

    doubly(int num){
        val=num;
        next=nullptr;
        prev=nullptr;
    }
}node;
class Solution {
  public:
    // Function to reverse a doubly linked list
    node* reverseDLL(node* head) {
        node* curr=head;
        node* back=nullptr;
        node* newhead=nullptr;
        while(curr){
            back=curr->prev;
            
            curr->prev=curr->next;
            curr->next=back;
            
            back=curr;
            newhead=curr;
            curr=curr->prev;
            
        }
        return newhead;
    }
};

