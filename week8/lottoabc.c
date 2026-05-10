#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//verzio A

void general(int n, int also, int felso, int tomb[]) {
    for (int i = 0; i < n; i++) {
        tomb[i] = rand() % (felso - also + 1) + also;
    }
}

//verzio B

void rendez(int tomb[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (tomb[i] > tomb[j]) {
                int temp = tomb[i];
                tomb[i] = tomb[j];
                tomb[j] = temp;
            }
        }
    }
}

//verzio C

void kulonbozo(int n, int also, int felso, int tomb[]) {
    int tartomany = felso - also + 1;

    if (n > tartomany) {
        printf("Nem lehet ennyi kulonbozo szamot generalni.\n");
        exit(1);
    }

    int szamok[tartomany];

    for (int i = 0; i < tartomany; i++) {
        szamok[i] = also + i;
    }

    for (int i = tartomany - 1; i > 0; i--) {
        int j = rand() % (i + 1);

        int temp = szamok[i];
        szamok[i] = szamok[j];
        szamok[j] = temp;
    }

    for (int i = 0; i < n; i++) {
        tomb[i] = szamok[i];
    }
}

int main() {
    int n, also, felso;

    srand(time(NULL));

    printf("Hany db random szamot kersz? ");
    scanf("%d", &n);

    printf("Also hatar: ");
    scanf("%d", &also);

    printf("Felso hatar: ");
    scanf("%d", &felso);

    int tomb[n];

    general(n, also, felso, tomb);

    printf("\nVersion A:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", tomb[i]);
    }

    general(n, also, felso, tomb);
    rendez(tomb, n);

    printf("\n\nVersion B:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", tomb[i]);
    }

    kulonbozo(n, also, felso, tomb);
    rendez(tomb, n);

    printf("\n\nVersion C:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", tomb[i]);
    }

    printf("\n");

    return 0;
}
