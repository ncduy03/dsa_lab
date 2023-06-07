#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int value;
    struct Node* next; // point to the next element of the current element
}Node;

Node* makeNode(int v){
    Node* p = (Node*)malloc(sizeof(Node));
    p->value = v; 
    p->next = NULL;
    return p;
}

Node* insertLast(Node* h, int v){
    Node* p = h;
    if(h == NULL){
        return makeNode(v);
    }
    // general case
    
}
