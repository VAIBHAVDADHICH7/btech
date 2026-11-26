/* Exp 11: Composite 3D Transformation (4x4 Homogeneous Matrix) */
#include <stdio.h>

int main(void) {
    double M[4][4] = {{2,0,0,10}, {0,2,0,20}, {0,0,2,30}, {0,0,0,1}};
    double p[4] = {1, 2, 3, 1}, res[4] = {0};
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++) res[i] += M[i][j] * p[j];
    printf("Composite 3D Result: (%.2f, %.2f, %.2f)\n", res[0], res[1], res[2]);
    return 0;
}
