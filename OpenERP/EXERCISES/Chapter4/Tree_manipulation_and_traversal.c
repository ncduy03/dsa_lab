#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node{
    int id;
    struct Node* leftChild;
    struct Node* rightChild;
} Node;

int max(int a, int b){
    return (a > b) ? a : b;
}

int height(Node* p){
    if (p == NULL) return 0;
    int hl = height(p->leftChild);
    int hr = height(p->rightChild);
    return max(hl, hr) + 1;
}

int isBalanced(Node* p){
    if (p == NULL) return 1;
    int hl = height(p->leftChild);
    int hr = height(p->rightChild);
    if (abs(hl - hr) <= 1 && isBalanced(p->leftChild) && isBalanced(p->rightChild)) {
        return 1;
    }
    return 0;
}

Node* createNode(int id){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->id = id;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    return newNode;
}

void addLeft(Node* parent, int id){
    Node* newNode = createNode(id);
    parent->leftChild = newNode;
}

void addRight(Node* parent, int id){
    Node* newNode = createNode(id);
    parent->rightChild = newNode;
}

Node* makeRoot(int id){
    return createNode(id);
}

Node* findNode(Node* current, int id){
    if (current == NULL) return NULL;
    if (current->id == id) return current;
    Node* leftResult = findNode(current->leftChild, id);
    if (leftResult != NULL) return leftResult;
    Node* rightResult = findNode(current->rightChild, id);
    return rightResult;
}

int main(){
    Node* root = NULL;
    int u, v;
    while(1){
        char cmd[256];
        scanf("%s", cmd);
        if(strcmp(cmd, "*") == 0) break;
        else if(strcmp(cmd, "MakeRoot") == 0){
            scanf("%d", &u);
            root = makeRoot(u);
        }
        else if(strcmp(cmd, "AddLeft") == 0){
            scanf("%d %d", &u, &v);
            Node* parent = findNode(root, v);
            if (parent != NULL) {
                addLeft(parent, u);
            }
        }
        else if(strcmp(cmd, "AddRight") == 0){
            scanf("%d %d", &u, &v);
            Node* parent = findNode(root, v);
            if (parent != NULL) {
                addRight(parent, u);
            }
        }
    }
    int treeHeight = height(root);
    int isTreeBalanced = isBalanced(root);
    printf("%d %d\n", isTreeBalanced, treeHeight);
    return 0;
}
