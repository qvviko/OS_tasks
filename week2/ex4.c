#include <stdio.h>


void swap(int *, int *);

void swap(int *n1, int *n2) {
    int n3 = *n1;
    *n1 = *n2;
    *n2 = n3;
}

int main(void) {
    int n1, n2;
    printf("Enter first integer:");
    scanf("%i", &n1);
    printf("Enter second integer:");
    scanf("%i", &n2);
    swap(&n1, &n2);
    printf("first: %d, second: %d\n", n1, n2);
    return 0;
}