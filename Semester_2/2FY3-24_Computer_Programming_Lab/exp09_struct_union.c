/* Exp 9: Structure and Union Operations */
#include <stdio.h>
#include <string.h>

struct Student {
    int roll_no;
    char name[40];
    float cgpa;
};

union Data {
    int i;
    float f;
    char str[20];
};

int main(void) {
    struct Student s = {101, "Aarav Sharma", 9.15f};
    printf("Struct Student -> Roll: %d, Name: %s, CGPA: %.2f (size: %zu bytes)\n",
           s.roll_no, s.name, s.cgpa, sizeof(s));

    union Data d;
    d.i = 42;
    printf("\nUnion as int   : %d\n", d.i);
    d.f = 3.14f;
    printf("Union as float : %.2f\n", d.f);
    strcpy(d.str, "Hello");
    printf("Union as string: %s (union size: %zu bytes)\n", d.str, sizeof(d));
    return 0;
}
