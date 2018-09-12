#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define TRUE 1
#define CMD_MAX_LEN 10

int main(void) {
    char cmd[1024];
    while (TRUE) {
        printf("-> ");
        fgets(cmd, CMD_MAX_LEN, stdin);
        printf("%s", cmd);
    }
}