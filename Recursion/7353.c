#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    struct Node* next;
    char* url;
}Node;
typedef struct Stack{
    Node* head;
    int size;
}Stack;

int main(void){

    return 0;
}
int webNavigation(){
    char* str;
    char* currentURL = "http://www.acm.org/";
    scanf("%s",str);
    Stack* forStack = (Stack*)malloc(sizeof(Stack));
    Stack* backStack = (Stack*)malloc(sizeof(Stack));
    forStack->size = 0;
    backStack->size = 0;

    if(strcmp(str,"VISIT")){
        push(backStack,currntURL);
        clearStack(forStack);
        scanf("%s",currentURL);
    }
    else if(strcmp(str,"BACK")){
        strcpy(pop(backStack),currentURL);
        push(forStack,currentURL);


    }
    else if(strcmp(str,"FORWARD")){
    }
    else if(strcmp(str,"QUIT")){
    }
}
void push(Stack* stack,char* str){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(empty(stack))
        stack->head=newNode;
    strcpy(str,newNode->url);
    Node* current = stack->head;
    for(int i = 0; i < stack->size -1; i++){
        current = current->next;
    }
    current->next = ndeNode;
    stack->size++;
    return;
}
char* pop(Stack* stack){
    if(stack->size == 0){
        return "Ignored";
    }
    Node* current = stack->head;
    char* url;
    if(stack->size == 1){
        strcpy(url,current->url);
        stack->head == NULL;
        free(current);
    }
    else{
        for(int i = 0; i<stack->size-2 ; i++)
            current = current->next;
        strcpy(url,current->next->url);
        free(current->next);
        current->next=NULL;
    }
    stack->size-=1;
    return url;
}
int empty(Stack* stack){
    if(stack->size==0)
        reuturn 1;
    return 0;
}
void claerStack(Stack* stack){
    Node* current = stack->head;
    for(int i = 0 ; i<stack->size ; i++){
        if(current->next != NULL)
            Node* current2=current->next;
        free(current);
        corrent = current2;
    }
    stack->head = NULL;
    stack->size = 0;
    return;
}
