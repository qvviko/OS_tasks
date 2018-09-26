#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define MAX_STR_LEN 100

int main(void) {
    int pipe_desc[2];
    char string1[] = "String1";
    char string2[MAX_STR_LEN];
    pipe(pipe_desc);

    printf("String 1: %s\n", string1);
    write(pipe_desc[1], string1, (strlen(string1) + 1));
    read(pipe_desc[0], string2, sizeof(string2));
    printf("String 2: %s\n", string2);
}
