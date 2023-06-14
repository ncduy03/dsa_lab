#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int value;
    struct Node* next; // point to the next element of the current element
}Node;

Node* head = NULL;

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
    while(p->next != NULL){
        p = p->next;
    }
    Node* q = makeNode(v);
    p->next = q;
    return h;
}

Node* insertLastRecursive(Node* h, int v){
    if(h == NULL){
        return makeNode(v);
    }
    h->next = insertLastRecursive(h->next, v);
    return h;
}

Node* removeNode(Node* h, int v){
    Node* p = h;
    if(h == NULL) return NULL;
    if(h->value == v){
        Node* tmp = h; 
        h = h->next;      
        free(tmp);  return h;
    }
    while(p->next != NULL){
        if(p->next->value == v) break;
        p = p->next;
    }
    if(p->next != NULL){
        Node* q = p->next; 
        p->next = q->next; 
        free(q);
    }
    return h;
}

Node* removeNodeRecursive(Node* h, int v){
    if(h == NULL) return NULL;
    if(h->value == v){
        Node* tmp = h;
        h = h->next; 
        free(tmp); 
        return h;
    }
    h->next = removeNodeRecursive(h->next, v);
    return h;
}

Node* removeAll(Node* h, int v){
    // remove all nodes having value v from the linked list headed by h
    if(h == NULL) return NULL;
    if(h->value == v){
        Node* tmp = h; h = h->next; free(tmp);
        h = removeAll(h,v); // continue to remove other elements having value v
        return h;
    }
    h->next = removeAll(h->next,v);
    return h;
}

int count(Node* h){
    int cnt = 0;
    Node* p = h;
    while(p != NULL){
        cnt += 1;
        p = p->next;
    }
    return cnt;
}

int countRecursive(Node* h){
    if(h == NULL) return 0;
    return 1+countRecursive(h->next);
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

int main(){
    head = insertLastRecursive(head, 1);
    head = insertLast(head, 2);
    head = insertLast(head, 3);

    printf("List: \n");
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");

    int nodeCount = count(head);
    printf("%d\n", nodeCount);

    head = reverse(head);
    Node* p = head;
    while (p != NULL) {
        printf("%d ", p->value);
        p = p->next;
    }
    printf("\n");

    // Giải phóng bộ nhớ đã cấp phát cho danh sách
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
    return 0;
}