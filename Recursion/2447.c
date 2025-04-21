#include <stdio.h>
void recursion(int n, int j ,int k, const int x);
int main(void){
    int x;
    scanf("%d",&x);
    recursion(x,1,1,x);

    return 0;
}
void recursion(int n, int j ,int k, const int x){
    for(int i = 1 ; i<4;i++){

        for(int j = 1 ; j < 4; j++){
            if((j)==2&(k)==2)
                printf(" ");
            else 
                printf("*");
            if(n!=1)
                recursion(n/3,i,j,x);
        }
    }


    if(n!=1){
        for(int i = 1 ; i<4;i++){
            recursion(n/3,i,j,x);
            for(int j = 1 ; j < 4; j++){
                recursion(n/3,i,j,x);
            }
            if(n==x)
                printf("\n");
        }
    }
    else{
    }
}


