#include <dirent.h>
#include <zconf.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>

//Struct for counting the i-nodes
struct numnodes {
    long unsigned int i_num;
    int count;
    char **names;
};

int main(void) {
    char *work_dir = "./tmp/";
    DIR *dirp = opendir(work_dir);
    if (dirp == NULL) {
        return 1;
    }

    //Size of array of i-nodes
    int size;
    //Array of i-nodes
    struct numnodes *inode_array = NULL;

    struct dirent *dp;

    //Find every file in directory
    while ((dp = readdir(dirp)) != NULL) {
        char found = 0;

        //If i-node array does not exist - create it and fill with first entry
        if (inode_array == NULL) {
            inode_array = malloc(sizeof(struct numnodes));
            size = 1;
            inode_array[0].i_num = dp->d_ino;
            inode_array[0].count = 1;
            inode_array[0].names = malloc(sizeof(char *));
            inode_array[0].names[0] = dp->d_name;
        } else {
            //Try to find i-node in array with the same num
            for (int i = 0; i < size && !found; ++i) {
                if (inode_array[i].i_num == dp->d_ino) {
                    found = 1;
                    inode_array[i].count++;
                    //Add new entry for name
                    inode_array[i].names = realloc(inode_array[i].names, sizeof(char *) * inode_array[i].count);
                    inode_array[i].names[inode_array[i].count - 1] = dp->d_name;
                }
            }

            //If not found - create new entry
            if (!found) {
                size++;
                inode_array = realloc(inode_array, sizeof(struct numnodes) * size);
                inode_array[size - 1].i_num = dp->d_ino;
                inode_array[size - 1].count = 1;
                inode_array[size - 1].names = malloc(sizeof(char *));
                inode_array[size - 1].names[0] = dp->d_name;
            }
        }
    }

    if (inode_array == NULL) {
        return 1;
    }

    printf("Found %d distinct i-nodes\n", size);

    for (int j = 0; j < size; ++j) {
        if (inode_array[j].count >= 2) {
            printf("Files for i-node %lu: ", inode_array[j].i_num);
            for (int i = 0; i < inode_array[j].count; ++i) {
                printf("%s%s ", work_dir, inode_array[j].names[i]);
            }
            printf("\n");
        }
    }
}
