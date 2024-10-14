#include <stdio.h>

void hello(char name[], int age);

int main()
{
    char name[] = "Mehmed Iksem";
    int age = 29;

    hello(name, age);
}

void hello(char name[], int age)
{
    printf("Hello, %s\n", name);
    printf("You are %d years old\n", age);
}