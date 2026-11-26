%{
#include <stdio.h>
int yylex(void);
void yyerror(const char *s) { printf("Error: %s\n", s); }
%}
%token NUM
%left '+' '-'
%left '*' '/'
%%
line : expr '\n' { printf("Result = %d\n", $1); } ;
expr : expr '+' expr { $$ = $1 + $3; }
     | expr '-' expr { $$ = $1 - $3; }
     | expr '*' expr { $$ = $1 * $3; }
     | expr '/' expr { $$ = $1 / $3; }
     | '(' expr ')'  { $$ = $2; }
     | NUM           { $$ = $1; } ;
%%
int main(void) { return yyparse(); }
