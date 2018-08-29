#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc == 1) {
        printf("Error. Enter number as an argument\n");
    } else if (argc == 2) {
        printf("Error. Need second argument\n");
    } else {
        int n, fig;
        sscanf(argv[1], "%d", &n);
        sscanf(argv[2], "%d", &fig);

        if (n <= 0) {
            printf("Invalid height. Must be greater then zero\n");
        } else if ((fig <= 0) || (fig > 4)) {
            printf("Invalid figure. Can be 1 2 3 or 4.\n1 is pyramid\n2 is one-sided pyramid\n3 is arrow\n4 is block\n");
        } else {
            switch (fig) {
                case 1: {
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
                    break;
                }
                case 2: {
                    char *string = malloc(sizeof(char) * (n + 1));
                    for (int i = 0; i < n; ++i) {
                        int k;
                        for (k = 0; k <= i; ++k) {
                            string[k] = '*';
                        }
                        string[k] = '\0';
                        printf("%s\n", string);
                    }
                    break;
                }
                case 3: {
                    char *string = malloc(sizeof(char) * n);
                    int k = 1;
                    for (int i = 1; i <= n; ++i) {
                        for (int j = 0; j < k; ++j) {
                            string[j] = '*';
                        }
                        if ((float) n / 2 > i) {
                            k++;
                        } else if ((float) n / 2 < i) {
                            k--;
                        }
                        string[k + 1] = '\0';
                        printf("%s\n", string);
                    }
                    break;
                }
                case 4: {
                    char *string = malloc(sizeof(char) * (n + 1));
                    for (int i = 0; i < n; ++i) {
                        for (int j = 0; j < n; ++j) {
                            string[j] = '*';
                        }
                        string[n] = '\0';
                        printf("%s\n", string);
                    }
                    break;
                }
            }
        }
    }
    return 0;
}