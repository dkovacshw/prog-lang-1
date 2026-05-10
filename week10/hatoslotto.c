#include <stdio.h>

int main() {
    for (int a = 1; a <= 40; a++) {
        for (int b = a + 1; b <= 41; b++) {
            for (int c = b + 1; c <= 42; c++) {
                for (int d = c + 1; d <= 43; d++) {
                    for (int e = d + 1; e <= 44; e++) {
                        for (int f = e + 1; f <= 45; f++) {
                            if (a + b + c + d + e + f == 90 &&
                                a * b * c * d * e * f == 996300) {
                                printf("%d %d %d %d %d %d\n", a, b, c, d, e, f);
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}
