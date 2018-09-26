#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int n = 228, pid = fork();
    if (pid > 0) {
        printf("Hello from parent [%d - %d]\n", pid, n);
    } else if (pid == 0) {
        printf("Hello from child [%d - %d]\n", pid, n);
    } else {
        return 1;
    }
    return 0;
}