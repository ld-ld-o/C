#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Queue{
    int head;
    int rear;
    int* q;
}Queue;
int divideIns(char* ins);
void push(char* ins, Queue* queue);
int pop(Queue* queue);
int size(Queue* queue);
int empty(Queue* queue);
int front(Queue* queue);
int back(Queue* queue);
    
int main(void){
    int n;
    char ins[6];
    char*tok;
    scanf("%d",&n);
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->q = (int*)malloc(sizeof(int)*n);
    queue->head = 0;
    queue->rear = 0;
    for(int i = 0 ; i < n ; i++){
        scanf("%s",ins);
        tok = strtok(ins," \n");
        switch(divideIns(tok)){
            case 1:
                tok = strtok(ins," \n");
                push(tok,queue);
                break;
            case 2:
                printf("%d\n",pop(queue));
                break;
            case 3:
                printf("%d\n",size(queue));
                break;
            case 4:
                printf("%d\n",empty(queue));
                break;
            case 5:
                printf("%d\n",front(queue));
                break;
            case 6:
                printf("%d\n",back(queue));
                break;
            default:
                break;
        }
    }
    return 0;
}
int divideIns(char* ins){
    if(strcmp(ins,"push")) return 1;
    else if(strcmp(ins,"pop")) return 2;
    else if(strcmp(ins,"size")) return 3;
    else if(strcmp(ins,"empty")) return 4;
    else if(strcmp(ins,"front")) return 5;
    else if(strcmp(ins,"back")) return 6;
    return 0;
}
void push(char* ins, Queue* queue){
    queue->q[queue->rear++]=atoi(ins);
    return;
}
int pop(Queue* queue){
    int n = queue->q[queue->head];
    queue->q[queue->head++] = 0;
    return n;
}
int size(Queue* queue){
    return(queue->rear-queue->head);
}
int empty(Queue* queue){
    if(queue->head==queue->rear) return 1;
    else return 0;
}
int front(Queue* queue){
    return queue->q[queue->head];
}
int back(Queue* queue){
    return queue->q[queue->rear];
}
