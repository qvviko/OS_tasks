#include <stdlib.h>
#include <stdio.h>

#define UNMARKED 0
#define MARKED 1

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
    char *P = malloc(sizeof(char) * processes_n);
    for (int n = 0; n < processes_n; ++n) {
        P[n] = UNMARKED;
    }

    while (1) {
        int chosen = -1;
        for (int i = 0; i < processes_n && chosen == -1; ++i) {
            fflush(stdout);
            if (!P[i]) {
                int all = 1;
                for (int j = 0; j < m && all; ++j) {
                    if (A[j] < R[i][j]) {
                        all = 0;
                    }
                }
                if (all) {
                    chosen = i;
                }
            }
        }
        if (chosen != -1) {
            P[chosen] = MARKED;
            for (int i = 0; i < m; ++i) {
                A[i] += C[chosen][i];
            }
        } else {
            break;
        }
    }
    int marked = 1;
    for (int l = 0; l < processes_n && marked; ++l) {
        marked = P[l];
    }
    if (marked) {
        FILE *outp = fopen("output_ok", "w+");
        fprintf(outp, "No deadlock found");
    } else {
        FILE *outp = fopen("output_dl", "w+");
        fprintf(outp, "Deadlock found, processes involved:\n");
        for (int i = 0; i < processes_n; ++i) {
            if (!P[i]) {
                fprintf(outp, "%d ", i + 1);
            }
        }

    }
}