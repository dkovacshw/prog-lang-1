#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shuffle(int n, char tomb[]) {
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);

        char temp = tomb[i];
        tomb[i] = tomb[j];
        tomb[j] = temp;
    }
}

int main() {
    char kis[] = "abcdefghijklmnopqrstuvwxyz";
    char nagy[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char szam[] = "0123456789";
    char spec[] = ".,;'";

    char jelszo[13];
    int hossz;

    srand(time(NULL));

    hossz = rand() % 5 + 8;

    jelszo[0] = kis[rand() % 26];
    jelszo[1] = nagy[rand() % 26];
    jelszo[2] = szam[rand() % 10];
    jelszo[3] = spec[rand() % 4];

    for (int i = 4; i < hossz; i++) {
        int tipus = rand() % 4;

        if (tipus == 0) {
            jelszo[i] = kis[rand() % 26];
        }
        else if (tipus == 1) {
            jelszo[i] = nagy[rand() % 26];
        }
        else if (tipus == 2) {
            jelszo[i] = szam[rand() % 10];
        }
        else {
            jelszo[i] = spec[rand() % 4];
        }
    }

    shuffle(hossz, jelszo);

    jelszo[hossz] = '\0';

    printf("%s\n", jelszo);

    return 0;
}
