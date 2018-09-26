#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define TRUE 1
#define CMD_MAX_LEN 10

int main(void) {
    char cmd[CMD_MAX_LEN];
    while (TRUE) {
        printf("-> ");
        scanf("%s", cmd);
        system(cmd);
    }
}

