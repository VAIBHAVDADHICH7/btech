%{
#include <stdio.h>
int yylex(void);
void yyerror(const char *s) { printf("Invalid string: %s\n", s); }
%}
%token A B NL
%%
stmt : S NL { printf("Valid string in a^n b^n\n"); } ;
S    : A S B | /* empty */ ;
%%
int main(void) { return yyparse(); }
