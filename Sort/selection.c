#include <stdio.h>
void selectionSort(int* list);
void swap(int* list,int index1,int index2);
int main(void){
    int list[] = {6, 3, 1, 7, 3, 6, 4, 3};
    selectionSort(list);
    for(int i = 0 ; i < 8 ; i++)
        printf("%d, ",list[i]);
    printf("\n");

    return 0;
}
void selectionSort(int* list){
    for(int i = 0; i<8 ; i++){
        int min=10000;
        int index;
        for(int j = i ; j<8; j++){
            if(list[j]<min){
                min = list[j];
                index = j;
            }
        }
        swap(list,i,index);
    }
}
void swap(int* list,int index1,int index2){
    int temp = list[index1];
    list[index1] = list[index2];
    list[index2] = temp;
}
