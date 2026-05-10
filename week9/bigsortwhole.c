#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    int x = *(int *)a;
    int y = *(int *)b;

    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

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

    int meret = 1000;
    int db = 0;
    int *szamok = malloc(meret * sizeof(int));

    if (szamok == NULL) {
        printf("Memoriafoglalasi hiba!\n");
        fclose(file);
        return 1;
    }

    while (fscanf(file, "%d", &szamok[db]) == 1) {
        db++;

        if (db == meret) {
            meret *= 2;
            int *uj = realloc(szamok, meret * sizeof(int));

            if (uj == NULL) {
                printf("Memoriafoglalasi hiba!\n");
                free(szamok);
                fclose(file);
                return 1;
            }

            szamok = uj;
        }
    }

    fclose(file);

    qsort(szamok, db, sizeof(int), cmp);

    for (int i = 0; i < db; i++) {
        printf("%d\n", szamok[i]);
    }

    free(szamok);

    return 0;
}
