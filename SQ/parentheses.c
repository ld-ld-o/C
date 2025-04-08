#include <stdio.h>
int main(void){
    char str[10000];
    char c=1;
    int top = 0;
    int num;
    scanf("%d",&num);
    scanf(" %c",&c);
    for(int i = 0; i<num&&c!='\n';i++){
        if(c=='(')
            str[top++] = c;
        else
            if(str[--top]=='(')
                str[top] = 0;
            else{
                printf("잘못된 괄호입니다\n");
                break;
            }
        scanf(" %c",&c);
    }
    if(top == 0)
        printf("올바른 괄호입니다\n");

    return 0; 
}
