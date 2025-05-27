#include<bits/stdc++.h>
using namespace std;

class node{ 
    public:
    int data;
    node* next;

    public:
    node(int d1,node* n1){
        data=d1;
        next=n1;
    }
    node(int d1){
        data=d1;
        next=nullptr;
    }
};

node* arrtoll(vector<int> &arr){
    // declaring head with next as nullptr and it points to the first element,ll
    node* head=new node(arr[0]);
    // declaring a mover pointer pointing to head
    node *mover=head;
    for(int i=1;i<arr.size();i++){
        node* temp=new node(arr[i]);
        mover->next=temp;
        mover=mover->next;
    }
    return head;
}

int lenofll(node* head){
    int count=0;
    node* temp=head;
    while(temp){
        temp=temp->next;
        count++;
    }
    return count;
}

int search(node* head,int target){
    node* temp=head;
    while(temp){
        if(temp->data==target){
            return 1;
        }
        else{
            temp=temp->next;
        }
    }
    return 0;
}


// delete head of linked list
node* deletehead(node* head){
    // case of empty linked list
    if(head==NULL){
        return head;
    }
    node* temp=head;
    head=head->next;
    delete temp;
    return head;
}

node* deletetail(node* head){
    if(head==NULL || head->next==NULL){
        return NULL;
    }
    node* temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    delete(temp->next);
    temp->next=nullptr;
    return head;
}

node* deletek(node* head,int k){
    if(head==NULL){
        return NULL;
    }
    node* temp=head;
    node* prev=NULL;
    int count=1;
    while(count!=k && temp!=NULL){
        prev=temp;
        temp=temp->next;
        count++;
    }
    if(temp==head){
        deletehead(head);
    }
    else if(temp->next==NULL){
        deletetail(head);
    }
    else{
        node* res=temp;
        prev->next=prev->next->next;
        delete res;
        return head;

    }

}

node* deletekvalue(node* head,int k){
    if(head==NULL){
        return NULL;
    }
    node* temp=head;
    node* prev=NULL;
    while(temp->data!=k && temp!=NULL){
        prev=temp;
        temp=temp->next;
    }
    if(temp==head){
        deletehead(head);
    }
    else if(temp->next==NULL){
        deletetail(head);
    }
    else{
        node* res=temp;
        prev->next=prev->next->next;
        delete res;
        return head;
    }
}

// ------------------------------------------------------------------------------------------------------------------------------
node* newhead(node* head,int el){
    node* newhead=new node(el,head);
    return newhead;
}

node* newtail(node *head,int el){
    if(head==NULL){
        return new node(el,nullptr);
    }
    node* newtail=new node(el,nullptr);
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newtail;
    return head;
}

node* insertk(node* head,int k,int el){
    int count=1;
    node* temp=head;
    while(count<k-1){
        temp=temp->next;
        count++;
    }
    node* newel=new node(el);
    newel->next=temp->next;
    temp->next=newel;
    return head;
}


node* insertafterk(node* head,int el,int k){
    node* temp=head;
    while(temp->data!=k){
        temp=temp->next;
    }
    node* newl=new node(el,nullptr);
    newl->next=temp->next;
    temp->next=newl;
    return head;
}

node* insertbeforek(node* head,int el,int k){
    node* temp=head;
    node* prev=NULL;
    while(temp->data!=k){
        prev=temp;
        temp=temp->next;
    }
    node* newl=new node(el,nullptr);
    newl->next=temp;
    prev->next=newl;
    return head;
}

// ADD TWO NUMBERS STORED REVERSED IN LINKED LISTS AND STORE THEIR SUM (REVERSED) IN ANOTHER LINKED LIST
node* add2num(int n1,int n2){
    node* temph1=new node(-1,nullptr);
    node* temph2=new node(-1,nullptr);

    node* current1=temph1;
    node* current2=temph2;

    
    
    while(n1>0){
        node *next1=new node(-1);
        next1->data=n1%10;
        n1/=10;
        current1->next=next1;
        current1=next1;
    }
    while(n2>0){
        node *next2=new node(-1);
        next2->data=n2%10;
        n2/=10;
        current2->next=next2;
        current2=next2;
    }
    //NEW HEAD OF 2ND LINKED LIST
    node* res1=temph2->next;
    temph2->next=nullptr;
    delete temph2;

    //NEW HEAD OF 1ST LINKED LIST
    node* res2=temph1->next;
    temph1->next=nullptr;
    delete temph1;

    node* mover1=res1;
    node* mover2=res2;
    node* result=new node(-1);
    node* mover3=result;
    int carry=0;
    while(mover1!=NULL || mover2!=NULL){
        int sum=carry;
        if(mover1!=NULL){
            sum+=mover1->data;
        }
        if(mover2!=NULL){
            sum+=mover2->data;
        }
        carry=sum/10;
        sum%=10;
        node* temp=new node(sum);
        mover3->next=temp;
        mover3=mover3->next;

        if(mover1!=NULL){
            mover1=mover1->next;
        }
        else{
            mover1->data=0;
        }
        if(mover2!=NULL){
            mover2=mover2->next;
        }
        else{
            mover2->data=0;
        }
    }
    if(carry==1){
        node* temp=new node(carry);
        mover3->next=temp;
        mover3=mover3->next;
    }
    return result->next;
}



