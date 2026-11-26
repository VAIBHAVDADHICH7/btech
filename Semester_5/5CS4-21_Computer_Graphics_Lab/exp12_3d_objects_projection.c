/* Exp 12: 3D Cube Perspective Projection onto 2D Screen */
#include <stdio.h>

int main(void) {
    double cube[8][3] = {
        {-1,-1,3},{1,-1,3},{1,1,3},{-1,1,3},
        {-1,-1,5},{1,-1,5},{1,1,5},{-1,1,5}
    };
    double d = 2.0;
    printf("Projected 2D Vertices of 3D Cube (focal length d=%.1f):\n", d);
    for (int i = 0; i < 8; i++) {
        double xp = d * cube[i][0] / cube[i][2];
        double yp = d * cube[i][1] / cube[i][2];
        printf("V%d: (%.3f, %.3f)\n", i, xp, yp);
    }
    return 0;
}
