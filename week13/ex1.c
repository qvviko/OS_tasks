#include <stdlib.h>
#include <stdio.h>


int main(void) {
    FILE *input = fopen("input.txt", "r");

    int m;
    fscanf(input, "%d", &m);
    int processes_n;
    fscanf(input, "%d", &processes_n);
    int *E = malloc(sizeof(int) * m);
    int *A = malloc(sizeof(int) * m);
    for (int i = 0; i < m; ++i) {
        fscanf(input, "%d", E + i);
    }
    printf("\n");
    for (int i = 0; i < m; ++i) {
        fscanf(input, "%d", A + i);
    }

    int **C = malloc(sizeof(int *) * processes_n);

    for (int j = 0; j < processes_n; ++j) {
        C[j] = malloc(sizeof(int *) * m);
    }

    for (int k = 0; k < processes_n; ++k) {
        for (int i = 0; i < m; ++i) {
            fscanf(input, "%d", C[k] + i);
        }
    }

    int **R = malloc(sizeof(int *) * processes_n);
    for (int j = 0; j < processes_n; ++j) {
        R[j] = malloc(sizeof(int *) * m);
    }

    for (int k = 0; k < processes_n; ++k) {
        for (int i = 0; i < m; ++i) {
            fscanf(input, "%d", R[k] + i);
        }
    }

}