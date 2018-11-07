#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FALSE 0
#define TRUE 1

int main(int argc, char *argv[]) {
    int files_count;
    char append = FALSE;

    // Get files count
    if (argc == 1) {
        files_count = 1;
    } else if (strcmp(argv[1], "-a") == 0) {
        files_count = argc - 1;
        append = TRUE;
    } else {
        files_count = argc;
    }

    //Malloc for an output file
    FILE **output_file = malloc((files_count) * sizeof(FILE *));
    if (output_file == NULL) {
        perror("Error on malloc of output file");
        exit(EXIT_FAILURE);
    }

    output_file[0] = stdout;

    //Append is 1 is -a is present so we need to skip argv[1] if append == 1
    for (int i = append + 1; i < argc; ++i) {
        if (append) {
            // We decrease by append since argv and files has not 1-1 correspondence because of -a
            output_file[i - append] = fopen(argv[i], "a+");
        } else {
            output_file[i] = fopen(argv[i], "w+");
        }
        if (output_file[i-append] == NULL) {
            perror("Error on open the file");
            exit(EXIT_FAILURE);
        }
    }

    char last_read;
    fread(&last_read, sizeof(char), 1, stdin);

    while (!feof(stdin)) {
        for (int i = 0; i < files_count; ++i) {
            fwrite(&last_read, sizeof(char), 1, output_file[i]);
        }
        fread(&last_read, sizeof(char), 1, stdin);
    }
}