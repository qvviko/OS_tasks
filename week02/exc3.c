#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc == 1) {
        printf("Error. Enter number as an argument\n");
    } else {
        int n;
        sscanf(argv[1], "%d", &n);
        if (n <= 0) {
            printf("Invalid number. Must be greater then zero\n");
        } else {
            char *string = malloc(sizeof(char) * (2 * n + 1));
            for (int j = 1; j <= n; ++j) {
                int rqr = ((2 * n - 1) - (2 * j - 1)) / 2;
                int i = (j + 1) * (2 * n);
                for (i = 0; i < rqr; ++i) {
                    string[i] = ' ';
                }
                for (; i < (rqr + 2 * j - 1); ++i) {
                    string[i] = '*';
                }
                for (; i < 2 * n - 1; ++i) {
                    string[i] = ' ';
                }
                string[i] = '\0';
                printf("%s\n", string);
            }
            free(string);
        }
    }

    return 0;
}