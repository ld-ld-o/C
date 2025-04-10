#include <stdio.h>

int main(void){
    while(1){
        char[100] stack = {0};
        char c;
        int top=0;
        for(int i = 0 ; i<100;i++){
            scanf("%",&c);
            if(c=='.'){
                if(i==0)stopSwitch = 1; 
                break;
            }
            if(c=='(') stack[top++] = c;
            else if(c=='[') stack[top++] = c;
            else if(c==']'){
                if(stack[--top]=='[')
                    stack[top] = 0;
                else{
                    printf("no\n");
                    break;
                }
            }
            else if(c==')'){
                if(stack[--top]=='(')
                    stack[top = 0];
                else{
                    printf("no\n");
                    break;
                }
            }
        }
        if(stopSwitch)
            break;
        if(top==0)
            printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
