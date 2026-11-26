%{
#include <stdio.h>
int spaces = 0, words = 0, lines = 0;
%}
%%
\n             { lines++; }
[ \t]+         { spaces += yyleng; }
[^ \t\n]+      { words++; }
%%
int yywrap(void) { return 1; }
int main(void) {
    yylex();
    printf("Lines: %d, Words: %d, Spaces/Tabs: %d\n", lines, words, spaces);
    return 0;
}
