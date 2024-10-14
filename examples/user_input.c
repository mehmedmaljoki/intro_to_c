#include <stdio.h>
#include <string.h>
#include <math.h> // math functions

int main(void)
{
    char name[25];
    int age;

    printf("Enter your name: ");
    //scanf("%s", &name); // mit scanf liest man bis leerzeichen kommt - use fgets()

    fgets(name, 25, stdin); // how to get new line character at the ned? -> string.h
    name[strlen(name) - 1] = '\0'; // remove new line character

    printf("Enter your age: ");

    scanf("%d", &age);

    printf("Hello, %s\n", name);
    printf("You are %d years old\n", age);

    return 0;
}