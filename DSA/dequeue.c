// #include<stdio.h>
// #include<stdlib.h>
// #define max 5   
// struct dqueue{
//     int arr[max];
//     int front;
//     int rear;
// };

// void start(struct dqueue *q){
//     q->front=-1;
//     q->rear=-1;
// }
// void enqueuefront(struct dqueue *q,int data){
//     if((q->front==0 && q->rear==max-1) || (q->front=q->rear+1)){
//         printf("Queue is full");
//         return ;
//     }
//     else{
//         if(q->front==-1){
//             q->front=0;
//             q->rear=0;
//         }
//         else if(q->front==0){
//             q->front=max-1;
//         }
//         else{
//             q->front--;
//         }
//         q->arr[q->front]=data;
//     }
// }
// void enqueuerear(struct dqueue* q,int data){
//     if(q->front==0 && q->rear==max-1 ||q->front==q->rear+1){
//         printf("queue is full");
//         return;
//     }
//     else{
//         if(q->rear==-1){
//             q->rear=0;
//             q->front=0;
//         }
//         else if(q->rear==max-1){
//             q->rear=0;
//         }
//         else{
//             q->rear=q->rear+1;
//         }
//         q->arr[q->rear]=data;
//     }
// }

// void dequeuefront(struct dqueue* q){
//     if(q->front==-1){
//         printf("Queue is empty");
//         return;
//     }
//     int data=q->arr[q->front];
//     if(q->front==q->rear){
//         q->front=-1;
//         q->rear=-1;
//     }
//     else if(q->front==max-1){
//         q->front=0;
//     }
//     else{
//         q->front++;
//     }
// }

// void dequeuerear(struct dqueue* q){
//     if(q->front==-1){
//         printf("Queue is empty");
//         return;
//     }
//     else{
//         if(q->rear==0){
//             q->rear=max-1;
//         }
//         else if(q->front==q->rear){
//         q->front=-1;
//         q->rear=-1;
//         }
//         else{
//             q->rear--;
//         }
//     }
// }



#include <stdio.h>
#include<math.h>
// C recursive function to solve tower of hanoi puzzle
void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod)
{
    if (n == 1)
    {
        printf("\n Move disk 1 from rod %c to rod %c", from_rod, to_rod);
        return;
    }
    towerOfHanoi(n-1, from_rod, aux_rod, to_rod);
    printf("\n Move disk %d from rod %c to rod %c", n, from_rod, to_rod);
    towerOfHanoi(n-1, aux_rod, to_rod, from_rod);
}
 
int main()
{
    int n = 4; // Number of disks
    int num=n;
    towerOfHanoi(n, 'A', 'C', 'B');  // A, B and C are names of rods
    printf("%d",pow(2,4));
    return 0;
}