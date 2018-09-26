#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void) {
    int i;
    float f;
    double d;
    i = INT_MAX;
    f = FLT_MAX;
    d = DBL_MAX;
    printf("Max int: %d\nMax float: %f\nMax double: %e\nSize of int: %d\nSize of float: %d\nSize of double: %d\n", i, f, d,
           sizeof(int), sizeof(float), sizeof(double));

    return 0;
}
