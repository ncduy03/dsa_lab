#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void traverseList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int countNodes(struct Node* head) {
    int count = 0;
    struct Node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

void insertAtBeginning(struct Node** headRef, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *headRef;
    *headRef = newNode;
}

void insertAtPosition(struct Node** headRef, int data, int k) {
    if (k == 1) {
        insertAtBeginning(headRef, data);
        return;
    }

    struct Node* newNode = createNode(data);
    struct Node* current = *headRef;

    for (int i = 1; i < k - 1 && current != NULL; i++) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Position is greater than the number of nodes in the list.\n");
        return;
    }

    newNode->next = current->next;
    current->next = newNode;
}

int main() {
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);

    traverseList(head);
    // printf("Number of Nodes: %d\n", countNodes(head));
    // insertAtBeginning(&head, 0);
    // traverseList(head);
    // insertAtPosition(&head, 10, 3);
    // traverseList(head);
    return 0;
}
