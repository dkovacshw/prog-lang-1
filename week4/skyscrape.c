#include <stdio.h>
#include <stdlib.h>

int diff_sum(int arr[], int n);

int diff_sum(int arr[], int n) {
    int sum = 0;
    for (int i = 1; i < n; i++) {
        sum += abs(arr[i] - arr[i - 1]);
    }
    return sum;
}

int main() {
    int arr[] = {2, 1, 0, 2, 4};
    int n = 5;

    printf("%d\n", diff_sum(arr, n));

    return 0;
}
