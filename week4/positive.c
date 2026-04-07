#include <stdio.h>
#include <stdlib.h>

void make_positive(int arr[], int n);
void print_array(int arr[], int n);

void make_positive(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) arr[i] = abs(arr[i]);
    }
}

void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        if (i > 0) printf(" ");
        printf("%d", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {3, -5, 7, -2, -9, 4};
    int n = 6;

    print_array(arr, n);
    make_positive(arr, n);
    print_array(arr, n);

    return 0;
}
