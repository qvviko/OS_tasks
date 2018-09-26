#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define STR_LEN 100

int main(void) {
    int pipe_desc[2];
    pid_t childpid;
    char string1[] = "String1";
    char string2[STR_LEN];

    pipe(pipe_desc);
    childpid = fork();

    if (childpid == 0) {
        //Child process
        close(pipe_desc[0]);
        read(pipe_desc[1], string2, sizeof(string2));
        printf("String: %s\n", string2);
        exit(0);

    } else {
        close(pipe_desc[1]);
        write(pipe_desc[0], string1, (strlen(string1) + 1));
    }
}
