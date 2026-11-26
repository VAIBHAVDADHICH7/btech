/* Exp 1: Line, Circle, and Ellipse Attributes (Portable C Framebuffer Demo) */
#include <stdio.h>
typedef struct { const char *style; int thickness; const char *color; } PrimitiveAttr;
int main(void) {
    PrimitiveAttr line = {"DASHED", 2, "BLUE"};
    PrimitiveAttr circle = {"SOLID", 1, "RED"};
    PrimitiveAttr ellipse = {"DOTTED", 3, "GREEN"};
    printf("Line    -> style=%s, width=%d, color=%s\n", line.style, line.thickness, line.color);
    printf("Circle  -> style=%s, width=%d, color=%s\n", circle.style, circle.thickness, circle.color);
    printf("Ellipse -> style=%s, width=%d, color=%s\n", ellipse.style, ellipse.thickness, ellipse.color);
    return 0;
}
