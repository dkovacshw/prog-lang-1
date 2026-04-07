#include <stdio.h>
#include <stdlib.h>

void print_array(int arr[], int n);

void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        if (i > 0) printf(", ");
        printf("%d", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Hany db szamot szeretnel bevinni?\n");
    scanf("%d", &n);

    int arr[n];
    int copy[n];

    for (int i = 0; i < n; i++) {
        printf("%d. szam: ", i + 1);
        scanf("%d", &arr[i]);
        copy[i] = abs(arr[i]);
    }

    printf("\nA bevitt szamok abszolutertekei: ");
    print_array(copy, n);

    printf("A megadott szamok: ");
    print_array(arr, n);

    return 0;
}
