#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void print(char* s){
    printf("%s in f\n",s);
    //strcat(s," world");
    s = "world";
    printf("%s in f\n",s);
    return; 
}
int main(void){
    char k[20] = "nooo\0";
    char *s = k;

    print(s);

    return 0;
}
    
