#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void quick_sort(int *, int);

void quick_sort_rec(int *array, int left, int right);

int partitition(int *array, int left, int right);

void swap(int *, int *);

void swap(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}

void quick_sort(int *array, int len) {
    quick_sort_rec(array, 0, len - 1);
}

void quick_sort_rec(int *array, int left, int right) {
    if (left < right) {
        int part = partitition(array, left, right);
        quick_sort_rec(array, left, part - 1);
        quick_sort_rec(array, part + 1, right);
    }
}

int partitition(int *array, int left, int right) {
    srand((unsigned int) time(NULL));
    int pindex = (rand() % (right - left + 1)) + left;
    int pivot = array[pindex];
    swap(array + pindex, array + right);
    int i = left - 1;
    for (int j = left; j < right; ++j) {
        if (array[j] <= pivot) {
            i = i + 1;
            swap(array + i, array + j);
        }
    }
    swap(array + i + 1, array + right);
    return i + 1;
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

    quick_sort(array, len);
    printf("Sorted array:\n");
    for (int i = 0; i < len; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}