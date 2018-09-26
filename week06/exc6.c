#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <wait.h>

#define TRUE 1

int main(void) {
    int pipe_desc[2];
    pid_t child1, child2 = 0;
    pipe(pipe_desc);
    child1 = fork();
    if (child1) {
        //Parent
        child2 = fork();
        if (child2) {
            printf("Parent sent pid %d of second child to the first child\n", child2);
            write(pipe_desc[1], &child2, sizeof(child2));

            int status;
            printf("Parent started waiting for second child\n");
            waitpid(child2, &status, WUNTRACED);
            printf("Parent received status %d from his second child\n", status);
            if (WIFSTOPPED(status)) {
                printf("Parent discovered that his child was stopped\n");
            } else if (WIFEXITED(status)) {
                printf("Parent discovered that his child stopped normally\n");
            }
            if (WIFSIGNALED(status)) {
                printf("Parent discovered that his child was stoppped by signal %d!\n", WTERMSIG(status));
            }
        } else {
            while (TRUE) {};
        }
    } else {
        //Child 1
        read(pipe_desc[0], &child2, sizeof(child2));
        printf("First child received pid %d of the second child\n", child2);

        sleep(2);
        printf("First child stops his brother\n");
        kill(child2, SIGSTOP);
        exit(0);
    }
}
