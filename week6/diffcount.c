#include <stdio.h>

int main() {
    int used[100] = {0};
    int x;

    printf("Adj meg 0 vegjelig egesz szamokat az [1, 99] intervallumbol!\n");

    while (1) {
        printf("Szam: ");
        scanf("%d", &x);

        if (x == 0) break;

        if (x < 1 || x > 99) {
            printf("Ez a szam kivul esik az elfogadhato intervallumon!\n");
        } else {
            used[x] = 1;
        }
    }

    int count = 0;
    for (int i = 1; i <= 99; i++) {
        if (used[i]) count++;
    }

    printf("\n%d db kulonbozo szam lett megadva.\n", count);
    printf("Ezek (novekvo sorrendben): ");

    int first = 1;
    for (int i = 1; i <= 99; i++) {
        if (used[i]) {
            if (!first) printf(", ");
            printf("%d", i);
            first = 0;
        }
    }
    printf("\n");

    return 0;
}
