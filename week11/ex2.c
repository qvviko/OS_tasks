#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
    char *hello = "Hello";

    if (setvbuf(stdout, NULL, _IOLBF, 0)) {
        perror("Error on setbuf");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < strlen(hello); ++i) {
        printf("%c", hello[i]);
        sleep(1);
    }
    printf("\n");
}