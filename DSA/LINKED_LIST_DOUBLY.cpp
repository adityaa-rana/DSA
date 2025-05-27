#include<bits/stdc++.h>
using namespace std;

class node{ 
    public:
    int data;
    node* next;
    node* back;

    public:
    node(int d1,node* n1,node* b1){
        data=d1;
        next=n1;
        back=b1;
    }
    node(int d1){
        data=d1;
        next=nullptr;
        back=nullptr;
    }
};

//array to doubly linked list

node* arrtodll(vector<int>arr){
    node* head=new node(arr[0]);
    node* prev=head;
    for(int i=1;i<arr.size();i++){
        node* temp=new node(arr[i],nullptr,prev);
        prev->next=temp;
        prev=prev->next;
    }
    return head;
}

void printdll(node* head){
    node* temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

node* deletehead(node* head){
    if(head==NULL){
        return NULL;
    }
    else if(head->next==NULL){
        delete head;
        return NULL;
    }
    else{
        node* temp=head;
        head=head->next;
        head->back=nullptr;
        temp->next=nullptr;
        delete temp;
        return head;
    }
    
}

node* deletetail(node* head){
    if(head->next==NULL){
        return head;
    }
    node* mover=head;
    while(mover->next->next!=NULL){
        mover=mover->next;
    }
    node* last=mover->next;
    mover->next=nullptr;
    last->back=nullptr;
    delete last;
    return head;
}

node* deletekth(node* head,int k){
    int count=1;
    node* mover=head;
    while(count!=k){
        mover=mover->next;
        count++;
    }
    node* behind=mover->back;
    node* ahead=mover->next;
    if(behind==NULL && ahead==NULL){
        return NULL;
    }
    else if(behind==NULL){
        deletehead(head);
    }
    else if(ahead==NULL){
        deletetail(head);
    }
    else{
        ahead->back=behind;
        behind->next=ahead;
        delete mover;
        return head;
    }
    
}
node* deletek(node* head,int k){
    node* mover=head;
    while(mover->data!=k){
        mover=mover->next;
        if(mover==NULL){
            return head;
        }
    }
    
    node* behind=mover->back;
    node* ahead=mover->next;
    if(behind==NULL && ahead==NULL){
        return NULL;
    }
    else if(behind==NULL){
        deletehead(head);
    }
    else if(ahead==NULL){
        deletetail(head);
    }
    else{
        ahead->back=behind;
        behind->next=ahead;
        delete mover;
        return head;
    }
    
}
 
// insertion of node
node* inserthead(node* head,int val){
    node* value=new node(val,nullptr,nullptr);
    value->next=head;
    head->back=value;
    head=head->back;
    return head;
}

node* inserttail(node* head,int val){
    node* mover=head;
    node* value=new node(val,nullptr,nullptr);
    while(mover->next!=NULL){
        mover=mover->next;
    }
    mover->next=value;
    value->back=mover;
    return head;
}

node* insertbeforetail(node* head,int val){
    node* mover=head;
    node* value=new node(val,nullptr,nullptr);
    while(mover->next->next!=NULL){
        mover=mover->next;
    }
    node* last=mover->next;
    value->next=last;
    value->back=mover;
    mover->next=value;
    last->back=value;
    return head;
}

node* insertbeforekth(node* head,int val,int k){
    node* newval=new node(val,nullptr,nullptr);
    int count=1;
    node* mover=head;
    while(count!=k){
        mover=mover->next;
        count++;
    }
    node* prev=mover->back;
    prev->next=newval;
    mover->back=newval;
    newval->next=mover;
    newval->back=prev;
    return head;
}

node* reversedll(node* head){
    node* mover=head;
    while(mover->next!=NULL){
        mover=mover->next;
    }
    node* last=mover->next;
    node* first=head;
    while(last->next!=first || last!=first){
        int temp=last->data;
        last->data=first->data;
        first->data=temp;
        first=first->next;
        last=last->back;
    }
    return head;
}


// NOT SWAPPING THE ELEMENTS BUT SWAPPING THE LINKS (BACK BECOMES FRONT AND FRONT BECOMES BACK)
node* revdll(node*  head){
    node* last=NULL;
    node* current=head;
    while(current!=NULL){
        last=current->back;
        current->back=current->next;
        current->next=last;

        current=current->back;
    }
    return last->back;
}

// using stack   TC= 0(2N)  , SC =0(N)
node *revdllst(node* head){
    stack<int>st;
    node* temp=head;
    while(temp!=NULL){
        st.push(temp->data);
        temp=temp->next;
    }
    temp=head;
    while(temp!=NULL){
        temp->data=st.top();
        st.pop();
        temp=temp->next;
    }
    return head;
}


// delete all occurences of a given key in a doubly linked list
node* removeocc(node *head,int key){
    node* temp=head;
    while(temp!=NULL){
        if(temp->data==key){
            node* todelete=temp;
            temp=temp->next;
            if(todelete==head){
                head=todelete->next;
                head->back=nullptr;
                todelete->next=nullptr;
                delete todelete;
            }
            else if(todelete->next==NULL){
                (todelete->back)->next=nullptr;
                todelete->back=nullptr;
                delete todelete;
            
            }
            else{
                (todelete->back)->next=todelete->next;
                (todelete->next)->back=todelete->back;
                todelete->next=nullptr;
                todelete->back=nullptr;
                delete todelete;
            }
        }
        else{
            temp=temp->next;
        }
    }
    return head;
}


// approach 1
void findpairs(node* head,int sum){
    node* i=head;
    while(i!=NULL){
        node*j=i->next;
        while(j!=NULL && (i->data+j->data)<=sum){
            int res=i->data+j->data;
            if(res==sum){
                printf("%d %d\n",i->data,j->data);
            }
            j=j->next;
        }
        i=i->next;
    }
}

void findpairs2(node* head,int sum){
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    node* j=temp;
    node* i=head;
    while(i->data<j->data){
        int res=i->data+j->data;
        if(res<sum){
            i=i->next;
        }
        else if(res>sum){
            j=j->back;
        }
        else{
            printf("%d %d\n",i->data,j->data);
            i=i->next;
            j=j->back;
        }
    }
}
// removing all duplicates in a doubly linked list in a sorted DLL
node* removedup(node* head){
    node* temp=head->next;
    while(temp->next!=NULL){
        if((temp->back)->data==temp->data || (temp->next)->data==temp->data){
            node* todelete=temp;
            temp=temp->next;
            (todelete->back)->next=todelete->next;
            (todelete->next)->back=todelete->back;
            todelete->next=nullptr;
            todelete->back=nullptr;
            delete todelete;
        }
        else{
            temp=temp->next;
        }
    }
}


int main(){
    vector<int>arr={10,4,10,6,10,7,10,10};
    vector<int> arr2={1,1,1,2,3,3,4,4};
    // node* head=arrtodll(arr);
    // node* revhead=removeocc(head,10);
    // printdll(revhead);

    // vector<int>arr={1,2,3,4,5};
    node* head=arrtodll(arr2);
    removedup(head);
    printdll0000000(head);

}
