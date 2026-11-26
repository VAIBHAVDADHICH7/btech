/* Exp 8: Cohen-Sutherland 2D Line Clipping Algorithm */
#include <stdio.h>
#define INSIDE 0
#define LEFT   1
#define RIGHT  2
#define BOTTOM 4
#define TOP    8

double xmin = 10, ymin = 10, xmax = 100, ymax = 100;

int outcode(double x, double y) {
    int c = INSIDE;
    if (x < xmin) c |= LEFT; else if (x > xmax) c |= RIGHT;
    if (y < ymin) c |= BOTTOM; else if (y > ymax) c |= TOP;
    return c;
}

void clip_line(double x1, double y1, double x2, double y2) {
    int c1 = outcode(x1, y1), c2 = outcode(x2, y2), accept = 0;
    while (1) {
        if ((c1 | c2) == 0) { accept = 1; break; }
        else if (c1 & c2) break;
        else {
            double x = 0, y = 0;
            int out = c1 ? c1 : c2;
            if (out & TOP)         { x = x1 + (x2 - x1) * (ymax - y1) / (y2 - y1); y = ymax; }
            else if (out & BOTTOM) { x = x1 + (x2 - x1) * (ymin - y1) / (y2 - y1); y = ymin; }
            else if (out & RIGHT)  { y = y1 + (y2 - y1) * (xmax - x1) / (x2 - x1); x = xmax; }
            else if (out & LEFT)   { y = y1 + (y2 - y1) * (xmin - x1) / (x2 - x1); x = xmin; }
            if (out == c1) { x1 = x; y1 = y; c1 = outcode(x1, y1); }
            else           { x2 = x; y2 = y; c2 = outcode(x2, y2); }
        }
    }
    if (accept) printf("Clipped Line: (%.2f, %.2f) -> (%.2f, %.2f)\n", x1, y1, x2, y2);
    else printf("Line rejected.\n");
}

int main(void) { clip_line(0, 0, 120, 80); return 0; }
