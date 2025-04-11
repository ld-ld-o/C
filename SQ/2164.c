#include <stdio.h>
#include <stdlib.h>
void init(int* n,int*rear, int**circleQ);
void enqueue(int n,int num, int* rear, int** q);
int dequeue(int n, int* front, int** q);

int main(void) {
    int* circleQ;
    int n;
    int front= 0;
    int rear; 
    init(&n,&rear, &circleQ);
    for(int i = 0; i < n-1; i++){
        dequeue(n,&front,&circleQ);
        enqueue(n,dequeue(n,&front,&circleQ),&rear,&circleQ);
    }
    printf("%d\n",circleQ[front%n]);
    return 0;
}
void init(int* n,int*rear, int**circleQ){
    scanf("%d",n);
    *rear =*n;
    *circleQ = (int*)malloc(sizeof(int)*(*n));
    for(int i = 0; i<(*n);i++)
        (*circleQ)[i] = i+1;
    return;
}
void enqueue(int n,int num, int* rear, int** q){
    (*q)[(*rear)++%n]=num;
    return;
}
int dequeue(int n, int* front, int** q){
    int a = (*q)[*front%n];
    (*q)[(*front)++%n]=0;
    
    return a;
}
