#include <stdio.h>

int is_sorted(int arr[], int n);

int is_sorted(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1]) return 0;
    }
    return 1;
}

int main() {
    int a[] = {1, 2, 2, 5, 8};
    int b[] = {3, 1, 4, 2};

    printf("%d\n", is_sorted(a, 5));
    printf("%d\n", is_sorted(b, 4));

    return 0;
}
