#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc nút cây
struct Node {
    int data;
    struct Node* parent;
    struct Node* left;
    struct Node* right;
};

// Hàm tạo mới một nút
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->parent = NULL;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Hàm tìm nút cha của một nút
struct Node* findNode(struct Node* root, int data) {
    if (root == NULL)
        return NULL;
    if (root->data == data)
        return root;
    struct Node* leftResult = findNode(root->left, data);
    if (leftResult != NULL)
        return leftResult;
    return findNode(root->right, data);
}

// Hàm chèn một nút vào cuối danh sách con của một nút
void insertNode(struct Node* root, int childData, int parentData) {
    struct Node* childNode = createNode(childData);
    struct Node* parentNode = findNode(root, parentData);
    if (parentNode != NULL) {
        childNode->parent = parentNode;
        if (parentNode->left == NULL)
            parentNode->left = childNode;
        else
            parentNode->right = childNode;
    }
}

// Hàm in ra thứ tự các nút trong phép duyệt cây theo thứ tự trước (PreOrder)
void preOrderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

// Hàm in ra thứ tự các nút trong phép duyệt cây theo thứ tự giữa (InOrder)
void inOrderTraversal(struct Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

// Hàm in ra thứ tự các nút trong phép duyệt cây theo thứ tự sau (PostOrder)
void postOrderTraversal(struct Node* root) {
    if (root != NULL) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    struct Node* root = NULL;

    char action[10];
    int u, v;

    // Đọc dữ liệu và thực hiện các hành động
    while (1) {
        scanf("%s", action);
        if (action[0] == '*')
            break;
        if (action[0] == 'M') {
            scanf("%d", &u);
            root = createNode(u);
        } else if (action[0] == 'I') {
            scanf("%d %d", &u, &v);
            insertNode(root, u, v);
        } else if (action[0] == 'P' && action[1] == 'r') {
            preOrderTraversal(root);
            printf("\n");
        } else if (action[0] == 'I' && action[1] == 'n') {
            inOrderTraversal(root);
            printf("\n");
        } else if (action[0] == 'P' && action[1] == 'o') {
            postOrderTraversal(root);
            printf("\n");
        }
    }
    return 0;
}
