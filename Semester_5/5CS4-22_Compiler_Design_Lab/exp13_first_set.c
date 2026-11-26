/* Exp 13: Compute FIRST Set of a Context-Free Grammar */
#include <stdio.h>
#include <ctype.h>
#include <string.h>

const char *prods[] = {"E=TR", "R=+TR", "R=#", "T=FY", "Y=*FY", "Y=#", "F=(E)", "F=i"};
int n_prods = 8;

void add_res(char res[], char c) {
    if (!strchr(res, c)) { size_t l = strlen(res); res[l] = c; res[l+1] = '\0'; }
}

void compute_first(char sym, char res[]) {
    if (!isupper((unsigned char)sym)) { add_res(res, sym); return; }
    for (int i = 0; i < n_prods; i++) {
        if (prods[i][0] == sym) {
            if (prods[i][2] == '#') add_res(res, '#');
            else compute_first(prods[i][2], res);
        }
    }
}

int main(void) {
    const char *nts = "ERTYF";
    for (int i = 0; nts[i]; i++) {
        char res[32] = "";
        compute_first(nts[i], res);
        printf("FIRST(%c) = { ", nts[i]);
        for (int j = 0; res[j]; j++) printf("%c ", res[j]);
        printf("}\n");
    }
    return 0;
}
