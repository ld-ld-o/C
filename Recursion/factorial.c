#include <stdio.h>
int fact(int n);
int main(void){
    int n;
    scanf("%d",&n);
    printf("%d",fact(n));
    return 0;
}
int fact(int n){
    if(n==0)
        return 1;
    else
        return n*fact(n-1);
}
