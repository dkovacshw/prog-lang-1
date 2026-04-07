#include <stdio.h>
#include <string.h>

int match_ends(int n, char *words[]);

int match_ends(int n, char *words[]) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        int len = strlen(words[i]);
        if (len >= 2 && words[i][0] == words[i][len - 1]) {
            count++;
        }
    }
    return count;
}

int main() {
    char *szavak1[] = { "aba", "xyz", "aa", "x", "bbb" };
    int szavak1_meret = 5;

    printf("%d\n", match_ends(szavak1_meret, szavak1));

    for (int i = 0; i < szavak1_meret; ++i) {
        puts(szavak1[i]);
    }

    return 0;
}
