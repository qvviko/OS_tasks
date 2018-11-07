#include <stdlib.h>
#include <stdio.h>

#define STR_LEN 20

int main(void) {
    FILE *random = fopen("/dev/urandom", "r");
    if (random == NULL) {
        perror("Error on open");
        exit(EXIT_FAILURE);
    }

    // 20+1 so we can end the string with terminator '\0'
    unsigned char *random_string = (unsigned char *) malloc(sizeof(unsigned char) * (STR_LEN + 1));

    //Read 20 symbols
    if (fread(random_string, sizeof(char), STR_LEN, random) == 0) {
        perror("Error on read");
        exit(EXIT_FAILURE);
    }
    //End string with terminator
    random_string[STR_LEN] = '\0';

    printf("String representation:\n");
    printf("%s\n", random_string);
    printf("Byte representation:\n");
    for (int i = 0; i < STR_LEN; ++i) {
        printf("%u ", random_string[i]);
    }
    printf("\n");
}