#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct Node{
    int value;
    struct Node* next;
}Node;

Node* head = NULL;

Node* makeNode(int v){
    Node* p = (Node*)malloc(sizeof(Node));
    p->value = v; 
    p->next = NULL;
    return p;
}

Node* insertLast(Node* h, int v){
    if(h == NULL){
        return makeNode(v);
    }
    h->next = insertLast(h->next, v);
    return h;
}

Node* insertFirst(Node* h, int v) {
    Node* p = makeNode(v);
    p->next = h;
    return p;
}

Node* reverse(Node *h){
    Node* p = h;
    Node* pp = NULL;
    Node* np = NULL;
    while(p != NULL){
        np = p->next;
        p->next = pp;
        pp = p;
        p = np;
    }
    return pp;
}

void printList(Node* h){
    Node* p = h;
    while (p != NULL) {
        printf("%d ", p->value);
        p = p->next;
    }
    printf("\n");
}

Node* addAfter(Node* h, int u, int v){
    Node* p = h;
    while (p != NULL) {
        if (p->value == v){
            Node* q = makeNode(u);
            q->next = p->next;
            p->next = q;
            break;
        }
        p = p->next;
    }
    return h;
}

Node* addBefore(Node* h, int u, int v){
    Node* p = h;
    Node* prev = NULL;
    while (p != NULL) {
        if (p->value == v){
            Node* q = makeNode(u);
            if (prev == NULL){
                q->next = p;
                h = q;
            }else{
                q->next = p;
                prev->next = q;
            }
            break;
        }
        prev = p;
        p = p->next;
    }
    return h;
}

Node* removeNode(Node* h, int v){
    if(h == NULL) return NULL;
    if(h->value == v){
        Node* tmp = h;
        h = h->next; 
        free(tmp); 
        return h;
    }
    h->next = removeNode(h->next, v);
    return h;
}

int main(){
    int n; scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int x; scanf("%d", &x);
        head = insertLast(head, x);
    }
    while(1){
        char cmd[256];
        scanf("%s",cmd);
        if(strcmp(cmd, "#") == 0){
            printList(head);
            break;
        }
        else if(strcmp(cmd, "addlast") == 0){
            int x; scanf("%d", &x);
            if(findNode(x) == 0)
                insertLast(head, x);
        } 
        else if(strcmp(cmd, "addfirst") == 0){
            int x; scanf("%d", &x);
            if(findNode(x) == 0)
                head = insertFirst(head, x);
        }
        else if(strcmp(cmd, "addafter") == 0){
            int u, v; scanf("%d %d", &u, &v);
            head = addAfter(head, u, v);
        }
        else if(strcmp(cmd, "addbefore") == 0){
            int u, v; scanf("%d %d", &u, &v);
            head = addBefore(head, u, v);
        }
        else if(strcmp(cmd, "remove") == 0){
            int x; scanf("%d", &x);
            removeNode(head, x);
        }
        else if(strcmp(cmd, "reverse") == 0){
            head = reverse(head);
        }
    }
    return 0;
}