#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define M 10000

typedef struct Node {
    char fromacc[21];
    int total_money;
    struct Node* left;
    struct Node* right;
} Node;

Node* root[M];

int h(char* s) {
    int n = strlen(s);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum = (sum * 256 + s[i]) % M;
    }
    return sum;
}

Node* makeNode(char fromacc[], int total_money) {
    Node* p = (Node*)malloc(sizeof(Node));
    strcpy(p->fromacc, fromacc);
    p->total_money = total_money;
    p->left = NULL;
    p->right = NULL;
    return p;
}

Node* findtrans(Node* root, char fromacc[21]) {
    if (root == NULL) {
        return NULL;
    }
    if (strcmp(root->fromacc, fromacc) == 0) {
        return root;
    }
    if (strcmp(fromacc, root->fromacc) < 0) {
        return findtrans(root->right, fromacc);
    }
    else {
        return findtrans(root->left, fromacc);
    }
}

Node* inserttrans(Node* root, char fromacc[], int total_money) {
    if (root == NULL) {
        root = makeNode(fromacc, total_money);
    }
    else {
        if (strcmp(fromacc, root->fromacc) < 0) {
            root->right = inserttrans(root->right, fromacc, total_money);
        }
        else if (strcmp(fromacc, root->fromacc) > 0) {
            root->left = inserttrans(root->left, fromacc, total_money);
        }
        else {
            return root;
        }
    }
    return root;
}

int number_trans = 0;
int total_money_trans = 0;

void printSortedAccounts(Node* root) {
    if (root != NULL) {
        printSortedAccounts(root->left);
        printf("%s ", root->fromacc);
        printSortedAccounts(root->right);
    }
}

int inspectCycle(Node* root, char fromacc[], char startacc[], int k, int count) {
    if (k == 0 && strcmp(fromacc, startacc) == 0) {
        return 1;
    }
    Node* p = findtrans(root, fromacc);
    if (p == NULL || count >= k) {
        return 0;
    }
    char nextacc[21];
    strcpy(nextacc, p->left->fromacc);
    return inspectCycle(root, nextacc, startacc, k, count + 1);
}

int main() {
    for (int i = 0; i < M; i++) root[i] = NULL;
    char cmd[256];
    char from_acc[256];
    char to_acc[256];
    int money;
    char time[256];
    char atm[256];
    while (1) {
        scanf("%s", from_acc);
        if (strcmp(from_acc, "#") == 0) break;
        else {
            scanf("%s %d %s %s", to_acc, &money, time, atm);
            number_trans++;
            total_money_trans += money;
            int index = h(from_acc);
            Node* p = findtrans(root[index], from_acc);
            if (p == NULL) {
                root[index] = inserttrans(root[index], from_acc, money);
            }
            else {
                p->total_money += money;
            }
        }
    }
    while (1) {
        scanf("%s", cmd);
        if (strcmp(cmd, "#") == 0) break;
        if (strcmp(cmd, "?number_transactions") == 0) {
            printf("%d\n", number_trans);
        }
        else if (strcmp(cmd, "?total_money_transaction") == 0) {
            printf("%d\n", total_money_trans);
        }
        else if (strcmp(cmd, "?list_sorted_accounts") == 0) {
            for (int i = 0; i < M; i++) {
                printSortedAccounts(root[i]);
            }
            printf("\n");
        }
        else if (strcmp(cmd, "?total_money_transaction_from") == 0) {
            char fromacc[21];
            scanf("%s", fromacc);
            int index = h(fromacc);
            Node* p = findtrans(root[index], fromacc);
            if (p == NULL) {
                printf("0\n");
            }
            else {
                printf("%d\n", p->total_money);
            }
        }
        else if (strcmp(cmd, "?inspect_cycle") == 0) {
            char account[21];
            int k;
            scanf("%s %d", account, &k);
            int index = h(account);
            int result = inspectCycle(root[index], from_acc, from_acc, k, 0);
            printf("%d\n", result);
        }
    }
    return 0;
}
