#include <stdio.h>

int main() {
    int height;

    printf("Magassag: ");
    if (scanf("%d", &height) != 1 || height <= 0 || height % 2 == 0) {
        printf("Hiba: Csak pozitiv paratlan szamot fogadunk el.\n");
        return 1;
    }

    int mid = height / 2;

    for (int i = 0; i <= mid; i++) {
        for (int j = 0; j < mid - i; j++) {
            printf(" ");
        }
        for (int j = 0; j < (2 * i + 1); j++) {
            printf("*");
        }
        printf("\n");
    }

    for (int i = mid - 1; i >= 0; i--) {
        for (int j = 0; j < mid - i; j++) {
            printf(" ");
        }
        for (int j = 0; j < (2 * i + 1); j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
