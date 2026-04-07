#include <stdio.h>

int index_of(int arr[], int n, int value);

int index_of(int arr[], int n, int value) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == value) return i;
    }
    return -1;
}

int main() {
    int arr[] = {4, 8, 2, 6, 10};

    printf("%d\n", index_of(arr, 5, 6));
    printf("%d\n", index_of(arr, 5, 3));

    return 0;
}
