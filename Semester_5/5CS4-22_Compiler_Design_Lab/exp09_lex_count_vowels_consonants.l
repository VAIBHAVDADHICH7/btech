%{
#include <stdio.h>
int vowels = 0, consonants = 0;
%}
%%
[aeiouAEIOU]   { vowels++; }
[a-zA-Z]       { consonants++; }
.|\n           ;
%%
int yywrap(void) { return 1; }
int main(void) {
    yylex();
    printf("Vowels: %d, Consonants: %d\n", vowels, consonants);
    return 0;
}
