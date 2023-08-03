#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* getNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void inorderTraversal(struct Node* root, int* arr, int* i) {
    if (root == NULL)
        return;

    inorderTraversal(root->left, arr, i);
    arr[(*i)++] = root->data;
    inorderTraversal(root->right, arr, i);
}

void BSTToMaxHeap(struct Node* root, int* arr, int* i) {
    if (root == NULL)
        return;

    BSTToMaxHeap(root->left, arr, i);
    BSTToMaxHeap(root->right, arr, i);

    root->data = arr[(*i)++];
}

void convertToMaxHeapUtil(struct Node* root) {
    int arr[100]; // Assuming the maximum number of nodes in the BST is 100
    int i = 0;
    inorderTraversal(root, arr, &i);

    i = 0;
    BSTToMaxHeap(root, arr, &i);
}

void postorderTraversal(struct Node* root) {
    if (!root)
        return;

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}
void inorder(struct Node* root) {
    if (!root)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
    
}

int main() {
    struct Node* root = getNode(4);
    root->left = getNode(2);
    root->right = getNode(6);
    root->left->left = getNode(1);
    root->left->right = getNode(3);
    root->right->left = getNode(5);
    root->right->right = getNode(7);

    convertToMaxHeapUtil(root);
    printf("inorder Traversal of Tree:\n");
    inorder(root);
    return 0;
}
