// infix to postfix

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define max 100

int precedence(char ch){
    if(ch=='^'){
        return 3;
    }
    else if(ch=='*'|| ch=='/' || ch=='%' ){
        return 2;
    }
    else if(ch=='+' || ch=='-'){
        return 1;
    }
    else{
        return 0;
    }
}

char associavtiy(char ch){
    if(ch=='^'){
        return 'R';
    }
    else{
        return 'L';
    }
}

void infixtopostfix(char sample[]){
    char result[max];
    int rindex=0;
    int sindex=-1;
    char stack[max];
    int len=strlen(sample);
    for(int i=0;i<len;i++){
        char ch=sample[i];
        if(ch>'a' && ch<'z' || ch>'A' && ch<'Z' &&  ch>'0' && ch<'9'){
            result[rindex++]=ch;
        }
        else if(ch='('){
            stack[++sindex]=ch;
        }
        else if(ch==')'){
            while(sindex>=0 && stack[sindex]!=')'){
                result[rindex]=stack[sindex];
                rindex++;
                sindex--;
            }
            sindex--;
        }
        else{
            while(sindex>=0 && associavtiy(ch)=='L' && precedence(ch)<precedence(stack[sindex])){
                result[rindex]=stack[sindex];
                rindex++;
                sindex--;
            }
            stack[++sindex]=ch;
        }
    }
    while(sindex>=0){
        result[rindex]=stack[sindex];
        rindex++;
        sindex--;
    }
    result[rindex]='\0';
    printf("%s",result);
}


void strrev(char sample[]){
    int len=strlen(sample);
    int i=0;
    int j=len-1;
    while(i<j){
        char temp=sample[i];
        sample[i]=sample[j];
        sample[j]=temp;
        i++;
        j--;
    }
}
void infixtoprefix(char sample[]){
    int len=strlen(sample);
    strrev(sample);
    for(int i=0;i<len;i++){
        if(sample[i]=='('){
            sample[i]=')';
        }
        else if(sample[i]==')'){
            sample[i]='(';
        }
    }
    infixtopostfix(sample);
    strrev(sample);
}

// postfix evaluation 

void removespace(char sample[]){
    int len=strlen(sample);
    int i=0,j=0;
    while(sample[i]!='\0'){
        if(sample[i]==" "){
            sample[j]=sample[i];
            j++;
        }
        i++;
    }
    sample[j]='\0';
}

int evaluate(char sample[]){
    int stack[max];
    int len=strlen(sample);
    int ans=-1;
    int sindex=-1;
    for(int i=0;i<len;i++){
        char ch=sample[i];
        if(ch>'0' && ch<'9'){
            stack[++sindex]=(int)(ch-'0');
        }
        else{
            int n1=stack[sindex];
            sindex--;
            int n2=stack[sindex];
            switch(ch){
                case '+':
                    stack[sindex]=n1+n2;
                    break;
                case '-':
                    stack[sindex]=n1-n2;
                    break;
                case '*':
                    stack[sindex]=n1*n2;
                    break;
                case '/':
                    stack[sindex]=n1/n2;
                    break;
                default:
                    goto here;
            }
        }
    }
    ans=stack[sindex];
    return ans;
    here: ans=-1;
    return ans;
}

// simple queue

typedef struct queue{
    int arr[max];
    int front,rear;
}queue;

void start(queue* q){
    q->front=-1;
    q->rear=-1;
}
void enqueue(queue* q,int data){
    if(q->rear=max-1){
        return;
    }
    else{
        if(q->front==-1){
            q->front=0;
        }
        q->rear++;
        q->arr[q->rear]=data;
    }
}
void dequeue(queue* q){
    if(q->front==-1){
        return;
    }
    
    else {
        int data=q->front;
        if(q->front==q->rear){
            q->front=0;
            q->rear=0;
        }
        else{
            q->front++;
        }
    }
}

void print(queue* q){
    for(int i=q->front;i<=q->rear;i++){
        printf("%d ",q->arr[i]);
    }
}

//circular queue
typedef struct cqueue{
    int front,rear;
    int arr[max];
}cqueue;

void start(queue* q){
    q->front=-1;
    q->rear=-1;
}
void enqueue(int data,cqueue* q){
    if(q->front==0 && q->rear==max-1 || q->front==q->rear+1){
        return;
    }
    else{
        if(q->front==-1){
            q->front=0;
            q->rear=0;
        }
        else if(q->rear==max-1 && q->front!=0){
            q->rear=0;
        }
        else{
            q->rear++;
        }
        q->arr[q->rear]=data;
    }
}

