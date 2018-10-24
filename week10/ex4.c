#include <dirent.h>
#include <zconf.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>


struct numnodes {
    long unsigned int i_num;
    int count;
    char **names;
};

int main(void) {
    char *work_dir = "../../week10/tmp/";
    DIR *dirp = opendir(work_dir);
    if (dirp == NULL) {
        return 1;
    }

    int size;
    struct numnodes *array = NULL;
    struct dirent *dp;
    while ((dp = readdir(dirp)) != NULL) {
        char found = 0;
        if (array == NULL) {
            array = malloc(sizeof(struct numnodes));
            size = 1;
            array[0].i_num = dp->d_ino;
            array[0].count = 1;
            array[0].names = malloc(sizeof(char *));
            array[0].names[0] = dp->d_name;
        } else {
            for (int i = 0; i < size && !found; ++i) {
                if (array[i].i_num == dp->d_ino) {
                    found = 1;
                    array[i].count++;
                    array[i].names = realloc(array[i].names, sizeof(char *) * array[i].count);


                    array[i].names[array[i].count - 1] = dp->d_name;
                }
            }
            if (!found) {
                size++;
                array = realloc(array, sizeof(struct numnodes) * size);
                array[size - 1].i_num = dp->d_ino;
                array[size - 1].count = 1;
                array[size - 1].names = malloc(sizeof(char *));
                array[size - 1].names[0] = dp->d_name;
            }
        }
    }
    if (array == NULL) {
        return 1;
    }
    printf("Found %d distinct i-nodes\n", size);

    for (int j = 0; j < size; ++j) {
        if (array[j].count >= 2) {
            printf("Files for i-node %lu: ", array[j].i_num);
            for (int i = 0; i < array[j].count; ++i) {
                printf("%s", array[j].names[i]);
            }
        }
    }
}
