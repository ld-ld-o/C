/*
    push() → 새 노드를 생성하여 스택에 추가

    pop() → 최상단 노드를 제거하고 반환
    
    peek() → 최상단 노드 값 확인 (삭제 X)
    
    isEmpty() → 스택이 비어 있는지 확인
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{ 
    int num;
    struct Node* next;
}Node;

Node* peek(Node* head);
void push(Node** head, int num);
int pop(Node* head);
bool isEmpty(Node* head);
void print(Node* head);
int main() {
    Node* head;
    while(1){
        printf("\n======\nMenu\n1. push\n2. pop\n3. print\n4. stop\n======\n\n");
        int m;
        scanf("%d",&m);
        if(m==1){
            int n;
            printf("push num : ");
            scanf("%d", &n);
            push(&head, n);
        }
        else if(m==2){
            if(isEmpty(head)){
                printf("NULL\n");
                continue;
            }
            int popedNum = pop(head);
            printf("%d\n", popedNum); 
        }
        else if(m==3){
            print(head);
            
        }
        else if(m==4){
            break; 
        }
    }
    
    
    return 0;
}
Node* peek(Node* head){
    Node* current=head;
    if(isEmpty(head)){
        printf("NULL\n");
        return head;
    }
    while(current->next != NULL){
        current=current->next;
    }
    //printf("%d\n",current->num);
    return current;
}
void push(Node** head, int num){
    Node* current = peek(*head);
    Node* nextNode = (Node*)malloc(sizeof(Node));
    if(isEmpty(*head)) *head = nextNode;
    else current->next = nextNode;
    nextNode->num = num;
}
int pop(Node* head){
    
    Node* last = peek(head);
    Node* current = head;
    while(current->next != last){
        current= current->next;
    }
    current->next=NULL;
    int lastNum = last->num;
    free(last);
    return lastNum;

}
bool isEmpty(Node* head){
    if(head==NULL){
        return 1;
    }else return 0;
}
void print(Node* head){
    Node* current = head;
    if(isEmpty(head)) {
        printf("NULL\n");
        return;
    }
    while(current->next != NULL){
	    printf("stack\n");
        printf("%d\n", current->num);
        current = current->next;
    }
    printf("%d\n", current->num);

    return;
}
