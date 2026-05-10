#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc == 1) {
        fprintf(stderr, "Nem adtal meg egyetlen szot sem!\n");
        return 1;
    }

    int min = strlen(argv[1]);

    for (int i = 2; i < argc; i++) {
        if (strlen(argv[i]) < min) {
            min = strlen(argv[i]);
        }
    }

    for (int i = 1; i < argc; i++) {
        if (strlen(argv[i]) == min) {
            printf("%s\n", argv[i]);
        }
    }

    return 0;
}
