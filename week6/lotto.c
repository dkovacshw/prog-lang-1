#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sort(int arr[], int n);

void sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
            }
        }
    }
}

int main() {
    int n, low, high;

    printf("Hany db random szamot kersz?\n");
    scanf("%d", &n);

    printf("Also hatar: ");
    scanf("%d", &low);

    printf("Felso hatar (zart intervallum): ");
    scanf("%d", &high);

    int arr[n];

    srand(time(NULL));

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % (high - low + 1) + low;
    }

    sort(arr, n);

    printf("\nA generalt szamok: ");
    for (int i = 0; i < n; i++) {
        if (i > 0) printf(" ");
        printf("%d", arr[i]);
    }
    printf("\n");

    return 0;
}
