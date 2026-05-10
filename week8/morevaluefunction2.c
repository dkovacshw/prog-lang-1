#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int min;
    int max;
    double atlag;
} Eredmeny;

Eredmeny adatok(int tomb[], int meret) {
    Eredmeny e;
    int osszeg = 0;

    e.min = tomb[0];
    e.max = tomb[0];

    for (int i = 0; i < meret; i++) {
        if (tomb[i] < e.min) {
            e.min = tomb[i];
        }
        if (tomb[i] > e.max) {
            e.max = tomb[i];
        }
        osszeg += tomb[i];
    }

    e.atlag = (double)osszeg / meret;

    return e;
}

int main() {
    int tomb[10];

    srand(331);

    for (int i = 0; i < 10; i++) {
        tomb[i] = rand() % 90 + 10;
    }

    printf("A tomb elemei:");
    for (int i = 0; i < 10; i++) {
        printf(" %d", tomb[i]);
        if (i < 9) {
            printf(",");
        }
    }

    Eredmeny e = adatok(tomb, 10);

    printf("\nLegkisebb elem: %d", e.min);
    printf("\nLegnagyobb elem: %d", e.max);
    printf("\nAz elemek atlaga: %.1f\n", e.atlag);

    return 0;
}
