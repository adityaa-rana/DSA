#include<stdio.h>
#include<stdlib.h>
struct queue{
    int arr[5];
    int rear;
    int front;
};
void start(struct queue *q){
    q->front=-1;
    q->rear=-1;
}
int isfull(struct queue *q){
    if(q->rear==4){
        return 1;
    }
    else{
        return 0;
    }
}
int isempty(struct queue *q){
    if(q->front==-1){
        return 1;
    }
    else{
        return 0;
    }
}

void enqueue(struct queue *q,int data){
    if(isfull(q)){
        printf("Queue is full");
    }
    if(isempty(q)){
        q->front=0;
    }
    q->rear++;
    q->arr[q->rear]=data;
    printf("Enqueued %d",data);
}

void dequeue(struct queue *q){
    if(isempty(q)){
        printf("The queue is empty");
    }
    int data=q->arr[q->front];
    if(q->front==q->rear){
        q->front=-1;
        q->rear=-1;
    }
    else{
        q->front++;
    }
    printf("Data removed : ",data);
    
}

void display(struct queue *q){
    if(isempty(q)){
        printf("Queue is empty");
    }
    else{
        for(int i=q->front;i=q->rear;i++){
            printf("%d",q->arr[i]);
        }
    }
}
