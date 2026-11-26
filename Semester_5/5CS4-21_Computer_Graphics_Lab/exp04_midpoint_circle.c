/* Exp 4: Mid-Point Circle Generating Algorithm */
#include <stdio.h>

void midpoint_circle(int xc, int yc, int r) {
    int x = 0, y = r, p = 1 - r;
    printf("Mid-point Circle (center=%d,%d, r=%d) octant-1 points:\n", xc, yc, r);
    while (x <= y) {
        printf("(%d,%d) ", xc + x, yc + y);
        x++;
        if (p < 0) p += 2 * x + 1;
        else { y--; p += 2 * (x - y) + 1; }
    }
    printf("\n");
}

int main(void) { midpoint_circle(50, 50, 10); return 0; }
