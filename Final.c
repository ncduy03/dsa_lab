#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define M 10000

typedef struct Node{
    char f_acc[21];
    int money;
    struct Node* left;
    struct Node* right;
}Node;

Node* root;

Node* makeNode(char f_acc[], int money){
    Node* p = (Node*)malloc(sizeof(Node));
    strcpy(p->f_acc, f_acc);
    p->money = 
    p->left = NULL; p->right = NULL;
    return p;
}

Node* insert(Node *root, char f_acc[], int money){
    if(root == NULL){
        root = makeNode(f_acc, money);
    }
    else{
        if(strcmp(f_acc, root->f_acc))
    }
}
int main(){
    int number_trans = 0;
    int total_money_trans = 0;
    char cmd[256];
    char f_acc[256], t_acc[256];
    int money;
    char time[256];
    char atm[256];
    while(1){
        scanf("%s", f_acc);
        if(strcmp(f_acc, "#") == 0){
            break;
        }   
        else{
            scanf("%s %s %s %s", t_acc, money, time, atm);
            number_trans++;
            total_money_trans += money;

        }
    }
    while(1){
        scanf("%s", cmd);
        if(strcmp(cmd, "#") == 0) break;
        if(strcmp(cmd, "?number_transactions") == 0){

        }
        else if(strcmp(cmd, "?total_money_transaction") == 0){

        }
        else if(strcmp(cmd, "?list_sorted_accounts") == 0){

        }
        else if (strcmp(cmd, "?total_money_transaction_from") == 0){

        }
    }
}
