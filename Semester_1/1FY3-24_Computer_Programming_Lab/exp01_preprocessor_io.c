/* Exp 1: C Library, Preprocessor Directives, and Input-Output Statements */
#include <stdio.h>
#include <math.h>

#define PI 3.14159265
#define SQUARE(x) ((x) * (x))
#define DEBUG_MODE 1

int main(void) {
    double radius;
    char name[50];

    printf("Enter your name: ");
    scanf("%49s", name);
    printf("Enter circle radius: ");
    scanf("%lf", &radius);

    double area = PI * SQUARE(radius);
    double circumference = 2.0 * PI * radius;

    printf("\nHello, %s!\n", name);
    printf("Radius        : %.2f\n", radius);
    printf("Area          : %.4f\n", area);
    printf("Circumference : %.4f\n", circumference);
    printf("Sqrt(Radius)  : %.4f\n", sqrt(radius));

#ifdef DEBUG_MODE
    printf("[DEBUG] Compiled on %s at %s\n", __DATE__, __TIME__);
#endif
    return 0;
}
