#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void bubble_sort(int *, int);

void swap(int *, int *);

void swap(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}

void bubble_sort(int *array, int len) {
    for (int i = 0; i < len - 1; ++i) {
        for (int j = 0; j < len - i - 1; ++j) {
            if (array[j] > array[j + 1]) {
                swap(array + j, array + j + 1);
            }
        }
    }
}

int main() {
    int len = 10;
    int *array = (int *) malloc(len * sizeof(int));

    int mod = 1000;
    srand((unsigned int) time(NULL));
    printf("Original array:\n");
    for (int i = 0; i < len; ++i) {
        array[i] = rand() % mod;
        if (rand() % 2 == 1) {
            array[i] = -array[i];
        }
        printf("%d ", array[i]);
    }
    printf("\n");

    bubble_sort(array, len);
    printf("Sorted array:\n");
    for (int i = 0; i < len; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}