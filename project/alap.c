#include <stdio.h>
#include <stdlib.h>

#define VERSION "1.1"

/* help kiirasa */
void help()
{
    printf("Usage:\n");
    printf("  c\n");
    printf("  java\n");
    printf("  bash\n\n");

    printf("Available options:\n");
    printf("  -h          help\n");
    printf("  -v          version\n");
    printf("  --stdout    print source code to stdout\n");
    printf("  exit        exit the program\n");
}

/* megnezi hogy letezik-e a file */
int exists(char *filename)
{
    FILE *f;

    f = fopen(filename, "r");

    if (f != NULL) {
        fclose(f);
        return 1;
    }

    return 0;
}

/* c kod */
void write_c(FILE *f)
{
    fprintf(f, "#include <stdio.h>\n\n");

    fprintf(f, "int main()\n");
    fprintf(f, "{\n");

    fprintf(f, "    printf(\"hello\\n\");\n");

    fprintf(f, "    return 0;\n");
    fprintf(f, "}\n");
}

/* java kod */
void write_java(FILE *f)
{
    fprintf(f, "public class main {\n");

    fprintf(f, "    public static void main(String[] args) {\n");
    fprintf(f, "        System.out.println(\"hello\");\n");
    fprintf(f, "    }\n");

    fprintf(f, "}\n");
}

/* bash kod */
void write_bash(FILE *f)
{
    fprintf(f, "#!/bin/bash\n\n");

    fprintf(f, "echo \"hello\"\n");
}

/* stdout-ra iras */
void print_source(char lang)
{
    if (lang == 'c') {
        write_c(stdout);
    }

    else if (lang == 'j') {
        write_java(stdout);
    }

    else if (lang == 'b') {
        write_bash(stdout);
    }
}

/* file letrehozasa */
void create_file(char lang)
{
    FILE *f;

    char *filename;

    if (lang == 'c') {
        filename = "main.c";
    }

    else if (lang == 'j') {
        filename = "main.java";
    }

    else {
        filename = "main.sh";
    }

    /* ha mar letezik */
    if (exists(filename)) {
        printf("Error: '%s' already exists\n", filename);
        return;
    }

    /* file megnyitasa */
    f = fopen(filename, "w");

    if (f == NULL) {
        printf("Error: could not create file\n");
        return;
    }

    /* kod beleirasa */
    if (lang == 'c') {
        write_c(f);
    }

    else if (lang == 'j') {
        write_java(f);
    }

    else {
        write_bash(f);
    }

    fclose(f);

    printf("created %s\n", filename);
}

int main()
{
    char line[100];

    printf("alap v%s\n\n", VERSION);

    help();

    while (1) {

        printf("\nalap> ");

        if (fgets(line, 100, stdin) == NULL) {
            break;
        }

        /* kilepes */
        if (line[0] == 'e') {
            printf("bye\n");
            break;
        }

        /* help */
        else if (line[0] == '-' && line[1] == 'h') {
            help();
        }

        /* verzio */
        else if (line[0] == '-' && line[1] == 'v') {
            printf("alap v%s\n", VERSION);
        }

        /* c */
        else if (line[0] == 'c') {

            if (line[2] == '-' &&
                line[3] == '-' &&
                line[4] == 's') {

                print_source('c');
            }

            else {
                create_file('c');
            }
        }

        /* java */
        else if (line[0] == 'j') {

            if (line[5] == '-' &&
                line[6] == '-' &&
                line[7] == 's') {

                print_source('j');
            }

            else {
                create_file('j');
            }
        }

        /* bash */
        else if (line[0] == 'b') {

            if (line[5] == '-' &&
                line[6] == '-' &&
                line[7] == 's') {

                print_source('b');
            }

            else {
                create_file('b');
            }
        }

        /* ismeretlen parancs */
        else {
            help();
        }
    }

    return 0;
}
