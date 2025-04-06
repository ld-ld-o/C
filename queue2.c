#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
    int num;
    struct Node* next;
}Node;

typedef struct Queue{
    Node* front;
    Node* rear;
}Queue;
void initQueue(Queue** queue);
void enqueue(Queue** q, int num);
int dequeue(Queue** q);
bool isEmpty(Queue* q);
int peek(Queue** q);

int main(void){
    Queue* q;

    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    
    printf("Front: %d\n", peek(&q));

    printf("Dequeued: %d\n", dequeue(&q));
    printf("Dequeued: %d\n", dequeue(&q));
    printf("Dequeued: %d\n", dequeue(&q));

    return 0;
}
void initQueue(Queue** queue){
    *queue = (Queue*)malloc(sizeof(Queue)*1);
    (*queue)->front=NULL;
    (*queue)->rear=NULL;
    return ;
}

void enqueue(Queue** q, int num){
    Node* newNode = (Node*)malloc(sizeof(Node)*1);
    newNode->num = num;
    newNode->next = NULL;
    if(isEmpty(*q)){
        (*q)->front = newNode;
        (*q)->rear = newNode;
    }
    else{
        (*q)->rear->next=newNode;
        (*q)->rear=newNode;
    }
    return;
}
int dequeue(Queue** q){
    Node* temp = (*q)->front;
    int num = temp->num;
    (*q)->front=(*q)->front->next;
    free(temp);

    return num;
}
    
bool isEmpty(Queue* q){
    if(q->front==NULL) return 1;
    else return 0;
}
int peek(Queue** q){
    if(isEmpty(*q))
        printf("NULL\n");
    return (*q)->front->num;
}
