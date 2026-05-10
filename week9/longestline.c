#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Hasznalat: %s sorok min max\n", argv[0]);
        return 1;
    }

    int sorok = atoi(argv[1]);
    int min = atoi(argv[2]);
    int max = atoi(argv[3]);

    srand(time(NULL));

    for (int i = 0; i < sorok; i++) {
        int hossz = rand() % (max - min + 1) + min;

        for (int j = 0; j < hossz; j++) {
            char c = rand() % 95 + 32;
            printf("%c", c);
        }

        printf("\n");
    }

    return 0;
}

//B resz


#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Hasznalat: %s fajlnev\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");

    if (file == NULL) {
        printf("Nem sikerult megnyitni a fajlt!\n");
        return 1;
    }

    int c;
    int hossz = 0;
    int max_hossz = 0;
    int sor = 1;
    int max_sor = 1;

    while ((c = fgetc(file)) != EOF) {
        if (c == '\n') {
            if (hossz > max_hossz) {
                max_hossz = hossz;
                max_sor = sor;
            }

            hossz = 0;
            sor++;
        } else {
            hossz++;
        }
    }

    if (hossz > max_hossz) {
        max_hossz = hossz;
        max_sor = sor;
    }

    fclose(file);

    printf("%d %d\n", max_sor, max_hossz);

    return 0;
}
