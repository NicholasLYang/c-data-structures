#include <stdio.h>
#include <stdlib.h>

struct treeNode {
    int data;
    struct treeNode* left;
    struct treeNode* right;
};

// newTreeNode() allocates a new treeNode with the given data and NULL left
// and right pointers
struct treeNode* newTreeNode(int data) {
    // Allocate memory for new treeNode
    struct treeNode* node = (struct treeNode*)malloc(sizeof(struct treeNode));

    // Assign the data to this treeNode
    node->data = data;

    node->left = NULL;
    node->right = NULL;

    return(node);
}

void preOrderTraversal(struct treeNode* root) {
    if (root == NULL) {
        return;
    }
    printf(" %i ", root->data);

    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void inOrderTraversal(struct treeNode* root) {
    if (root == NULL) {
        return;
    }

    inOrderTraversal(root->left);
    printf(" %i ", root->data);
    inOrderTraversal(root->right);
}

void postOrderTraversal(struct treeNode* root) {
    if (root == NULL) {
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    printf(" %i ", root->data);
}

int isEqual(struct treeNode* rootA, struct treeNode* rootB) {
    if (rootA == NULL && rootB == NULL) {
        return 1;
    }
    if ((rootA == NULL) ||
        (rootB == NULL) ||
        (rootA->data != rootB->data)) {
        return 0;
    }

    return(isEqual(rootA->left, rootB->left) && isEqual(rootA->right, rootB->right));
}

/*
 int main() {
    struct treeNode* rootA = newNode(120);
    rootA->left = newNode(10);
    rootA->right = newNode(12);
    rootA->left->left = newNode(2);
    rootA->left->right = newNode(5);
    rootA->right->left = newNode(3);
    rootA->right->right = newNode(4);
    rootA->right->right->right = newNode(2);
    rootA->right->right->left = newNode(2);

    struct treeNode* rootB = newNode(120);
    rootB->left = newNode(10);
    rootB->right = newNode(12);
    rootB->left->left = newNode(2);
    rootB->left->right = newNode(5);
    rootB->right->left = newNode(3);
    rootB->right->right = newTreeNode(4);
    rootB->right->right->right = newNode(2);
    rootB->right->right->left = newNode(2);

    if (isEqual(rootA, rootB) == 1) {
        printf("True");
    } else {
        printf("False");
    }
    printf("Pre order: ");
    preOrderTraversal(rootA);
    printf("\n");
    printf("In order: ");
    inOrderTraversal(rootA);
    printf("\n");
    printf("Post order: ");
    postOrderTraversal(rootA);
    return 0;
}
 */