void dequeue(cqueue* q){
    if(q->front==-1){
        return;
    }
    else{
        int data=q->arr[q->front];
        if(q->rear==q->front){
            q->front=-1;
            q->rear=-1;
        }
        else if(q->front==max-1){
            q->front=0;
        }
        else{
            q->front++;
        }
    }
}

void print(cqueue* q){
    if(q->front<=q->rear){
        for(int i=q->front;i<=q->rear;i++){
            printf("%d",q->arr[i]);
        }
    }
    else{
        for(int i=q->front;i<max;i++){
            printf("%d",q->arr[i]);
        }
        for(int i=0;i<=q->rear;i++){
            printf("%d",q->arr[i]);
        }
    }
}

// double ended queue

typedef struct dqueue{
    int front,rear;
    int arr[max];
}dqueue;

void start(dqueue* q){
    q->front=-1;
    q->rear=-1;
}
void enqueuerear(dqueue* q,int data){
    if(q->front==0 && q->rear==max-1 || q->front==q->rear+1){
        return;
    }
    else{
        if(q->front==-1){
        q->front=0;
        q->rear=0;
        }
        else if(q->rear==max-1 && q->front!=0){
            q->rear=0;
        }
        else{
            q->rear++;
        }
        q->arr[q->rear]=data;
    }
}

void enqueuefront(dqueue* q,int data){
    if(q->front==0 && q->rear==max-1 || q->front==q->rear+1){
        return;
    }
    else{
        if(q->front==-1){
            q->front=0;
            q->rear=0;
        }
        else if(q->front==0){
            q->front=max-1;
        }
        else{
            q->front--;
        }
        q->arr[q->front]=data;
    }
}

void dequeuefront(dqueue* q){
    if(q->front==-1){
        return;
    }
    else{
        int data=q->arr[q->front];
        if(q->front==q->rear){
            q->front=-1;
            q->rear=-1;
        }
        else if(q->front==max-1){
            q->front=0;
        }
        else{
            q->front++;
        }
    }
}

void dequeuerear(dqueue* q){
    if(q->rear==-1){
        return;
    }
    else{
        int data=q->arr[q->rear];
        if(q->front==q->rear){
            q->front=0;
            q->rear=0;
        }
        else if(q->rear==0){
            q->rear=max-1;
        }
        else{
            q->rear--;
        }
    }
}

// linked list

typedef struct node{
    int data;
    struct node* next;
}node;

