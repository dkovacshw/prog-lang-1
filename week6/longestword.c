#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    int count = 0;
    int maxlen = 0;

    printf("Adj meg szavakat '*' vegjelig!\n");

    while (1) {
        printf("Szo: ");
        fgets(s, sizeof(s), stdin);

        int len = strlen(s);
        if (len > 0 && s[len - 1] == '\n') {
            s[len - 1] = '\0';
            len--;
        }

        if (strcmp(s, "*") == 0) break;

        count++;

        if (len > maxlen) maxlen = len;
    }

    printf("\n%d db szot adtal meg. A leghosszabb szo %d karakterbol all.\n", count, maxlen);

    return 0;
}
