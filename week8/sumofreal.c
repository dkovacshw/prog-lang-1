#include <stdio.h>

int main() {
    FILE *file;
    double szam;
    double osszeg = 0.0;

    file = fopen("valos_szamok.txt", "r");

    if (file == NULL) {
        printf("Nem sikerult megnyitni a fajlt!\n");
        return 1;
    }

    while (fscanf(file, "%lf", &szam) == 1) {
        osszeg += szam;
    }

    printf("%.20lf\n", osszeg);

    fclose(file);

    return 0;
}
