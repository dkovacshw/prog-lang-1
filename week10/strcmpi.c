#include <stdio.h>
#include <ctype.h>

int strcmpi(const char* s1, const char* s2) {
    int i = 0;

    while (s1[i] != '\0' && s2[i] != '\0') {
        char c1 = tolower(s1[i]);
        char c2 = tolower(s2[i]);

        if (c1 != c2) {
            return c1 - c2;
        }

        i++;
    }

    return tolower(s1[i]) - tolower(s2[i]);
}

int main() {
    printf("%d\n", strcmpi("ez", "EZ"));
    printf("%d\n", strcmpi("alma", "Alma"));
    printf("%d\n", strcmpi("alma", "korte"));

    return 0;
}
