/* Exp 4: Count Total Operators in a File */
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    FILE *fp = (argc > 1) ? fopen(argv[1], "r") : fopen(__FILE__, "r");
    if (!fp) return 1;
    const char *ops = "+-*/%=<>!&|^";
    int ch, count = 0;
    while ((ch = fgetc(fp)) != EOF) if (strchr(ops, ch)) count++;
    fclose(fp);
    printf("Total operator characters found: %d\n", count);
    return 0;
}
