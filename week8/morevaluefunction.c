#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void adatok(int tomb[], int meret, int *min, int *max, double *atlag) {
    int osszeg = 0;

    *min = tomb[0];
    *max = tomb[0];

    for (int i = 0; i < meret; i++) {
        if (tomb[i] < *min) {
            *min = tomb[i];
        }
        if (tomb[i] > *max) {
            *max = tomb[i];
        }
        osszeg += tomb[i];
    }

    *atlag = (double)osszeg / meret;
}

int main() {
    int tomb[10];
    int min, max;
    double atlag;

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

    adatok(tomb, 10, &min, &max, &atlag);

    printf("\nLegkisebb elem: %d", min);
    printf("\nLegnagyobb elem: %d", max);
    printf("\nAz elemek atlaga: %.1f\n", atlag);

    return 0;
}
