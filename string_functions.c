#include <stdio.h>
#include <string.h>


int main()
{
    char string1[] = "Hello, ";
    char string2[] = "world!";


    strlwr(string1); // lowercase
    strupr(string1); // uppercase
    strcat(string1, string2); // appends string2 at the end of string1
    strncat(string1, string2, 3); // appends first 3 characters of string2 at the end of string1
    strcpy(string1, string2); // copies string2 to string1
    strncpy(string1, string2, 3); // copies first 3 characters of string2 to string1

    strset(string1, 'a'); // sets all characters of string1 to 'a'
    strnset(string1, 'b', 3); // sets first 3 characters of string1 to 'b'
    strrev(string1); // reverses string1

    int result = strlen(string1); // returns the length of string1
    int result2 = strcmp(string1, string2); // compares string1 and string2
    int result3 = strncmp(string1, string2, 3); // compares first 3 characters of string1 and string2
    int result4 = strcmpi(string1, string2); // compares string1 and string2 ignoring case
    int result5 = strnicmp(string1, string2, 3); // compares first 3 characters of string1 and string2 ignoring case

    printf("%s\n", string1);
    return 0;
}