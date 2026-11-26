/* Exp 7: Composite 2D Transformation using 3x3 Homogeneous Matrices */
#include <stdio.h>
#include <math.h>

void mat_mul(double A[3][3], double B[3][3], double C[3][3]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) {
            C[i][j] = 0;
            for (int k = 0; k < 3; k++) C[i][j] += A[i][k] * B[k][j];
        }
}

int main(void) {
    double T[3][3] = {{1,0,10}, {0,1,5}, {0,0,1}};
    double S[3][3] = {{2,0,0},  {0,2,0}, {0,0,1}};
    double M[3][3];
    mat_mul(T, S, M);
    double x = 3, y = 4;
    double nx = M[0][0]*x + M[0][1]*y + M[0][2];
    double ny = M[1][0]*x + M[1][1]*y + M[1][2];
    printf("Composite (Scale 2x then Translate +10,+5) on (3,4) -> (%.2f, %.2f)\n", nx, ny);
    return 0;
}
