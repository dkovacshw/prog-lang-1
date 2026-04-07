#include <stdio.h>
#include <stdbool.h>

bool valid_triangle(double a, double b, double c);

bool valid_triangle(double a, double b, double c) {
    if (a <= 0 || b <= 0 || c <= 0) return false;
    if (a + b > c && a + c > b && b + c > a) return true;
    return false;
}

int main() {
    printf("%d\n", valid_triangle(3, 4, 5));
    printf("%d\n", valid_triangle(1, 2, 10));
    return 0;
}