// odd and even linked list  SC=0(N) AND TC=0(N)

node* oddeven(node* sample){
    node* ans=new node(-1);
    node* mover=ans;
    node* current=sample;
    while(current!=NULL && current->next!=NULL){
        node* anstemp=new node(-1);
        anstemp->data=current->data;
        mover->next=anstemp;
        mover=mover->next;
        current=current->next->next;
        
    }
    if(current!=NULL){
        node* anstemp=new node(-1);
        anstemp->data=current->data;
        mover->next=anstemp;
        mover=mover->next;
    }
    current=sample->next;
    while(current!=NULL && current->next!=NULL){
        node* anstemp=new node(-1);
        anstemp->data=current->data;
        mover->next=anstemp;
        mover=mover->next;
        current=current->next->next;
        
    } 
    if(current!=NULL){
        node* anstemp=new node(-1);
        anstemp->data=current->data;
        mover->next=anstemp;
        mover=mover->next;
    }
    return ans->next;
    
}

// METHOD 2 : SHIFTING OF NODE LINKS

node* oddev(node* sample){
    node* odd=sample;
    node* even=sample->next;
    node* evhead=sample->next;
    while(even!=NULL && even->next!=NULL){
        odd->next=odd->next->next;
        odd=odd->next;
        even->next=even->next->next;
        even=even->next;
    }
    odd->next=evhead;

    return sample;
}

node* sort012(node* sample){
    node* zero=new node(-1);
    node* one=new node(-1);
    node* two=new node(-1);
    node* mover=sample;
    node* moverzero=zero;
    node* moverone=one;
    node* movertwo=two;
    while(mover!=NULL){
        if(mover->data==0){
            moverzero->next=mover;
            moverzero=mover;
        }
        else if(mover->data==1){
            moverone->next=mover;
            moverone=mover;
        }
        else{
            movertwo->next=mover;
            movertwo=mover;
        }
        mover=mover->next;
    }
    if(one->next!=NULL){
        moverzero->next=one->next;
    }
    else{ 
        moverzero->next=two->next;
    }
    moverone->next=two->next;
    movertwo->next=NULL;
    node* newhead=zero->next;
    delete one,two,zero;
    return newhead;
}

node* deletekfromlast(node* sample,int k){
    int len=0;
    node* mover=sample;
    while(mover!=NULL){
        len++;
        mover=mover->next;
    }
    if(k=1){
        deletetail(sample);
    }
    else if(k=len){
        deletehead(sample);
    }
    else{
        int prev=len-k;
        int j=1;
        mover=sample;
        while(j<prev){
            mover=mover->next;
            j++;
        }
        mover->next=mover->next->next;
    }
    return sample;
}

// reversing a linked list by reversing the links

// method 1: using a stack
node* revll1(node* head){
    stack<int> temp;
    node* mover=head;
    while(mover!=NULL){
        temp.push(mover->data);
        mover=mover->next;
    }
    mover=head;
    while(mover!=NULL){
        int a=temp.top();
        temp.pop();
        mover->data=a;
        mover=mover->next;
    }
    return head;
}

node* revll2(node* head){
    node* mover=head;
    node* prev=NULL;
    
    while(mover!=NULL){
        node* nxt=mover->next;
        mover->next=prev;
        prev=mover;
        mover=nxt;
    }
    return prev;

}

// checking palindrome in ll
// method 1: using a stack': tc=0(2n)and sc=0(n)

// method 2 : reversing second half of linked list and then using 2 pointers from front and back to check if equal

bool checkpal(node* head){
    // step 1: find the mid point of linked list
    node* slow=head;
    node* fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }

    // prev means mid
    node* mid=slow;
    node* prev=NULL;
    node* mover=slow->next;
    while(mover!=NULL){
        node* nxt=mover->next;
        mover->next=prev;
        prev=mover;
        mover=nxt;
    }
    node* l=head;
    node* r=prev;
    while(r!=NULL){
        if(l->data==r->data){
            l=l->next;
            r=r->next;
        }
        else{
            return false;
        }
    }
    return true;
}

// add 1 to number represented by nodes of linked list

node* addone(node* head){
    int num=0;
    node* mover=head;
    
    while(mover!=NULL){
        num=num*10+mover->data;
        mover=mover->next;
    }
  
    mover=head;
    num++;
    int rev=0;
   
    while(num>0){
        int r=num%10;
        rev=rev*10+r;
        num/=10;
    }
    
    while(rev!=0){
        
        mover->data=rev%10;
        rev=rev/10;
        mover=mover->next;
    }
    return head;
}

