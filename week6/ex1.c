#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int pipe_desc[2];
    pid_t childpid;
    char *string1 = "String1";
    char *string2 = "";
    pipe(pipe_desc);

    if ((childpid = fork()) == -1) {
        perror("fork creation error");
        exit(1);
    }
}
