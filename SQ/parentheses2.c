#include <stdio.h>

int main(void){
    while(1){
        char stack[1000] = {0};
        char c;
        int top=0;
        int stopSwitch = 0;
        int isValid = 1;
        for(int i = 0 ; i<1000;i++){
            scanf("%c",&c);
            if(c=='.'){
                if(i==0)
                    stopSwitch = 1; 
                break;
            }
            if(c=='(') stack[top++] = c;
            else if(c=='[') stack[top++] = c;
            else if(c==']'){
                if(top!=0&&stack[top-1]=='[')
                    stack[--top] = 0;
                else{
                    isValid = 0;
                     
                    break;
                }
            }
            else if(c==')'){
                if(top!=0&&stack[top-1]=='(')
                    stack[--top]=0;
                else{
                    isValid = 0;
                    break;
                }
            }
        }
        if(stopSwitch)
            break;
        if(top==0&&isValid)
            printf("yes\n");
        else
            printf("no\n");
        while (c != '\n') scanf("%c", &c);
    }
    return 0;
}
