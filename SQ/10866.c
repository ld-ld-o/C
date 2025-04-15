#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
typedef struct Deque{
    int head;
    int rear;
    int* q;
    int n;
}Deque;
int divideIns(char* ins);
void push_front(int ins, Deque* deque);
void push_back(int ins, Deque* deque);
int pop_front(Deque* deque);
int pop_back(Deque* deque);
int size(Deque* deque);
int empty(Deque* deque);
int front(Deque* deque);
int back(Deque* deque);
    
int main(void){
    int n;
    char ins[6];
    char*tok;
    scanf("%d",&n);
    Deque* deque = (Deque*)malloc(sizeof(Deque));
    deque->q = (int*)malloc(sizeof(int)*n);
    deque->head = n;
    deque->rear = n+1;
    deque->n = n;
    for(int i = 0 ; i < n ; i++){
        scanf("%s",ins);
        tok = strtok(ins," \n");
        switch(divideIns(tok)){
            case 1:
                int j;
                scanf("%d",&j);
                push_front(j,deque);
                break;
            case 2:
                int r;
                scanf("%d",&r);
                push_back(r,deque);
                break;
            case 3:
                printf("%d\n",pop_front(deque));
                break;
            case 4:
                printf("%d\n",pop_back(deque));
                break;
            case 5:
                printf("%d\n",size(deque));
                break;
            case 6:
                printf("%d\n",empty(deque));
                break;
            case 7:
                printf("%d\n",front(deque));
                break;
            case 8:
                printf("%d\n",back(deque));
                break;
            case 0:
                printf("Error\n");
            default:
                break;
        }
    }
    return 0;
}
int divideIns(char* ins){
    if(strcmp(ins,"push_front")==0) return 1;
    else if(strcmp(ins,"push_back")==0) return 2;
    else if(strcmp(ins,"pop_front")==0) return 3;
    else if(strcmp(ins,"pop_back")==0) return 4;
    else if(strcmp(ins,"size")==0) return 5;
    else if(strcmp(ins,"empty")==0) return 6;
    else if(strcmp(ins,"front")==0) return 7;
    else if(strcmp(ins,"back")==0) return 8;
    return 0;
}
void push_front(int ins, Deque* deque){
    deque->q[deque->head%deque->n]=ins;
    deque->head--;
    return;
}
void push_back(int ins, Deque* deque){
    deque->q[deque->rear%deque->n]=ins;
    deque->rear++;
    return;
}
int pop_front(Deque* deque){
    if(empty(deque)) return -1;
    int n = deque->q[(++deque->head)%deque->n];
    return n;
}
int pop_back(Deque* deque){
    if(empty(deque)) return -1;
    int n = deque->q[(--deque->rear)%deque->n];
    return n;
}
int size(Deque* deque){
    return(deque->rear-deque->head-1);
}
int empty(Deque* deque){
    if(deque->rear-deque->head==1) return 1;
    else return 0;
}
int front(Deque* deque){
    if(empty(deque)) return -1;
    return deque->q[(deque->head+1)%deque->n];
}
int back(Deque* deque){
    if(empty(deque)) return -1;
    return deque->q[(deque->rear-1)%deque->n];
}
