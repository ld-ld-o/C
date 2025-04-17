#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    struct Node* next;
    char* url;
}Node;
typedef struct Stack{
    Node* head;
    int size; }Stack;
int init(Stack** forStack,Stack** backStack);
int webNavigation(Stack* forStack, Stack* backStack);
void push(Stack* stack,char* str);
char* pop(Stack* stack);
int empty(Stack* stack);
void clearStack(Stack* stack);
void clear(Stack** forStack,Stack** backStack);
char* copyString(const char* src) ;

int main(void){
    Stack* forStack;
    Stack* backStack;
    int n;
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        init(&forStack, &backStack);
        webNavigation(forStack, backStack);
        clear(&forStack, &backStack);
    }
    return 0;
}
int init(Stack** forStack,Stack** backStack){
    *forStack = (Stack*)malloc(sizeof(Stack));
    *backStack = (Stack*)malloc(sizeof(Stack));
    (*forStack)->size = 0;
    (*backStack)->size = 0;
}
int webNavigation(Stack* forStack, Stack* backStack){
    char* currentURL = "http://www.acm.org/\0";
    char str[10];
    while(1){
        scanf("%s",str);
        if(strcmp(str,"VISIT")==0){
            push(backStack,currentURL);
            clearStack(forStack);
            scanf("%s",currentURL);
        }
        else if(strcmp(str,"BACK")==0){
            push(forStack,currentURL);
            strcpy(pop(backStack),currentURL);
        }
        else if(strcmp(str,"FORWARD")==0){
            push(backStack,currentURL);
            strcpy(pop(forStack),currentURL);
        }
        else if(strcmp(str,"QUIT")==0){
            break;
        }   
    }
}
void push(Stack* stack,char* str){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(empty(stack))
        (stack)->head=newNode;
    newNode->url = copyString(str);
    Node* current = (stack)->head;
    for(int i = 0; i < (stack)->size -1; i++){
        current = current->next;
    }
    current->next = newNode;
    (stack)->size++;
    return;
}
char* pop(Stack* stack){
    if(stack->size == 0){
        return "Ignored";
    }
    Node* current = stack->head;
    char* url;
    if(stack->size == 1){
        url = copyString(current->url);
        stack->head == NULL;
        free(current);
    }
    else{
        for(int i = 0; i<stack->size-2 ; i++)
            current = current->next;
        url = copyString(current->next->url);
        free(current->next);
        current->next=NULL;
    }
    stack->size-=1;
    return url;
}
int empty(Stack* stack){
    if(stack->size==0)
        return 1;
    return 0;
}
void clearStack(Stack* stack){
    Node* current = stack->head;
    Node* current2;
    for(int i = 0 ; i<stack->size ; i++){
        if(current->next != NULL)
            current2=current->next;
        free(current);
        current = current2;
    }
    stack->head = NULL;
    stack->size = 0;
    return;
}
void clear(Stack** forStack,Stack** backStack){
    clearStack(*forStack);
    clearStack(*backStack);
    *forStack = NULL;
    *backStack = NULL;
    return;
}
char* copyString(char* src) {
    char* dst = (char*)malloc(strlen(src) + 1);
    strcpy(dst, src);
    return dst;
}
