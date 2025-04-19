#include <stdio.h>
void recursion(int n, int j ,int k, const int x);
int main(void){
    int x;
    scanf("%d",&x);
    recursion(x,1,1,x);

    return 0;
}
void recursion(int n, int j ,int k, const int x){
    if(n!=1){
            for(int i = 0 ; i < n; i++){
                recursion(n,j+1,1,x);
            }
    }
    else{
        if((j%3)==2&(k%3)==2)
            printf(" ");
        else 
            printf("*");
    if(k==x){
        printf("\n");
        

    }
}


