/* Exp 2: Identify Whether a Given String is a C Keyword */
#include <stdio.h>
#include <string.h>

int is_keyword(const char *s) {
    const char *kw[] = {"auto","break","case","char","const","continue","default","do","double",
        "else","enum","extern","float","for","goto","if","int","long","register","return",
        "short","signed","sizeof","static","struct","switch","typedef","union","unsigned","void","volatile","while"};
    for (int i = 0; i < 32; i++) if (strcmp(s, kw[i]) == 0) return 1;
    return 0;
}

int main(void) {
    const char *tests[] = {"while", "counter", "return", "myVar"};
    for (int i = 0; i < 4; i++)
        printf("'%s' -> %s\n", tests[i], is_keyword(tests[i]) ? "KEYWORD" : "NOT A KEYWORD");
    return 0;
}
