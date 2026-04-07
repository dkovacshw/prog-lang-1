#include <stdio.h>

void fill_array(char arr[]);
void fill_string(char str[]);

void fill_array(char arr[]) {
    for (int i = 0; i < 26; i++) {
        arr[i] = 'a' + i;
    }
}

void fill_string(char str[]) {
    for (int i = 0; i < 26; i++) {
        str[i] = 'a' + i;
    }
    str[26] = '\0';
}

int main() {
    char arr[26];
    char str[27];

    fill_array(arr);
    fill_string(str);

    for (int i = 0; i < 26; i++) {
        printf("%c", arr[i]);
    }
    printf("\n");

    printf("%s\n", str);

    return 0;
}
