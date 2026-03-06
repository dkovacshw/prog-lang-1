#include <stdio.h>

int main() {
    int height;

    printf("magassag: ");
    if (scanf("%d", &height) != 1 || height < 1) {
        return 1;
    }

    for (int i = 1; i <= height; i++) {
        for (int j = 0; j < height - i; j++) {
            printf(" ");
        }

        for (int j = 0; j < i; j++) {
            printf("#");
        }

        printf("  ");

        for (int j = 0; j < i; j++) {
            printf("#");
        }

        printf("\n");
    }

    return 0;
}
