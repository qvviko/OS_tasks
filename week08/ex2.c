#include <stdlib.h>
#include <memory.h>
#include <stdio.h>
#include <sys/resource.h>
#include <zconf.h>
#include <string.h>

#define SLEEP 10

int main(void) {

    for (int i = 0; i < SLEEP; ++i) {
        size_t t = 10* 1 << 20;
        char *a = malloc(t);
        memset(a, 0, t);
        sleep(1);
    }

}