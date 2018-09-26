#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

#define TRUE 1

void universal_handler(int sig) {
    printf("Sig number:%d\n", sig);
}

int main(void) {
    signal(SIGINT, universal_handler);
    signal(SIGSTOP, universal_handler);
    signal(SIGUSR1, universal_handler);
    while (TRUE) {

    }
}