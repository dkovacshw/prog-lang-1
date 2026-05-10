#include <stdio.h>

int get_number_of_lines(FILE *file) {
    int c;
    int lines = 0;

    while ((c = fgetc(file)) != EOF) {
        if (c == '\n') {
            lines++;
        }
    }

    return lines;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Hiba! Adja meg egy szoveges allomany nevet!\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");

    if (file == NULL) {
        fprintf(stderr, "Hiba! A %s nevu file-t nem sikerult megnyitni!\n", argv[1]);
        return 1;
    }

    printf("%d\n", get_number_of_lines(file));

    fclose(file);

    return 0;
}
