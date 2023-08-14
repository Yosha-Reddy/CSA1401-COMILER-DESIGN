#include <stdio.h>

int main() {
    int a, b, c, d, e, f, g;

    // Taking input from the user
    printf("Enter the value of a: ");
    scanf("%d", &a);

    printf("Enter the value of b: ");
    scanf("%d", &b);

    printf("Enter the value of c: ");
    scanf("%d", &c);

    // Common subexpression elimination
    d = a + b;
    e = c - a;
    f = d * e;
    g = d * e;

    printf("d = %d\n", d);
    printf("e = %d\n", e);
    printf("f = %d\n", f);
    printf("g = %d\n", g);

    return 0;
}
