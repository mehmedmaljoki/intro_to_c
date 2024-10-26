
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char greeting[] = "hello";

    // String.length => strlen(char *str)
    int string_length = strlen(greeting);

    // In C the strlen is O(n) and not O(1) like in Java,
    // so if you need the length often be
    // it from arrays or strings cache them
    printf("the length of string %s is: %\n", greeting, string_length);


    //Adress of codepoint in str => strchr(char *str, int codepoint)

    printf("Address of first 'l' in \"%s\": %p\n", greeting, strchr(greeting, 'l'));
    char *past_l = strchr(greeting, 'l') + 1;
    printf("Address of second 'l' in \"%s\": %p\n", greeting, strchr(past_l, 'l'));

    // Address of last occurrence of codepoint => strrchar(char *str, int codepoint)

    printf("Address of last 'l' in \"%s\": %p\n", greeting, strrchr(greeting, 'l'));

    // String.indexOf in Java =>


    return EXIT_SUCCESS;
}
