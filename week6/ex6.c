#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define STR_LEN 100

int main(void) {
    int pipe_desc[2], value = 0;
    pid_t child1, child2;
    child1 = fork();
    pipe(pipe_desc);

    if (child1) {
        //Parent
        printf("Parent sent pid %d of second child to the first child\n", child2);
        write(pipe_desc[1], &child2, sizeof(child2));
        child2 = fork();

        if (child2) {
            //Child 2
        }
    } else {
        //Child 1
        printf("I'm here");
        read(pipe_desc[0], &child2, sizeof(child2));
        printf("Child 1 received pid %d of the second child\n", child2);
        fflush(stdout);
    }
    sleep(5);

}
