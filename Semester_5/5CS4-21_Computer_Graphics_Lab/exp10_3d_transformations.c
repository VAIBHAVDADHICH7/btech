/* Exp 10: 3D Translation, Scaling, and Rotation about Z-axis */
#include <stdio.h>
#include <math.h>
#define PI 3.14159265

int main(void) {
    double x = 2, y = 3, z = 4;
    printf("3D Original : (%.2f, %.2f, %.2f)\n", x, y, z);
    printf("Translated  : (%.2f, %.2f, %.2f)\n", x + 5, y - 2, z + 3);
    printf("Scaled      : (%.2f, %.2f, %.2f)\n", x * 2, y * 2, z * 2);
    double r = 90.0 * PI / 180.0;
    printf("Rot-Z (90d) : (%.2f, %.2f, %.2f)\n", x*cos(r)-y*sin(r), x*sin(r)+y*cos(r), z);
    return 0;
}
