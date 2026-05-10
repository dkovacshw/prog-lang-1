#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void my_strfry(char s[]) {
    int n = strlen(s);

    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);

        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

int main() {
    char s[] = "HelloWorld";

    srand(time(NULL));

    my_strfry(s);

    printf("%s\n", s);

    return 0;
}
