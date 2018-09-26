#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <pthread.h>

#define TRUE 1


int main(void) {
    pid_t child;
    child = fork();
    if (child == 0) {
        //Child process
        while (TRUE) {
            printf("I am alive\n");
            //Because otherwise it won't print for some reason
            fflush(stdout);
            sleep(1);
        }

    } else {
        sleep(10);
        kill(child, SIGTERM);
    }
}