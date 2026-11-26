/* Exp 5: Singly, Doubly, and Circular Linked Lists */
#include <stdio.h>
#include <stdlib.h>

typedef struct SNode { int data; struct SNode *next; } SNode;
typedef struct DNode { int data; struct DNode *prev, *next; } DNode;

SNode *s_insert_front(SNode *head, int val) {
    SNode *n = malloc(sizeof(SNode)); n->data = val; n->next = head; return n;
}
SNode *s_delete(SNode *head, int val) {
    SNode *curr = head, *prev = NULL;
    while (curr && curr->data != val) { prev = curr; curr = curr->next; }
    if (!curr) return head;
    if (!prev) head = curr->next; else prev->next = curr->next;
    free(curr);
    return head;
}
void s_print(SNode *h) {
    printf("Singly LL: ");
    for (; h; h = h->next) printf("%d -> ", h->data);
    printf("NULL\n");
}

DNode *d_insert_front(DNode *head, int val) {
    DNode *n = malloc(sizeof(DNode)); n->data = val; n->prev = NULL; n->next = head;
    if (head) head->prev = n;
    return n;
}
void d_print(DNode *h) {
    printf("Doubly LL: ");
    for (; h; h = h->next) printf("%d <-> ", h->data);
    printf("NULL\n");
}

SNode *c_insert(SNode *tail, int val) {
    SNode *n = malloc(sizeof(SNode)); n->data = val;
    if (!tail) { n->next = n; return n; }
    n->next = tail->next; tail->next = n; return n;
}
void c_print(SNode *tail) {
    printf("Circular LL: ");
    if (!tail) { printf("EMPTY\n"); return; }
    SNode *p = tail->next;
    do { printf("%d -> ", p->data); p = p->next; } while (p != tail->next);
    printf("(back to head)\n");
}

int main(void) {
    SNode *sh = NULL;
    sh = s_insert_front(sh, 30); sh = s_insert_front(sh, 20); sh = s_insert_front(sh, 10);
    s_print(sh); sh = s_delete(sh, 20); s_print(sh);

    DNode *dh = NULL;
    dh = d_insert_front(dh, 200); dh = d_insert_front(dh, 100);
    d_print(dh);

    SNode *ct = NULL;
    ct = c_insert(ct, 1); ct = c_insert(ct, 2); ct = c_insert(ct, 3);
    c_print(ct);
    return 0;
}
