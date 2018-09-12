/*
 * This program is more simplistic then the one in ex4 but it is done using fork and execve
 * can accept parameters and handle background jobs
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <wait.h>

#define TRUE 1
#define CMD_MAX_LEN 1024
#define CMD_MAX_ARG_COUNT 16
#define ARG_SIZE 5
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1
#define SPLIT_CHRS " \t\n\a\0"

int shell_loop();

char *receive_line();

char **split_line(const char *inp);

int find_char(const char *string, char chr);

int execute(char **args);

char *receive_line() {
    char *inp = malloc(sizeof(char) * CMD_MAX_LEN);
    if (!inp) {
        fprintf(stderr, "Allocation error, not enough memory\n");
        exit(EXIT_FAILURE);
    }
    fgets(inp, CMD_MAX_LEN, stdin);
}


char **split_line(const char *inp) {
    char **outp = malloc(sizeof(char *) * CMD_MAX_ARG_COUNT);

    if (!outp) {
        fprintf(stderr, "Allocation error, not enough memory\n");
        exit(EXIT_FAILURE);
    }
    int position = 0, args_pos = 0, chr_pos = 0, args_size = ARG_SIZE, args_count = CMD_MAX_ARG_COUNT;
    while (inp[position] != '\0') {
        args_size = ARG_SIZE;
        outp[args_pos] = malloc(sizeof(char) * ARG_SIZE);
        while (find_char(SPLIT_CHRS, inp[position])) {
            outp[args_pos][chr_pos] = inp[position];
            chr_pos++;
            if (chr_pos >= args_size) {
                args_size += ARG_SIZE;
                outp[args_pos] = realloc(outp[args_pos], sizeof(char) * args_size);
                if (!outp[args_pos]) {
                    fprintf(stderr, "Allocation error, not enough memory\n");
                    exit(EXIT_FAILURE);
                }
            }
            position++;
        }
        outp[args_pos][chr_pos] = '\0';
        chr_pos = 0;

        position++;
        args_pos++;

        if (args_pos >= args_size) {
            args_count += CMD_MAX_ARG_COUNT;
            outp = realloc(outp, sizeof(char *) * args_count);
            if (!outp) {
                fprintf(stderr, "Allocation error, not enough memory\n");
                exit(EXIT_FAILURE);
            }
        }

    }
    outp[args_pos] = NULL;
    return outp;
}

int find_char(const char *string, char chr) {
    int i = 0;
    while (string[i] != chr && string[i] != '\0') {
        i++;
    }
    return string[i] != chr;
}

int execute(char **args) {
    int status, pid, is_background = 0;
    int i;
    for (i = 0; args[i] != NULL; ++i);
    if (args[i - 1][0] == '&') {
        is_background = 1;
        args[i - 1] = NULL;
    }
    if (strcmp(args[0], "exit") == 0) {
        exit(EXIT_SUCCESS);
    }
    pid = fork();
    if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            fprintf(stderr, "Execution error\n");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        fprintf(stderr, "Error while forking\n");
    } else {
        if (is_background) {
            fprintf(stdout, "Jobs %s is running in background\n", args[0]);
        } else {
            do {
                waitpid(pid, &status, WUNTRACED);
            } while (!WIFEXITED(status) && !WIFSIGNALED(status));
        }
    }
    return 1;
}

int shell_loop() {
    char *input_line;
    char **args;
    while (TRUE) {
        printf("-> ");

        input_line = receive_line();
        args = split_line(input_line);
        execute(args);

        free(input_line);
        free(args);
    }
}

int main(void) {
    shell_loop();
}
