#include <stdio.h>

int main() {
    int a, b;

    printf("Add meg a téglalap egyik oldalát: ");
    scanf("%d", &a);

    printf("Add meg a téglalap másik oldalát: ");
    scanf("%d", &b);

    int kerulet = 2 * (a + b);
    int terulet = a * b;

    printf("A téglalap kerülete: %d\n", kerulet);
    printf("A téglalap területe: %d\n", terulet);

    return 0;
}
