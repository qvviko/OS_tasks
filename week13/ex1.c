#include <stdlib.h>
#include <stdio.h>

#define default_size 5

int main(void) {
    FILE *input = fopen("input.txt", "r");

    int *E = malloc(sizeof(int) * default_size);
    int m_size = 0;
    int m_max = default_size;

    char temp;
    while (fscanf(input, "%d%c", E + m_size, &temp)) {
        m_size++;
        if (temp == '\n') {
            break;
        }
        if (m_size >= m_max) {
            m_max += default_size;
            E = realloc(E, m_max * sizeof(int));
        }
    }
    int *A = malloc(sizeof(int) * m_size);
    int i = 0;
    while (fscanf(input, "%d%c", A + i, &temp)) {
        i++;
        if (temp == '\n') {
            break;
        }
    }

    int processes_n = 0;
    int max_processes = default_size;

    int **C = malloc(sizeof(int *) * max_processes);

    for (int j = 0; j < max_processes; ++j) {
        C[j] = malloc(sizeof(int *) * m_size);
    }

    int **R = malloc(sizeof(int *) * max_processes);
    for (int j = 0; j < max_processes; ++j) {
        C[j] = malloc(sizeof(int *) * m_size);
    }


    char *buffer = malloc(sizeof(char) * (3 * m_size));
    while (fgets(buffer, 3 * m_size, input)) {
        printf("%s", buffer);
        if (buffer == "\n") {
            break;
        } else {
            i = 0;
            while (sscanf(buffer, "%d", C[processes_n] + i)) {
                i++;
            }
        }
        processes_n++;
        if (processes_n == max_processes) {
            max_processes += default_size;
            C = realloc(C, sizeof(int *) * max_processes);

            for (int j = max_processes - default_size; j < max_processes; ++j) {
                C[j] = malloc(sizeof(int *) * m_size);
            }
        }
    }

    while (fgets(buffer, 3 * m_size, input)) {
        i = 0;
        while (sscanf(buffer, "%d", C[processes_n] + i)) {
            i++;
        }
        processes_n++;
        if (processes_n == max_processes) {
            max_processes += default_size;
            C = realloc(C, sizeof(int *) * max_processes);

            for (int j = max_processes - default_size; j < max_processes; ++j) {
                C[j] = malloc(sizeof(int *) * m_size);
            }
        }
    }
}