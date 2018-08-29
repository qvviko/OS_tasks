#include "string.h"
#include <stdio.h>
#include <stdlib.h>

#define STRING_SIZE 256

int main(void) {
    char *string = malloc(sizeof(char) * STRING_SIZE);
    char *reverse_string = malloc(sizeof(char) * STRING_SIZE);
    printf("Enter the string with size no more then %d: ", STRING_SIZE);
    scanf("%s", string);
    int i = 0, size_of_str = (int) strlen(string);
    while (string[i] != '\0') {
        reverse_string[size_of_str - i - 1] = string[i];
        i++;
    };
    reverse_string[size_of_str + 1] = '\0';
    printf("%s\n", reverse_string);
}