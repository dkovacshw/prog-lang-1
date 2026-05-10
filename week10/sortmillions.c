#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int size;
    int capacity;
} DynArray;

void da_init(DynArray *self) {
    self->size = 0;
    self->capacity = 2;
    self->data = malloc(self->capacity * sizeof(int));
}

void da_append(DynArray *self, int value) {
    if (self->size == self->capacity) {
        self->capacity *= 2;
        self->data = realloc(self->data, self->capacity * sizeof(int));
    }

    self->data[self->size] = value;
    self->size++;
}

void da_clear(DynArray *self) {
    free(self->data);
    self->size = 0;
    self->capacity = 2;
    self->data = malloc(self->capacity * sizeof(int));
}

void da_destroy(DynArray *self) {
    free(self->data);
    self->data = NULL;
    self->size = 0;
    self->capacity = 0;
}

int cmp(const void *a, const void *b) {
    int x = *(int *)a;
    int y = *(int *)b;

    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Hasznalat: %s fajlnev\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");

    if (file == NULL) {
        printf("Nem sikerult megnyitni a fajlt!\n");
        return 1;
    }

    DynArray tomb;
    da_init(&tomb);

    int szam;

    while (fscanf(file, "%d", &szam) == 1) {
        da_append(&tomb, szam);
    }

    fclose(file);

    qsort(tomb.data, tomb.size, sizeof(int), cmp);

    for (int i = 0; i < tomb.size; i++) {
        printf("%d\n", tomb.data[i]);
    }

    da_clear(&tomb);

    da_append(&tomb, 10);
    da_append(&tomb, 20);
    da_append(&tomb, 30);

    da_destroy(&tomb);

    return 0;
}
