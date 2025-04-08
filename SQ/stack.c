#include <stdio.h>
#include <stdlib.h>
void push(int* stack, int num, int* top);
int pop(int* stack, int* top);
int main(void){
	int * stack;
	int size;
	printf("size를 입력하세요 : ");
	scanf("%d",&size);
	stack = (int*)malloc(sizeof(int)*size);
	int top = 0;
	while(1){
		printf("\n======\nmenu\n1. push\n2. pop\n3. print\n4. stop\n======\n");
		int menu;
		scanf("%d",&menu);
		if(menu == 1){
			if(size<top){
				printf("stack is full\n");	
				continue;
			}
			int num;
			printf("push num : ");
			scanf("%d",&num);
			push(stack, num, &top);
		}
		if(menu == 2){
			if(top == 0){
				printf("stack is empty\n");
				continue;
			}
			int num = pop(stack,&top);
			printf("pop num : %d\n",num);
		}
		if(menu == 3){
			printf("print stack\n");
			for(int i = 0 ; i<top ; i++){
				printf("%d. %d\n",i+1, stack[i]);
			}
		}
		if(menu == 4)
			break;
	}
	free(stack);
	return 0;
}
void push(int* stack, int num, int* top){
	stack[*top] = num;
	(*top)++;
	return;
}
int pop(int* stack, int* top){
	(*top)--;
	int num = stack[*top];
	stack[*top] = 0;
	return num;
}

	
