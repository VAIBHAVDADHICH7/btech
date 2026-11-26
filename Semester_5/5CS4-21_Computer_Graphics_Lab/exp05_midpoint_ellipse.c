/* Exp 5: Mid-Point Ellipse Generating Algorithm */
#include <stdio.h>

void midpoint_ellipse(int rx, int ry, int xc, int yc) {
    float x = 0, y = (float)ry;
    float d1 = (ry * ry) - (rx * rx * ry) + (0.25f * rx * rx);
    float dx = 2 * ry * ry * x, dy = 2 * rx * rx * y;
    printf("Mid-point Ellipse (rx=%d, ry=%d) Region 1:\n", rx, ry);
    while (dx < dy) {
        printf("(%.0f,%.0f) ", xc + x, yc + y);
        if (d1 < 0) { x++; dx += 2 * ry * ry; d1 += dx + ry * ry; }
        else { x++; y--; dx += 2 * ry * ry; dy -= 2 * rx * rx; d1 += dx - dy + ry * ry; }
    }
    printf("\n");
}

int main(void) { midpoint_ellipse(8, 6, 0, 0); return 0; }
