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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp=head;
        int count=0;
        while(temp){
            count++;
            temp=temp->next;
        }
        int index=count-n;
        if(index==0){
            ListNode* temp=head;
            head=head->next;
            delete(temp);
            return head;
        }
        int curr=1;
        temp=head;
        while(curr!=index){
            temp=temp->next;
            curr++;
        }
        ListNode* remove=temp->next;
        temp->next=temp->next->next;
        delete(remove);
        return head;

    }
};

// method 2
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        // If fast is NULL, it means we need to delete the head
        if (fast == NULL) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        ListNode* slow = head;
        while (fast->next != NULL) {
            fast = fast->next;
            slow = slow->next;
        }

        ListNode* todelete = slow->next;
        slow->next = slow->next->next;
        delete todelete;
        return head;
    }
};


// sort linked list with 0s,1s,2s

