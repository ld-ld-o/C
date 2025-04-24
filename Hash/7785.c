#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node{
    char* key;
    int value;
    struct Node* next;
    struct Node* prev;
}Node;
void print(Node* hashTable[],int size);
int hashFunction(const char* key);
void insert(const char* key, int value, Node* hashTable[]);
Node* search(const char* key, Node* hashTable[]);
void delete(const char* key, Node* hashTable[]);

int main(void){
    Node* hashTable[15];
    memset(hashTable,0,sizeof(hashTable));
    int n;
    scanf("%d",&n);
    char name[6],status[6];
    int state;
    int size = 0;
    for(int i = 0;i<n;i++){
        scanf("%s",name);
        scanf("%s",status);
        if(strcmp(status,"enter")==0){
            state = 1;
            size++;
        }
        else if(strcmp(status,"leave")==0){
            state = 0;
            size--;
        }
        insert(name,state,hashTable);
    }
    print(hashTable,size);

    return 0;
}
void print(Node* hashTable[],int size){
    char nameList[size][6];
    int id =0; 
    for(int i = 0 ; i < 15 ;i++){
        Node* iter = hashTable[i];
        if(iter == NULL) continue;
        else{
            while(iter->next != NULL){
                if(iter->value==1){
                    strcpy(nameList[id++],iter->key);
                }
                iter = iter-> next;
            }
            if(iter->value==1){
                strcpy(nameList[id++],iter->key);
            }
        }
    }

    for(int i = id ; i > 0; i--){
        for(int j = 0 ; j < i-1 ; j++){
            if(strcmp(nameList[j],nameList[j+1])<0){
                char temp[6];
                strcpy(temp,nameList[j]);
                strcpy(nameList[j],nameList[j+1]);
                strcpy(nameList[j+1],temp);
            }
        }
    }

    for(int i = 0 ; i<id; i++)
        printf("%s\n",nameList[i]);

}
int hashFunction(const char* key){
    int hash = 0;
    for(int i = 0; key[i]!='\0' ; i++){
        hash = (hash*31 + key[i])%15;
    }
    return hash;
}
void insert(const char* key, int value, Node* hashTable[]){
    Node* location = search(key, hashTable);
    if(location == NULL){
        location = (Node*)malloc(sizeof(Node));
        location->key = (char*) malloc(sizeof(char)*10);
        strcpy(location->key,key);
        location->value = value;
        hashTable[hashFunction(key)] = location;
    }
    else if(strcmp(location->key, key) ==0){ // 존재
        location->value = value;
    }
    else{
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->key = (char*) malloc(sizeof(char)*10);
        strcpy(newNode->key,key);
        newNode->value = value;
        location->next = newNode;
        newNode->prev = location;
    }
}
Node* search(const char* key, Node* hashTable[]){
    int idx = hashFunction(key);
    Node *current = hashTable[idx];
    if(current == NULL)
        return current;
    while(current->next!=NULL && strcmp(current->key, key)!=0){
        current = current->next;
    }
    return current;
}
void delete(const char* key, Node* hashTable[]){
    Node* delNode = search(key, hashTable);
    if(delNode==NULL)
        printf("errer : 존재하지 않음\n");
    else if(strcmp(delNode->key,key)==0){
        if(delNode->next !=NULL){
            if(hashTable[hashFunction(key)] == delNode)
                hashTable[hashFunction(key)] = delNode->next;
            else{
                delNode->prev->next = delNode->next;
                delNode->next->prev = delNode->prev;
            }
        }
        else{
            if(hashTable[hashFunction(key)] == delNode)
                hashTable[hashFunction(key)] = NULL;
            else
                delNode->prev->next = NULL;
        }
        free(delNode);
    }
    else
        printf("errer : 존재하지 않음\n");
}
