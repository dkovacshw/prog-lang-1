#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int choice(const int n, const int tomb[]) {
    int index = rand() % n;
    return tomb[index];
}

int main() {
    int tomb[] = {10, 20, 30, 40, 50};
    int n = sizeof(tomb) / sizeof(tomb[0]);

    srand(time(NULL));

    printf("%d\n", choice(n, tomb));

    return 0;
}
