/* Exp 2: Stack, Queue, Circular Queue, and Deque using 1-D Arrays */
#include <stdio.h>
#define MAX 5

/* Stack */
int stack[MAX], top = -1;
void push(int x) { if (top < MAX - 1) stack[++top] = x; }
int pop(void) { return (top >= 0) ? stack[top--] : -1; }
void print_stack(void) {
    printf("Stack: ");
    for (int i = top; i >= 0; i--) printf("%d ", stack[i]);
    printf("\n");
}

/* Linear Queue */
int lq[MAX], lf = 0, lr = -1;
void lq_enq(int x) { if (lr < MAX - 1) lq[++lr] = x; }
int lq_deq(void) { return (lf <= lr) ? lq[lf++] : -1; }
void print_lq(void) {
    printf("Linear Queue: ");
    for (int i = lf; i <= lr; i++) printf("%d ", lq[i]);
    printf("\n");
}

/* Circular Queue */
int cq[MAX], cf = -1, cr = -1;
void cq_enq(int x) {
    if ((cr + 1) % MAX == cf) return;
    if (cf == -1) cf = 0;
    cr = (cr + 1) % MAX;
    cq[cr] = x;
}
int cq_deq(void) {
    if (cf == -1) return -1;
    int v = cq[cf];
    if (cf == cr) cf = cr = -1;
    else cf = (cf + 1) % MAX;
    return v;
}
void print_cq(void) {
    printf("Circular Queue: ");
    if (cf != -1) {
        int i = cf;
        while (1) {
            printf("%d ", cq[i]);
            if (i == cr) break;
            i = (i + 1) % MAX;
        }
    }
    printf("\n");
}

/* Deque */
int dq[MAX], df = -1, dr = -1;
void dq_push_front(int x) {
    if ((df == 0 && dr == MAX - 1) || (df == dr + 1)) return;
    if (df == -1) df = dr = 0;
    else if (df == 0) df = MAX - 1;
    else df--;
    dq[df] = x;
}
void dq_push_rear(int x) {
    if ((df == 0 && dr == MAX - 1) || (df == dr + 1)) return;
    if (df == -1) df = dr = 0;
    else dr = (dr + 1) % MAX;
    dq[dr] = x;
}
void print_dq(void) {
    printf("Deque: ");
    if (df != -1) {
        int i = df;
        while (1) {
            printf("%d ", dq[i]);
            if (i == dr) break;
            i = (i + 1) % MAX;
        }
    }
    printf("\n");
}

int main(void) {
    push(10); push(20); push(30); print_stack();
    printf("Popped: %d\n", pop()); print_stack();

    lq_enq(1); lq_enq(2); lq_enq(3); print_lq();
    printf("Dequeued: %d\n", lq_deq()); print_lq();

    cq_enq(11); cq_enq(22); cq_enq(33); cq_deq(); cq_enq(44); print_cq();

    dq_push_rear(100); dq_push_front(50); dq_push_rear(200); print_dq();
    return 0;
}
