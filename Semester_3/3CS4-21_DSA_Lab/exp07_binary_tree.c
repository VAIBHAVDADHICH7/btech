/* Exp 7: Binary Tree Creation, Deletion, and Traversals */
#include <stdio.h>
#include <stdlib.h>

typedef struct TNode {
    int data;
    struct TNode *left, *right;
} TNode;

TNode *new_node(int val) {
    TNode *n = malloc(sizeof(TNode));
    n->data = val; n->left = n->right = NULL;
    return n;
}

void inorder(TNode *r) { if (r) { inorder(r->left); printf("%d ", r->data); inorder(r->right); } }
void preorder(TNode *r) { if (r) { printf("%d ", r->data); preorder(r->left); preorder(r->right); } }
void postorder(TNode *r) { if (r) { postorder(r->left); postorder(r->right); printf("%d ", r->data); } }

int main(void) {
    TNode *root = new_node(1);
    root->left = new_node(2);
    root->right = new_node(3);
    root->left->left = new_node(4);
    root->left->right = new_node(5);

    printf("Inorder   : "); inorder(root); printf("\n");
    printf("Preorder  : "); preorder(root); printf("\n");
    printf("Postorder : "); postorder(root); printf("\n");
    return 0;
}
