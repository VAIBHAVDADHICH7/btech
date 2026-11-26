%{
#include <stdio.h>
%}
%%
[6-9][0-9]{9}                                  { printf("Valid Mobile: %s\n", yytext); }
https?:\/\/[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}(\/\S*)? { printf("Valid URL: %s\n", yytext); }
(0[1-9]|[12][0-9]|3[01])\/(0[1-9]|1[0-2])\/[0-9]{4} { printf("Valid Date: %s\n", yytext); }
([01][0-9]|2[0-3]):[0-5][0-9]:[0-5][0-9]       { printf("Valid Time: %s\n", yytext); }
[a-zA-Z_][a-zA-Z0-9_]*                         { printf("Valid Identifier: %s\n", yytext); }
[ \t\n]+                                       ;
.                                              { printf("Other: %s\n", yytext); }
%%
int yywrap(void) { return 1; }
int main(void) { yylex(); return 0; }
