#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

int main(void) {
    char *path_src = "/home/vlad/Projects/OS/week11/ex1.txt";
    char *path_dest = "/home/vlad/Projects/OS/week11/ex1.memcpy.txt";

    int source = open(path_src, O_RDWR);
    if (source < 0) {
        perror("Error on open");
        exit(EXIT_FAILURE);
    }

    struct stat source_stat = {};
    if (fstat(source, &source_stat)) {
        perror("Error on fstat");
        exit(EXIT_FAILURE);
    };

    int dest = open(path_dest, O_RDWR);
    if (dest < 0) {
        perror("Error on open");
        exit(EXIT_FAILURE);
    }

    void *smp = mmap(NULL, source_stat.st_size, PROT_WRITE | PROT_READ, MAP_SHARED, source, 0);
    void *dmp = mmap(NULL, source_stat.st_size, PROT_WRITE | PROT_READ, MAP_SHARED, dest, 0);

    if (ftruncate(dest, source_stat.st_size)) {
        perror("Error on truncate");
        exit(EXIT_FAILURE);
    }

    memcpy(dmp, smp, source_stat.st_size);

}