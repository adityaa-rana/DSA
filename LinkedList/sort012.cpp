#include<bits/stdc++.h>
using namespace std;
//method 1

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
  public:
    Node* segregate(Node* head) {
        Node* zero = new Node(-1);
        Node* one = new Node(-1);
        Node* two = new Node(-1);

        Node* zerohead = zero;
        Node* onehead = one;
        Node* twohead = two;

        Node* curr = head;

        while (curr) {
            if (curr->data == 0) {
                zero->next = curr;
                zero = curr;
            }
            else if (curr->data == 1) {
                one->next = curr;
                one = curr;
            }
            else {
                two->next = curr;
                two = curr;
            }
            curr = curr->next;
        }

        // Connect the three sublists
        zero->next = (onehead->next) ? onehead->next : twohead->next;
        one->next = twohead->next;
        two->next = NULL; // important to terminate the list

        return zerohead->next;
    }
};
