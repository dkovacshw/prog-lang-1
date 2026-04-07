#include <stdio.h>

int is_even(int n);
int is_odd(int n);

int is_even(int n) {
    return n % 2 == 0;
}

int is_odd(int n) {
    return !is_even(n);
}

int main() {
    printf("%d\n", is_even(4));
    printf("%d\n", is_even(7));
    printf("%d\n", is_odd(4));
    printf("%d\n", is_odd(7));
    return 0;
}
