#include <stdio.h>

int largestDivisor(int n) {
    for (int i = n / 2; i >= 1; i--) {
        if (n % i == 0) {
            return i;
        }
    }
    return 1;
}

int main() {

    for (int i = 1; i <= 50; i++) {
        printf("%d -> %d\n", i, largestDivisor(i));
    }

    return 0;
}
