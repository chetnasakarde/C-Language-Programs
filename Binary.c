// File: bst.c
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node* newNode(int val) {
    Node* n = malloc(sizeof(Node));
    n->data = val; n->left = n->right = NULL;
    return n;
}

Node* insert(Node* root, int val) {
    if (!root) return newNode(val);
    if (val < root->data) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

void inorder(Node* root) {
    if (root) { inorder(root->left); printf("%d ", root->data); inorder(root->right); }
}

int main() {
    Node* root = NULL;
    int arr[] = {50, 30, 20, 40, 70, 60, 80};
    for (int i=0;i<7;i++) root = insert(root, arr[i]);
    inorder(root);
    return 0;
}
