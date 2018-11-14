#include <stdlib.h>
#include <stdio.h>

#define default_size 5

int main(void) {
    FILE *input = fopen("input.txt", "r");

    int *E = malloc(sizeof(int) * default_size);
    int e_size = 0;
    int e_max = default_size;

    int *A = malloc(sizeof(int) * default_size);
    int a_size = 0;
    int a_max = default_size;

    char temp;
    while (fscanf(input, "%d%c", E + e_size, &temp)) {
        e_size++;
        if (temp == '\n') {
            break;
        }
        if (e_size >= e_max) {
            e_max += default_size;
            E = realloc(E, e_max * sizeof(int));
        }
    }

    while (fscanf(input, "%d%c", A + a_size, &temp)) {
        a_size++;
        if (temp == '\n') {
            break;
        }
        if (a_size >= a_max) {
            a_max += default_size;
            E = realloc(E, a_max * sizeof(int));
        }
    }

    int **C =;

    int **R =;

    for (int i = 0; i < e_size; ++i) {
        printf("%d ", A[i]);
    }
}