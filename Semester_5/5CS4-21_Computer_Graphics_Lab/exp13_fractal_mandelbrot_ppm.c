/* Exp 13: Generate Mandelbrot Set Fractal Image (mandelbrot.ppm) */
#include <stdio.h>

int main(void) {
    int W = 320, H = 240, max_iter = 64;
    FILE *fp = fopen("mandelbrot.ppm", "w");
    if (!fp) return 1;
    fprintf(fp, "P3\n%d %d\n255\n", W, H);
    for (int py = 0; py < H; py++) {
        for (int px = 0; px < W; px++) {
            double x0 = (px - W * 0.7) / (W * 0.3);
            double y0 = (py - H * 0.5) / (H * 0.4);
            double x = 0, y = 0;
            int iter = 0;
            while (x*x + y*y <= 4.0 && iter < max_iter) {
                double xt = x*x - y*y + x0;
                y = 2*x*y + y0; x = xt; iter++;
            }
            int c = (iter == max_iter) ? 0 : (iter * 4) % 256;
            fprintf(fp, "%d %d %d ", c, (c * 2) % 256, 255 - c);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
    printf("Generated mandelbrot.ppm (%dx%d)\n", W, H);
    return 0;
}
