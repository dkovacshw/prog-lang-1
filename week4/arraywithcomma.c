#include <stdio.h>

void print_array(int arr[], int n);

void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        if (i > 0) printf(", ");
        printf("%d", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {4, 7, 34, 23, 67};
    int n = 5;

    print_array(arr, n);

    return 0;
}
