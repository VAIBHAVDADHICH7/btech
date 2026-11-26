/* Exp 6: 2D Transformations (Translation, Rotation, Scaling, Reflection, Shear) */
#include <stdio.h>
#include <math.h>
#define PI 3.14159265

int main(void) {
    double x = 4.0, y = 3.0;
    printf("Original: (%.2f, %.2f)\n", x, y);
    printf("Translated (+5,+2): (%.2f, %.2f)\n", x + 5, y + 2);
    double rad = 45.0 * PI / 180.0;
    printf("Rotated (45 deg)  : (%.2f, %.2f)\n", x * cos(rad) - y * sin(rad), x * sin(rad) + y * cos(rad));
    printf("Scaled (2x, 3y)   : (%.2f, %.2f)\n", x * 2, y * 3);
    printf("Reflected (X-axis): (%.2f, %.2f)\n", x, -y);
    printf("Sheared (shx=1.5) : (%.2f, %.2f)\n", x + 1.5 * y, y);
    return 0;
}
