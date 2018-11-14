#include <stdio.h>
#include <stdlib.h>

typedef struct Tree {
    int val;
    struct Tree *left, *right;
} Tree;


void add_node(Tree* tree, int val) {

    if (tree != NULL && tree->val == -1) {
        tree->val = val;
        return;
    }

    Tree *node = malloc(sizeof(Tree));
    node->val = val;
    node->left = NULL;
    node->right = NULL;

    /* Find the place of val */
    Tree* root = tree;
    Tree* parent = NULL;
 
    while (root != NULL) {
        parent = root;
        if (val < root->val) {
            root = root->left;
        } else {
            root = root->right;
        }
    }

    if (parent == NULL) {
        tree = node;
        printf("tree->val=%d\n", tree->val);
    } else {
        if (val < parent->val) {
            parent->left = node;
        } else {
            parent->right = node;
        }
    }
}


void build_tree(Tree *tree, int arr[], int len) {
    for (int i = 0; i < len; i++) {
        add_node(tree, arr[i]);
    }
}

void print_tree_preorder(Tree* tree) {
    if (tree) {
        printf("%d ", tree->val);
        print_tree_preorder(tree->left);
        print_tree_preorder(tree->right);
    }
}

int main(void) {
    /* 
        4
      2    6 
    1  3  5  7
    */
    int arr[] = {4, 2, 6, 1, 3, 5, 7};
    int len = 7;

    /* Initialize for a pointer is IMPORTANT! */
    Tree* tree = malloc(sizeof(Tree));
    tree->val = -1;
    tree->left = NULL;
    tree->right = NULL;

    build_tree(tree, arr, len);
    print_tree_preorder(tree);

    return 0;
}
