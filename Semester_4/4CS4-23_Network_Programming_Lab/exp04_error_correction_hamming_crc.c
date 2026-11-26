/* Exp 4: Error Detection & Correction — Hamming(7,4) Code */
#include <stdio.h>

int main(void) {
    int d[4] = {1, 0, 1, 1}; /* 4 data bits: d3 d2 d1 d0 */
    int h[8] = {0};          /* 1-indexed Hamming(7,4) codeword */
    h[3] = d[0]; h[5] = d[1]; h[6] = d[2]; h[7] = d[3];
    h[1] = h[3] ^ h[5] ^ h[7];
    h[2] = h[3] ^ h[6] ^ h[7];
    h[4] = h[5] ^ h[6] ^ h[7];

    printf("Encoded Hamming(7,4): ");
    for (int i = 1; i <= 7; i++) printf("%d", h[i]);
    printf("\n");

    /* Simulate 1-bit error at position 5 */
    h[5] ^= 1;
    printf("Received (bit 5 flipped): ");
    for (int i = 1; i <= 7; i++) printf("%d", h[i]);
    printf("\n");

    int p1 = h[1] ^ h[3] ^ h[5] ^ h[7];
    int p2 = h[2] ^ h[3] ^ h[6] ^ h[7];
    int p4 = h[4] ^ h[5] ^ h[6] ^ h[7];
    int err_pos = p4 * 4 + p2 * 2 + p1;

    if (err_pos) {
        printf("Error detected at bit position %d. Correcting...\n", err_pos);
        h[err_pos] ^= 1;
    }
    printf("Corrected codeword: ");
    for (int i = 1; i <= 7; i++) printf("%d", h[i]);
    printf("\n");
    return 0;
}
