/* Exp 6: Stack, Queue, 2-Variable Polynomial, and Sparse Matrix using Linked Lists */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node { int data; struct Node *next; } Node;
typedef struct PolyNode { int c, px, py; struct PolyNode *next; } PolyNode;
typedef struct SpNode { int r, col, val; struct SpNode *next; } SpNode;

void push(Node **top, int x) {
    Node *n = malloc(sizeof(Node)); n->data = x; n->next = *top; *top = n;
}
int pop(Node **top) {
    if (!*top) return -1;
    Node *t = *top; int v = t->data; *top = t->next; free(t); return v;
}

void enqueue(Node **f, Node **r, int x) {
    Node *n = malloc(sizeof(Node)); n->data = x; n->next = NULL;
    if (!*r) *f = *r = n; else { (*r)->next = n; *r = n; }
}
int dequeue(Node **f, Node **r) {
    if (!*f) return -1;
    Node *t = *f; int v = t->data; *f = t->next; if (!*f) *r = NULL; free(t); return v;
}

PolyNode *add_term(PolyNode *h, int c, int px, int py) {
    PolyNode *n = malloc(sizeof(PolyNode)); n->c = c; n->px = px; n->py = py; n->next = h; return n;
}

SpNode *add_sp(SpNode *h, int r, int col, int val) {
    SpNode *n = malloc(sizeof(SpNode)); n->r = r; n->col = col; n->val = val; n->next = h; return n;
}

int main(void) {
    Node *st = NULL; push(&st, 10); push(&st, 20);
    printf("Linked Stack pop: %d\n", pop(&st));

    Node *qf = NULL, *qr = NULL; enqueue(&qf, &qr, 100); enqueue(&qf, &qr, 200);
    printf("Linked Queue deq: %d\n", dequeue(&qf, &qr));

    PolyNode *p = NULL;
    p = add_term(p, 5, 2, 1); p = add_term(p, 3, 1, 1);
    printf("Linked 2-Var Poly: ");
    for (PolyNode *t = p; t; t = t->next) printf("%dx^%dy^%d ", t->c, t->px, t->py);
    printf("\n");

    SpNode *sp = NULL;
    sp = add_sp(sp, 0, 2, 9); sp = add_sp(sp, 1, 0, 4);
    printf("Linked Sparse Matrix:\n");
    for (SpNode *t = sp; t; t = t->next) printf("(%d, %d) = %d\n", t->r, t->col, t->val);
    return 0;
}
