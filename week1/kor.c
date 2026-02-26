#include <stdio.h>

int main() {
    double r;

    printf("Adja meg a kör sugarát: ");
    scanf("%lf", &r);

    double pi = 3.14;
    double kerulet = 2 * pi * r;
    double terulet = pi * r * r;

    printf("A kör kerülete: %.2f\n", kerulet);
    printf("A kör területe: %.2f\n", terulet);

    return 0;
}
