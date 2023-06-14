#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node{
    int value;
    struct Node* next;
    struct Node* prev;
}Node;

Node *first, *last;

Node* makeNode(int v){
    Node* p = (Node*)malloc(sizeof(Node));
    p->value = v; 
    p->next = NULL;
    p->prev = NULL;
    return p;
}

void initList(){
    first = NULL;
    last = NULL;
}

int listEmpty(){
    return first == NULL && last == NULL;
}

void printListLeft2Right(){
    for(Node* p = first; p != NULL; p = p->next)
        printf("%d ", p->value);
}

void printListRight2Left(){
    for(Node* p = last; p != NULL; p = p->prev)
        printf("%d ", p->value);
}

void insertLast(int v){
    Node* p = makeNode(v);
    if(listEmpty()){
        first = p;
        last = p;
    }else{
        last->next = p;
        p->prev = last;
        last = p;
    }
}

void insertFirst(int v){
    Node* p = makeNode(v);
    if(listEmpty()){
        first = p;
        last = p;
    }else{
        p->next = first;
        first->prev = p;
        first = p;
    }
}

Node* findNode(int v){
    for(Node* p = first; p != NULL; p = p->next){
        if(p->value == v){
            return p;
        }
    }
    return NULL;
}

void insertAfter(int u, int v){
    Node* p = findNode(v);
    if(p != NULL){
        Node* newNode = makeNode(u);
        newNode->next = p->next;
        newNode->prev = p;
        if(p->next != NULL)
            p->next->prev = newNode;
        p->next = newNode;
        if(p == last)
            last = newNode;
    }
}

void insertBefore(int u, int v){
    Node* p = findNode(v);
    if(p != NULL){
        Node* newNode = makeNode(u);
        newNode->next = p;
        newNode->prev = p->prev;
        if(p->prev != NULL)
            p->prev->next = newNode;
        p->prev = newNode;
        if(p == first)
            first = newNode;
    }
}

void removeNode(int v){
    if(listEmpty()) return;
    Node* p = findNode(v);
    if(p != NULL){
        Node* left = p->prev;
        Node* right = p->next;
        if(left != NULL)
            left->next = right;
        if(right != NULL)
            right->prev = left;
        if(p == first)
            first = right;
        if(p == last)
            last = left;
        free(p);
    }
}

Node* reverse(Node* h){
    Node* current = h;
    Node* temp = NULL;
    while (current != NULL) {
        temp = current->next;
        current->next = current->prev;
        current->prev = temp;
        current = temp;
    }
    first = h;
    return first;
}


int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int x;
        scanf("%d", &x);
        insertLast(x);
    }

    while(1){
        char cmd[256];
        scanf("%s", cmd);
        if(strcmp(cmd, "#") == 0){
            printListLeft2Right();
            break;
        }
        else if(strcmp(cmd, "addlast") == 0){
            int x;
            scanf("%d", &x);
            if(findNode(x) == NULL)
                insertLast(x);
        } 
        else if(strcmp(cmd, "addfirst") == 0){
            int x;
            scanf("%d", &x);
            if(findNode(x) == NULL)
                insertFirst(x);
        }
        else if(strcmp(cmd, "addafter") == 0){
            int u, v;
            scanf("%d %d", &u, &v);
            if(findNode(u) == NULL)
                insertAfter(u, v);
        }
        else if(strcmp(cmd, "addbefore") == 0){
            int u, v;
            scanf("%d %d", &u, &v);
            if(findNode(u) == NULL)
                insertBefore(u, v);
        }
        else if(strcmp(cmd, "remove") == 0){
            int x;
            scanf("%d", &x);
            removeNode(x);
        }
        else if(strcmp(cmd, "reverse") == 0){
            first = reverse(first);
            Node* temp = first;
            first = last;
            last = temp;
        }
    }
    return 0;
}
