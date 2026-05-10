#include <stdio.h>
#include <string.h>
#include <ctype.h>

int is_valid_c_identifier(const char* input) {
    if (strlen(input) == 0) {
        return 0;
    }

    if (!(isalpha(input[0]) || input[0] == '_')) {
        return 0;
    }

    for (int i = 1; input[i] != '\0'; i++) {
        if (!(isalnum(input[i]) || input[i] == '_')) {
            return 0;
        }
    }

    return 1;
}

int main() {
    char input[100];

    printf("Adj meg sztringeket '*' vegjelig!\n");

    while (1) {
        scanf("%99s", input);

        if (strcmp(input, "*") == 0) {
            break;
        }

        if (is_valid_c_identifier(input)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}
