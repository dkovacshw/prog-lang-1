#include <stdio.h>

int main() {
    FILE *in;
    FILE *out;

    double szam;
    int db = 0;

    in = fopen("in.txt", "r");

    if (in == NULL) {
        printf("Hiba az in.txt megnyitasakor!\n");
        return 1;
    }

    printf("# in.txt sikeresen megnyitva\n");

    out = fopen("out.txt", "w");

    if (out == NULL) {
        printf("Hiba az out.txt megnyitasakor!\n");
        fclose(in);
        return 1;
    }

    printf("# 0,5-nel nagyobb szamok szurese...\n");

    while (fscanf(in, "%lf", &szam) == 1) {
        if (szam > 0.5) {
            fprintf(out, "%.16lf\n", szam);
            db++;
        }
    }

    printf("# szures vege\n");

    fclose(in);
    fclose(out);

    printf("# out.txt bezarva\n");
    printf("# out.txt-be kiirt szamok mennyisege: %d db\n", db);

    return 0;
}
