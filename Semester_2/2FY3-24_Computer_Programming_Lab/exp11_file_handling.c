/* Exp 11: File Handling Operations in C */
#include <stdio.h>

int main(void) {
    const char *filename = "sample_c_lab.txt";
    FILE *fp = fopen(filename, "w");
    if (!fp) {
        perror("fopen write");
        return 1;
    }
    fprintf(fp, "RTU Computer Programming Lab\nFile handling in C language.\n");
    fclose(fp);

    fp = fopen(filename, "r");
    if (!fp) {
        perror("fopen read");
        return 1;
    }
    int ch, chars = 0, words = 0, lines = 0, in_word = 0;
    printf("File contents:\n");
    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
        chars++;
        if (ch == '\n') lines++;
        if (ch == ' ' || ch == '\n' || ch == '\t') in_word = 0;
        else if (!in_word) { in_word = 1; words++; }
    }
    fclose(fp);
    printf("\nStats -> Chars: %d, Words: %d, Lines: %d\n", chars, words, lines);
    return 0;
}
