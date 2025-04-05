#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void enqueue(int* queue,int* top, int* front, int size);
int dequeue(int* queue,int *front, int size);
bool isEmpty(int front, int size);
bool isFull(int top, int size);
int main(void){
    int* queue;
    int size;
    int top = 0;
    int front = size;
    printf("size : ");
    scanf("%d",&size);
    queue = (int*)malloc(sizeof(int)*size);
    

    while(1){
        int m;
        printf("======\nmenu\n1. enqueue\n2. dequeue\n3. print\n4. stop\n======\n");
        scanf("%d",&m);
        if(m==1){
            enqueue(queue, &top, &front, size);
        }else if(m==2){
            dequeue(queue, &front, size);
        }else if(m==3){
            printf("\nQueue\n");
            int i = front;
            while(i<top){
                printf("%d\n",queue[i++]);
            }
        }else if(m==4){
            break;
        }
    }
    free(queue);

    return 0;
}
void enqueue(int* queue,int* top, int* front, int size){
    if(isFull(*top,size)){
        printf("queue is full\n");
        return ;
    }
    if(isEmpty(*front,size))
        *front = 0;
    int n;
    printf("number : ");
    scanf("%d",&n);
    queue[(*top)++]=n;
    return ;
}
int dequeue(int* queue,int *front, int size){
    if(isEmpty(*front,size)){
        printf("NULL\n");
        return 0;
    }
    int n = queue[(*front)];
    queue[(*front)++]=0;
    return n;
}
bool isEmpty(int front, int size){
    if(front>=size)
        return 1;
    else
        return 0;
}
bool isFull(int top, int size){
    if(top>=size)
        return 1;
    else 
        return 0;
}
