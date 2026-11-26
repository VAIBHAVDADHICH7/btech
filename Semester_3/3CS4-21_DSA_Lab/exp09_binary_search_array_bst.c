/* Exp 9: Binary Search on Array and Linked Binary Search Tree (BST) */
#include <stdio.h>
#include <stdlib.h>

int binary_search_arr(const int a[], int n, int key) {
    int l = 0, r = n - 1;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (a[m] == key) return m;
        if (a[m] < key) l = m + 1; else r = m - 1;
    }
    return -1;
}

typedef struct BST { int key; struct BST *l, *r; } BST;

BST *bst_insert(BST *root, int key) {
    if (!root) {
        BST *n = malloc(sizeof(BST)); n->key = key; n->l = n->r = NULL; return n;
    }
    if (key < root->key) root->l = bst_insert(root->l, key);
    else if (key > root->key) root->r = bst_insert(root->r, key);
    return root;
}

BST *bst_search(BST *root, int key) {
    if (!root || root->key == key) return root;
    return (key < root->key) ? bst_search(root->l, key) : bst_search(root->r, key);
}

int main(void) {
    int arr[] = {5, 12, 19, 27, 44, 58};
    printf("Array Binary Search for 27 -> index %d\n", binary_search_arr(arr, 6, 27));

    BST *root = NULL;
    int vals[] = {27, 12, 44, 5, 19, 58};
    for (int i = 0; i < 6; i++) root = bst_insert(root, vals[i]);
    printf("BST Search for 19 -> %s\n", bst_search(root, 19) ? "FOUND" : "NOT FOUND");
    printf("BST Search for 99 -> %s\n", bst_search(root, 99) ? "FOUND" : "NOT FOUND");
    return 0;
}
