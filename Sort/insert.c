#include <stdio.h>
void insertSort(int *list);
int main(void){
    int list[] = {6, 3, 1, 7, 3, 6, 4, 3};
    insertSort(list);
    for(int i = 0 ; i < 8 ; i++)
        printf("%d, ",list[i]);
    printf("\n");

    return 0;
}
void insertSort(int* list){
    for(int i = 0; i<=7 ; i++){
        for(int j = i ; j>=0; j--){
            if(list[j]>list[j+1]){
                int temp  = list[j+1];
                list[j+1] = list[j];
                list[j] = temp;
            }
        }
    }
}
