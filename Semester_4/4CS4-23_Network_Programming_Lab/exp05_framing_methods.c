/* Exp 5: Data Link Layer Framing — Bit Stuffing & Byte Stuffing */
#include <stdio.h>
#include <string.h>

void bit_stuff(const char *in, char *out) {
    int ones = 0, j = 0;
    for (int i = 0; in[i]; i++) {
        out[j++] = in[i];
        if (in[i] == '1') {
            if (++ones == 5) { out[j++] = '0'; ones = 0; }
        } else ones = 0;
    }
    out[j] = '\0';
}

void byte_stuff(const char *in, char *out) {
    int j = 0;
    out[j++] = 'F'; /* FLAG */
    for (int i = 0; in[i]; i++) {
        if (in[i] == 'F' || in[i] == 'E') out[j++] = 'E'; /* ESC */
        out[j++] = in[i];
    }
    out[j++] = 'F';
    out[j] = '\0';
}

int main(void) {
    char bits_out[128], bytes_out[128];
    bit_stuff("01111110111110", bits_out);
    byte_stuff("A F E B", bytes_out);
    printf("Bit Stuffed : %s\n", bits_out);
    printf("Byte Stuffed: %s\n", bytes_out);
    return 0;
}
