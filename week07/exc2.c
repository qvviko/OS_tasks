#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int N;
    printf("Input N:");
    char *input;
    scanf("%s", input);
    N = (int) strtol(input, (char **) NULL, 10);
    int *array = (int *) malloc(N * sizeof(int));
    for (int i = 0; i < N; ++i) {
        array[i] = i;
        printf("%d ", array[i]);
    }
    printf("\n");
    free(array);
}