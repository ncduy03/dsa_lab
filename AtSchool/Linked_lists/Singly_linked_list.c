#include <stdio.h>
typedef struct Node{
    int value;
    struct Node* next;
}

Node* makeNode(int v){
    Node* p = (Node*)malloc(sizeof(Node));
    p->value = v; p->next = NULL;
    return p;
}

Node* insertLast(Node* h, int v){
      Node* p = h;
     if(h == NULL){
            return makeNode(v);
      }
      // general case
      while(p->next != NULL)
            p = p->next;

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
        Node* tmp = h; h = h->next;      
        free(tmp);  return h;
    }
    while(p->next != NULL){
        if(p->next->value == v) break;
        p = p->next;
    }
    if(p->next != NULL){
        Node* q = p->next; p->next = q->next; free(q);
    }
    return h;
}

Node* removeNodeRecursive(Node* h, int v){
    if(h == NULL) return NULL;
    if(h->value == v){
        Node* tmp = h; h = h->next; free(tmp); return h;
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

int countRecursive(Node* h){
    if(h == NULL) return 0;
    return 1+countRecursive(h->next);
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

