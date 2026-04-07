#include <stdio.h>

int contains(int arr[], int n, int value);

int contains(int arr[], int n, int value) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == value) return 1;
    }
    return 0;
}

int main() {
    int arr[] = {1, 3, 5, 7, 9};

    printf("%d\n", contains(arr, 5, 5));
    printf("%d\n", contains(arr, 5, 2));

    return 0;
}
