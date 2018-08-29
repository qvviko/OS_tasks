#include "string.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char *string = malloc(sizeof(char) * 100);
    char *reverse_string = malloc(sizeof(char) * 100);
    printf("Enter the string with size no more then 100: ");
    scanf("%s", string);
    int i = 0, size_of_str = (int) strlen(string);
    while (string[i] != '\0') {
        reverse_string[size_of_str - i - 1] = string[i];
        i++;
    };
    reverse_string[size_of_str + 1] = '\0';
    printf("%s\n", reverse_string);
}