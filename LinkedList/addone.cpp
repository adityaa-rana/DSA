#include<bits/stdc++.h>
using namespace std;

typedef struct Node {
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {}
    }Node;
class Solution {
public:

    Node* addOne(Node* head) {
        Node* mover = head;
        int num = 0;

        // Step 1: Convert linked list to integer
        while (mover) {
            num = num * 10 + mover->data;
            mover = mover->next;
        }

        // Step 2: Add one
        num++;

        // Step 3: Create new linked list from updated number
        // Edge case: num might be 0
        int temp = num;
        int divisor = 1;
        while (temp >= 10) {
            temp /= 10;
            divisor *= 10;
        }

        Node* newHead = nullptr;
        Node* tail = nullptr;

        while (divisor > 0) {
            int digit = num / divisor;
            num %= divisor;
            divisor /= 10;

            Node* newNode = new Node(digit);
            if (!newHead) {
                newHead = tail = newNode;
            } else {
                tail->next = newNode;
                tail = tail->next;
            }
        }

        return newHead;
    }
};

// method 2:
class Solution {
  public:
    Node* reverseList(Node* head) {
        Node* curr=head;
        Node* prev=nullptr;
        while(curr){
            Node* ahead=curr->next;
            curr->next=prev;
            prev=curr;
            head=curr;
            curr=ahead;

        }
        return head;
    }
    Node* addOne(Node* head) {
        Node* reversed=reverseList(head);
        int carry=1;
        Node* mover=reversed;
        Node* prev=nullptr;
        while(mover){
            int num=mover->data;
            num++;
            if(num<10){
                carry=0;
                mover->data=num;
                break;
            }
            else{
                carry=1;
                mover->data=0;
            }
            prev->next=mover;
            prev=mover;
            mover=mover->next;
        }
        if(carry==1){
            Node* newtail=new Node(1);
            prev->next=newtail;
        }
        head=reverseList(reversed);
        return head;
    }
};

// method 3 :
class Solution {
  public:
    int helper(Node* head){
        if(head==NULL){
            return 1;
        }
        int carry=helper(head->next);
        head->data+=carry;
        
        if(head->data<10){
            return 0;
        }
        head->data=0;
        return 1;
    }
    Node* addOne(Node* head) {
        int carry=helper(head);
        if(carry==1){
            Node* newhead=new Node(1);
            newhead->next=head;
            head=newhead;
        }
        return head;
    }
};