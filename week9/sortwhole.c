#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Adja meg a fajl nevet!\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");

    if (file == NULL) {
        printf("Nem sikerult megnyitni a fajlt!\n");
        return 1;
    }

    int szamok[1000];
    int db = 0;

    while (fscanf(file, "%d", &szamok[db]) == 1) {
        db++;
    }

    fclose(file);

    for (int i = 0; i < db - 1; i++) {
        for (int j = i + 1; j < db; j++) {
            if (szamok[i] > szamok[j]) {
                int temp = szamok[i];
                szamok[i] = szamok[j];
                szamok[j] = temp;
            }
        }
    }

    for (int i = 0; i < db; i++) {
        printf("%d\n", szamok[i]);
    }

    return 0;
}
