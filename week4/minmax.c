#include <stdio.h>

int min_element(int arr[], int n);
int max_element(int arr[], int n);

int min_element(int arr[], int n) {
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) min = arr[i];
    }
    return min;
}

int max_element(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) max = arr[i];
    }
    return max;
}

int main() {
    int arr[] = {5, 2, 9, 1, 7};

    printf("%d\n", min_element(arr, 5));
    printf("%d\n", max_element(arr, 5));

    return 0;
}
