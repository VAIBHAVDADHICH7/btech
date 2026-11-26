/* Exp 2: Plot a Pixel on a 2D Raster Grid */
#include <stdio.h>
#define W 20
#define H 10
int main(void) {
    char grid[H][W];
    for (int y = 0; y < H; y++) for (int x = 0; x < W; x++) grid[y][x] = '.';
    int px = 10, py = 4;
    grid[py][px] = '#';
    printf("Plotted pixel at (%d, %d):\n", px, py);
    for (int y = 0; y < H; y++) {
        for (int x = 0; x < W; x++) putchar(grid[y][x]);
        putchar('\n');
    }
    return 0;
}
