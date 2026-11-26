/* Exp 6: Symbol Table (Insert, Delete, Display) */
#include <stdio.h>
#include <string.h>

typedef struct { char name[32], type[16]; int addr; } Symbol;
Symbol table[50];
int count = 0;

void insert(const char *name, const char *type, int addr) {
    strcpy(table[count].name, name);
    strcpy(table[count].type, type);
    table[count].addr = addr;
    count++;
}

void del(const char *name) {
    for (int i = 0; i < count; i++) {
        if (strcmp(table[i].name, name) == 0) {
            table[i] = table[--count];
            return;
        }
    }
}

void display(void) {
    printf("Name\tType\tAddress\n");
    for (int i = 0; i < count; i++)
        printf("%s\t%s\t%d\n", table[i].name, table[i].type, table[i].addr);
}

int main(void) {
    insert("x", "int", 1000);
    insert("rate", "float", 1004);
    insert("flag", "char", 1008);
    display();
    printf("\nAfter deleting 'rate':\n");
    del("rate");
    display();
    return 0;
}
