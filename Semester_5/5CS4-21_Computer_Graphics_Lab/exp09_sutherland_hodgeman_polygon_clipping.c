/* Exp 9: Sutherland-Hodgeman Polygon Clipping (Left Boundary Demo) */
#include <stdio.h>
typedef struct { double x, y; } Pt;

int clip_left(Pt in[], int n, Pt out[], double xmin) {
    int k = 0;
    for (int i = 0; i < n; i++) {
        Pt s = in[i], p = in[(i + 1) % n];
        int s_in = (s.x >= xmin), p_in = (p.x >= xmin);
        if (s_in && p_in) out[k++] = p;
        else if (s_in && !p_in) {
            double y = s.y + (p.y - s.y) * (xmin - s.x) / (p.x - s.x);
            out[k++] = (Pt){xmin, y};
        } else if (!s_in && p_in) {
            double y = s.y + (p.y - s.y) * (xmin - s.x) / (p.x - s.x);
            out[k++] = (Pt){xmin, y};
            out[k++] = p;
        }
    }
    return k;
}

int main(void) {
    Pt poly[] = {{5, 20}, {50, 50}, {50, 10}}, out[20];
    int m = clip_left(poly, 3, out, 15.0);
    printf("Clipped Polygon Vertices (%d):\n", m);
    for (int i = 0; i < m; i++) printf("(%.2f, %.2f)\n", out[i].x, out[i].y);
    return 0;
}
