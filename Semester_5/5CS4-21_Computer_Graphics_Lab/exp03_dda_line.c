/* Exp 3: DDA (Digital Differential Analyzer) Line Drawing Algorithm */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void dda_line(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1, dy = y2 - y1;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    float x_inc = dx / (float)steps, y_inc = dy / (float)steps;
    float x = (float)x1, y = (float)y1;
    printf("DDA Line pixels from (%d,%d) to (%d,%d):\n", x1, y1, x2, y2);
    for (int i = 0; i <= steps; i++) {
        printf("(%d, %d) ", (int)roundf(x), (int)roundf(y));
        x += x_inc; y += y_inc;
    }
    printf("\n");
}

int main(void) { dda_line(2, 3, 12, 8); return 0; }
