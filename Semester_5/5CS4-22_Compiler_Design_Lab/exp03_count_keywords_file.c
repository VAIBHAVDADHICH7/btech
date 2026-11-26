/* Exp 3: Count Total Number of C Keywords in a File */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int is_kw(const char *s) {
    const char *kw[] = {"int","float","char","double","if","else","for","while","return","void","struct"};
    for (int i = 0; i < 11; i++) if (strcmp(s, kw[i]) == 0) return 1;
    return 0;
}

int main(int argc, char *argv[]) {
    FILE *fp = (argc > 1) ? fopen(argv[1], "r") : fopen(__FILE__, "r");
    if (!fp) return 1;
    char word[64]; int idx = 0, ch, count = 0;
    while ((ch = fgetc(fp)) != EOF) {
        if (isalpha(ch) || ch == '_') { if (idx < 63) word[idx++] = (char)ch; }
        else {
            if (idx > 0) { word[idx] = '\0'; if (is_kw(word)) count++; idx = 0; }
        }
    }
    fclose(fp);
    printf("Total keywords found: %d\n", count);
    return 0;
}
