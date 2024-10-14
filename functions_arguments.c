#include <stdio.h>

void print_name_age(char name[], int age)
{
    printf("Hello, %s\n", name);
    printf("You are %d years old\n", age);
}

double square(double number)
{
    return number * number;
}

int main()
{
    char name[] = "Mehmed Iksem";
    int age = 29;


    print_name_age(name, age);

    double number = 5.0;
    double result = square(number);
    printf("The square of %.2f is %.2f\n", number, result);

}