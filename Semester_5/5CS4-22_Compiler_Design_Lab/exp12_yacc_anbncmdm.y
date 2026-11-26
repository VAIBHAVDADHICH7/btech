%{
#include <stdio.h>
int yylex(void);
void yyerror(const char *s) { printf("Invalid string: %s\n", s); }
%}
%token A B C D NL
%%
stmt : X Y NL { printf("Valid string in a^n b^n c^m d^m (n,m > 0)\n"); } ;
X    : A X B | A B ;
Y    : C Y D | C D ;
%%
int main(void) { return yyparse(); }
