#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

#define TRUE 1

void handle_sigint(int sig) {
    printf("\nCtrl+C received\n");
}

int main(void) {
    signal(SIGINT, handle_sigint);
    while (TRUE) {

    }
}