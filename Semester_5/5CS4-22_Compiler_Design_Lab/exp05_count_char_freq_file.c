/* Exp 5: Count Occurrence of Each Character in a File */
#include <stdio.h>

int main(int argc, char *argv[]) {
    FILE *fp = (argc > 1) ? fopen(argv[1], "r") : fopen(__FILE__, "r");
    if (!fp) return 1;
    int freq[256] = {0}, ch;
    while ((ch = fgetc(fp)) != EOF) freq[(unsigned char)ch]++;
    fclose(fp);
    for (int i = 32; i < 127; i++)
        if (freq[i] > 0) printf("'%c': %d\n", i, freq[i]);
    return 0;
}
