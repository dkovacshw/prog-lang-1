#include <stdio.h>

void print_ascii() {
    for (int i = 32; i <= 126; i++) {
        printf("%d: %c\n", i, i);
    }
}

int sum_uppercase() {
    int sum = 0;
    for (int i = 65; i <= 90; i++) {
        sum += i;
    }
    return sum;
}

int main() {
    print_ascii();
    printf("\nSum of ASCII values (A-Z): %d\n", sum_uppercase());
    return 0;
}
