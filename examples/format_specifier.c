#include <stdio.h>

int main(void)
{
    // %c = char
    // %s = string (array of char)
    // %f = float
    // %d = int
    // %lf = double

    // %.1 decimal precision
    // %1 = minimum field width
    // %- left align

    float item1 = 5.75;
    float item2 = 10.00;
    float item3 = 100.99;

    printf("item 1: $%8.2f\n", item1);
    printf("item 2: $%8.2f\n", item2);
    printf("item 3: $%8.1f\n", item3);

    return 0;

}