#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node{
    char* key;
    int value;
    struct Node* next;
    struct Node* prev;
}Node;
int hashFunction(const char* key);
void insert(const char* key, int value, Node* hashTable[]);
Node* search(const char* key, Node* hashTable[]);
void delete(const char* key, Node* hashTable[]);

int main(void){
    Node* hashTable[100];
    insert("qkr",1,hashTable);
    Node* n = search("qkr",hashTable);
    printf("%s, %d \n",n->key,n->value);
    delete("qkr",hashTable);
    delete("qkr",hashTable);
    return 0;
}
int hashFunction(const char* key){
    int hash = 0;
    for(int i = 0; key[i]!='\0' ; i++){
        hash = (hash*31 + key[i])%100;
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
    else if(strcmp(location->key, key) !=0){ // 존재
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
    while(current->next!=NULL&&strcmp(current->key, key)!=0){
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
