#include <stdio.h>

int main() {
    int cellak[601] = {0};

    for (int i = 1; i <= 600; i++) {
        for (int j = i; j <= 600; j += i) {
            cellak[j] = !cellak[j];
        }
    }

    for (int i = 1; i <= 600; i++) {
        if (cellak[i]) {
            printf("%d", i);

            if (i != 576) {
                printf(", ");
            }
        }
    }

    printf("\n");

    return 0;
}
