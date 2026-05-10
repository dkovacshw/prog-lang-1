#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct {
    char nev[100];
    int kor;
    char szak[100];
} Hallgato;

void nagykezdo(char s[]) {
    s[0] = toupper(s[0]);

    for (int i = 1; s[i] != '\0'; i++) {
        s[i] = tolower(s[i]);
    }
}

int strcmpi(const char *s1, const char *s2) {
    while (*s1 && *s2) {
        char c1 = tolower(*s1);
        char c2 = tolower(*s2);

        if (c1 != c2) {
            return c1 - c2;
        }

        s1++;
        s2++;
    }

    return tolower(*s1) - tolower(*s2);
}

int main() {
    FILE *file = fopen("nevek.csv", "r");

    if (file == NULL) {
        printf("Nem sikerult megnyitni a fajlt!\n");
        return 1;
    }

    Hallgato h[100];
    int db = 0;

    while (fscanf(file, "%99[^,],%d,%99s\n",
                  h[db].nev,
                  &h[db].kor,
                  h[db].szak) == 3) {
        db++;
    }

    fclose(file);

    char pti[100][100];
    int pti_db = 0;

    for (int i = 0; i < db; i++) {
        if (strcmpi(h[i].szak, "PTI") == 0) {
            strcpy(pti[pti_db], h[i].nev);
            nagykezdo(pti[pti_db]);
            pti_db++;
        }
    }

    for (int i = 0; i < pti_db - 1; i++) {
        for (int j = i + 1; j < pti_db; j++) {
            if (strcmp(pti[i], pti[j]) > 0) {
                char temp[100];

                strcpy(temp, pti[i]);
                strcpy(pti[i], pti[j]);
                strcpy(pti[j], temp);
            }
        }
    }

    for (int i = 0; i < pti_db; i++) {
        printf("%s", pti[i]);

        if (i < pti_db - 1) {
            printf(", ");
        }
    }

    printf("\n");

    return 0;
}