node* addone2(node* head){
    node* temp=head;
    node* prev=NULL;
    while(temp!=NULL){
        node* nex=temp->next;
        temp->next=prev;
        prev=temp;
        temp=nex;
    }
    node* head2=prev;
    temp=head2;
    int carry=1;
    while(carry!=0 && temp!=NULL){
        carry=(temp->data+carry)/10;
        temp->data=(temp->data+carry)%10;
        
        temp=temp->next;
    }
    head=revll2(head2);
    if(carry==1){
        node* hed=new node(1);
        hed->next=head;
        head=hed;
    }
    return head;
}

// intersection in linked lists

// node* intersect(node* h1,node* h2){
//     node* mover=h1;
//     map<node*,int>mpp;
//     while(mover!=NULL){
//         mpp[mover]=1;
//         mover=mover->next;
//     }
//     mover=h2;
//     while(mover!=NULL){
//         if(mpp.find(mover)){
//             return mover;
//         }
//         mover=mover->next;
//     }
//     return NULL;
// }

// DETECTING A LOOP IN LINKED LIST
// method 1 : using a hashmap

bool loopinll(node* head){
    node* temp=head;
    map<node*,int>mpp;
    while(temp!=NULL){
        if(mpp.find(temp)!=mpp.end()){
            return true;
        }
        mpp[temp]=1;
    }
    return false;
}
// method 2: using hare tortoise
bool loopinll2(node* head){
    node* slow=head;
    node* fast=head;
    while(fast!=NULL || fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow){
            return true;
        }
    }
    return false;
}

// reverse a linked list with groups of k
node* revbyk(node* head,int k){
    node* temp=head;
    int finalcount=0;

    node* prevhead=NULL;
    while(temp!=NULL){
        int count=1;
        node* temphead=temp;
        while(count<k && temp->next!=NULL){
            if(temp->next==NULL){
                return head;
                ;
            }
            temp=temp->next;
            count++;
        }
        if (count < k && temp->next == NULL) {
            if (prevhead != NULL) {
                prevhead->next = temphead;  
            }
            return head; 
        }
        node* temptail=temp;
        if(finalcount==0){
            head=temptail;
        }
        temp=temp->next;

        node* prev=NULL;
        node* mover=temphead;
        while(mover!=temp){
            node* nxt=mover->next;
            mover->next=prev;
            prev=mover;
            mover=nxt;
        }
        if(prevhead!=NULL){
            prevhead->next=temptail;
        }
        
        prevhead=temphead;
        finalcount++;
    }
    return head;
}

// rotate a linked list k times

node* rotate(node* head,int k){
    node* temp=head;
    int count=0;
    node* prev=NULL;
    while(temp!=NULL){
        prev=temp;
        temp=temp->next;
        count++;
    }
    if(k>count){
        k=k%count;
    }
    node* tail=prev;
    temp=head;
    int req=1;
    while(req!=count-k){
        temp=temp->next;
        req++;
    }
    node* newhead=temp->next;
    prev->next=head;
    temp->next=nullptr;
    return newhead;
}

node* merge(node* head1,node* head2){
    node* ans=new node(0);
    node* temp1=head1;
    node* temp2=head2;
    node* mover=ans;
    int d;
    while(temp1!=NULL && temp2!=NULL){
        if(temp1->data<=temp2->data){
            d=temp1->data;
            temp1=temp1->next;
        }
        else{
            d=temp2->data;
            temp2=temp2->next;
        }
        node* temp=new node(d);
        mover->next=temp;
        mover=temp;
    }
    while(temp1!=NULL){
        node* temp=new node(temp1->data);
        mover->next=temp;
        mover=temp;
        temp1=temp1->next;
    }
    while(temp2!=NULL){
        node* temp=new node(temp2->data);
        mover->next=temp;
        temp2=temp2->next;
        mover=temp;
    }
    return ans->next;

}

node* merge2(node* head1,node* head2){
    node* temp1=head1;
    node* temp2=head2;
    node* prev=NULL;
    while(temp1!=NULL && temp2!=NULL){
        if(temp1->data<temp2->data){
            prev=temp1;
            temp1=temp1->next;
        }
        else if(temp2->data<=temp1->data){
            node* toadd=temp2;
            temp2=temp2->next;
            if(temp1==head1){
                toadd->next=head1;
                head1=toadd;
                prev=toadd;
            }
            else{
                prev->next=toadd;
                toadd->next=temp1;
                prev=toadd;
            }
        }
    }
    if(temp2!=NULL){
            prev->next=temp2;
        }
    return head1;
    
}
int main(){
    vector<int>arr1={2,4,8,10};
    vector<int>arr2={1,3,3,6,11,14};
    node* head1=arrtoll(arr1);
    node* head2=arrtoll(arr2);
    // head=rotate(head,2);
    node* head=merge2(head1,head2);


    node* temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
 