node* create(int data){
    node* newnode=(node*)malloc(sizeof(node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}

node* insertfront(int data,node* head){
    node* newnode=create(data);
    newnode->next=head;
    head=newnode;
    return head;
}
node* insertend(int data,node* head){
    node* newnode=create(data);
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
    return data;
}
node* deletefront(node* head){
    node* temp=head;
    head=head->next;
    delete(temp);
    return head;
}

node* deleteend(node* head){
    node* temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    node* todel=temp->next;
    temp->next=NULL;
    free(todel);
    return head;
}
node* insertk(int k,node* head,int val){
    node* newnode=create(val);
    node* temp=head;
    while(temp->data!=k){
        temp=temp->next;
    }
    newnode->next=temp->next;
    temp->next=newnode;
    return head;
}

node* deletek(node* head,int k){
    node* temp=head;
    while(temp->next->data!=k){
        temp=temp->next;
    }
    node* todel=temp->next;
    temp->next=temp->next->next;
    free(todel);
    return head;
}

//polynomials

typedef struct node1{
    int coeff;
    int expo;
    struct node1* next;
}node1;

node1* create1(int expo,int coeff){
    node1* newnode=(node1*)malloc(sizeof(node1));
    newnode->coeff=coeff;
    newnode->expo=expo;
    newnode->next=NULL;
    return newnode;
}
node1* insert(node1* head,int c,int e){
    node1* newnode=create1(e,c);
    if(head==NULL || newnode->expo>head->expo){
        newnode->next=head;
        head=newnode;
    }
    else{
        node1* temp=head;
        while(temp->next!=NULL && temp->next->expo>newnode->expo){
            temp=temp->next;
        }
        if(temp->next!=NULL && temp->next->expo==newnode->expo){
            temp->next->coeff=newnode->coeff+temp->next->coeff;
        }
        else{
            newnode->next=temp->next;
            temp->next=newnode;
        }
    }
    return head;
}
node1* add(node1* head1,node1* head2){
    node1* temp1=head1;
    node1* temp2=head2;
    node1* result=NULL;
    while(temp1!=NULL && temp2!=NULL){
        if(temp1->expo==temp2->expo){
            result=insert(result,temp1->coeff+temp2->coeff,temp1->expo);
            temp1=temp1->next;
            temp2=temp2->next;
        }
        else if(temp1->expo>temp2->expo){
            result=insert(result,temp1->coeff,temp1->expo);
            temp1=temp1->next;
        }
        else{
            result=insert(result,temp2->coeff,temp2->expo);
            temp2=temp2->next;
        }
    }
    while(temp1!=NULL){
        result=insert(result,temp1->coeff,temp1->expo);
        temp1=temp1->next;
    }
    while(temp2!=NULL){
        result=insert(result,temp2->coeff,temp2->expo);
        temp2=temp2->next;
    }
    return result;
}
node1* multiply(node1* head1,node1* head2){
    node1* temp1=head1;
    node1* prod=NULL;
    while(temp1!=NULL){
        node1* temp2=head2;
        while(temp2!=NULL){
            prod=insert(prod,temp1->coeff*temp2->coeff,temp1->expo+temp2->expo);
            temp2=temp2->next;
        }
        temp1=temp1->next;
    }
    return prod;
}

bool compare(node1* head1,node1* head2){
    node1* temp1=head1;
    node1* temp2=head2;
    while(temp1!=NULL && temp2!=NULL){
        if(temp1->coeff!=temp2->coeff || temp1->expo!=temp2->expo){
            return false;
        }
        temp1=temp1->next;
        temp2=temp2->next;
    }
    if(temp1!=NULL){
        return false;
    }
    if(temp2!=NULL){
        return false;
    }
    return true;
}

int evaluate(int x,node1* head){
    int sum=0;
    node1* temp=head;
    while(temp!=NULL){
        sum+=(temp->coeff*pow(x,temp->expo));
        temp=temp->next;
    }
    return sum;
}

// doubly linked list
typedef struct node{
    int data;
    struct node* next;
    struct node* prev;
}node;

node* create(int data){
    node* newnode=(node*)malloc(sizeof(node));
    newnode->data=data;
    newnode->next=NULL;
    newnode->prev=NULL;
}

node* insertfront(node* head,int data){
    node* newnode=reate(data);
    if(head==NULL){
        head=newnode;
    
    }
    else{
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
    }
    return head;
}


node* deletefront(node* head){
    node* todel=head;
    head=head->next;
    todel->next=NULL;
    head->prev=NULL;
    free(todel);
    return head;
}

node* delk(node* head,int k){
    node* temp=head;
    while(temp->data!=k){
        temp=temp->next;
    }
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    free(temp);
    return head;
}

node* insertk(node* head,int k,int val){
    node* temp=head;
    node* newnode=create(val);
    while(temp->data!=k){
        temp=temp->next;
    }
    newnode->next=temp->next;
    newnode->prev=temp;
    temp->next->prev=newnode;
    temp->next=newnode;
    return head;
}

node* middle(node* head){
    node* fast=head;
    node* slow=head;
    while(fast!=NULL || fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

// binary trees

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}node;

void create(int data){
    node* newnode=(node*)malloc(sizeof(node));
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

node* insert(node* root,int data){

    node* newnode=create(data);
    if(root==NULL){
        return newnode;
    }
    node* queue[max];
    int front=0,rear=0;
    queue[rear++]=root;
    while(front<rear){
        node* temp=queue[front];
        front++;
        if(temp->left==NULL){
            temp->left=newnode;
            break;
        }
        else{
            queue[rear++]=temp->left;
        }
        if(temp->right==NULL){
            temp->right=newnode;
            break;
        }
        else{
            queue[rear++]=temp->right;
        }
    }
    return root;
}

//bst 
typedef struct node{
    int data;
    node* left,right;
}node;

node* create(int val){
    node* newnode=(node*)malloc(sizeof(node));
    newnode->data=val;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

node* insert(node* root,int val){
    node* newnode=create(val);
    if(root==NULL){
        return newnode;
    }
    if(root->data>val){
        root->left=insert(root->left,val);
    }
    else if(root->data<val){
        root->right=insert(root->right,val);
    }
    
    return root;
}

node* deletenode(node* root,int val){
    if(root==NULL){
        return NULL;
    }
    if(root->data<val){
        root->right=deletenode(root->right,val);
    }
    else if(root->data>val){
        root->left=deletenode(root->left,val);
    }
    else{
        if(root->left==NULL && root->right==NULL){
            free(root);
            return NULL;
        }
        else if(root->left==NULL || root->right==NULL){
            node* temp;
            if(root->left==NULL){
                temp=root->right;
            }
            else{
                temp=root->right;
            }
            free(root);
            return temp;
        }
        else{
            node* rightmin=root->right;
            while(rightmin->left){
                rightmin=rightmin->left;
            }
            root->data=rightmin->data;
            root->right=deletenode(root->right,rightmin->data);
        }
    }
    return root;
}

node* search(int val,node* root){
    if(root==NULL || root->data==val){
        return root;
    }
    else if(root->data<val){
        return search(val,root->right);
    }
    else{
        return search(val,root->left);
    }
}

int distance(node* root,int n,int m){
    int ans=-1;
    while(root->data!=n || root->data!=m){
        if(root->data<n && root->data<m){
            root=root->right;
        }
        else if(root->data>n && root->data>m){
            root=root->left;
        }
        else{
            int h1=0;
            int h2=0;
            node* temp1=root;
            node* temp2=root;
            while(temp1->data!=n){
                if(temp1->data<n){
                    temp1=temp1->left;
                }
                else{
                    temp1=temp1->right;
                }
                h1++;
            }
            while(temp2->data!=n){
                if(temp2->data<n){
                    temp2=temp2->left;
                }
                else{
                    temp2=temp2->right;
                }
                h2++;
            }
            ans=h1+h2;
            break;
        }
    }
    return ans;
}
// dfs
#include<stdio.h>
#include<stdlib.h>
#define max 100
typedef struct graph{
    int adj[max][max];
    int visited[max];
    int n,e;
}graph;

void init(graph *g,int n,int m){
    g->n=n;
    g->e=m;
    for(int i=0;i<n;i++){
        g->visited[i]=0;
        for(int j=0;j<n;j++){
            g->adj[i][j]=0;
        }
    }
}

void addedge(graph* g,int u,int v,int w){
    g->adj[u][v]=w;
}

void dfs(graph *g,int vertex){
    g->visited[vertex]=1;
    printf("%d",vertex);
    for(int i=0;i<g->n;i++){
        if(!g->visited[i] && i!=vertex && g->adj[vertex][i]!=0){
            dfs(g,i);
        }
    }
}

int main(){
    graph* g;
    int n,e;
    scanf("%d %d",&n,&e);
    init(g,n,e);
    for(int i=0;i<e;i++){
        int u,v;
        scanf("%d %d",&u,&v);
        addedge(g,u,v,1);
    }
    int source;
    scanf("%d",&source);
    for(int i=0;i<n;i++){
        if(!g->visited[i]){
            dfs(g,i);
            printf("\n");
        }
    }
}


// bfs

typedef struct graph{
    int adj[max][max];
    int visited[max];
    int level[max];
    int n,e;
}graph;

void init(graph* g,int n,int m){
    g->n=n;
    g->e=m;
    for(int i=0;i<n;i++){   
        g->visited[i]=0;
        g->level[i]=0;
        for(int j=0;j<n;j++){
            g->adj[i][j]=0;
        }
    }
}

int bfs(graph* g,int source,int target){
    int ans=-1;
    int count=-1;
    int queue[max];
    int front=0,rear=0;
    queue[rear++]=source;
    g->visited[source]=1;
    while(front<rear){
        int node=queue[front++];
        if(node==target){
            ans=g->level[node];
            break;
        }
        for(int i=0;i<g->n;i++){
            if(!g->visited[i] && g->adj[node][i]!=0 && i!=node){
                queue[rear++]=i;
                g->level[i]=g->level[node]+1;

                g->visited[i]=1;
            }
        }
    }

    return ans;
}

node* search(node* root,int val){
    if(root==NULL){
        return ;
    }
    if(root->data==val){
        return root;
    }
    search(root->left,val);
    search(root->right,val);
}

node* deletenode(node* root,int val){
    node* todelete=search(root,val);
    if(todelete->left==NULL & todelete->right==NULL){
        free(todelete);
        return  NULL;
    }
    else if(todelete->left==NULL || todelete->right==NULL){
        node* temp;
        if(todelete->left==NULL){
            temp=todelete->right;
        }
        else{
            temp=todelete->left;
        }
        free(todelete);
        return temp;
    }
    else{
        node* rightmin=todelete->right;
        while(rightmin->left!=NULL){
            rightmin=rightmin->left;
        }
        todelete->data=rightmin->data;
        todelete->right=delete(rightmin);
    }
    return root;
}