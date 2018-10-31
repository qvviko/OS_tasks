#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>


int main(void) {
    char *path = "./ex1.txt";
    char *to_print = "This is a nice day";
    size_t str_len = strlen(to_print);
    int file = open(path, O_RDWR);
    if (file < 0) {
        perror("Error on open");
        exit(EXIT_FAILURE);
    }

    if (ftruncate(file, str_len)) {
        perror("Error on truncate");
        exit(EXIT_FAILURE);
    }

    void *mp = mmap(NULL, str_len, PROT_READ | PROT_WRITE, MAP_SHARED, file, 0);
    if (mp == MAP_FAILED) {
        perror("Error on map");
        exit(EXIT_FAILURE);
    }
    memcpy(mp, to_print, str_len);

}