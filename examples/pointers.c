#include <stdio.h>
#include <stdlib.h>

// Pass by value elementary types
// pass by reference -> pointers
void swap(int *a, int *b) {
    printf("a = %p, b = %p\n", a, b);
    int temp = *b;
    *b = *a;
    *a = temp;
    printf("(swap) *a = %d, *b = %d\n", *a, *b);
}

// ++val
int pre_increment(int *val) {
    *val += 1;
    return *val;
}

// val++
int post_increment(int *val) {
    int old_val = *val;
    *val += 1;
    return old_val;
}

int main() {
    int a = 7;
    int b = 43;
    printf("(before swap method) a = %d, b = %d\n", a, b);

    swap(&a, &b);

    printf("a = %d, b = %d\n", a, b);

    a = 7;
    b = 43;

    // In Java, method parameters are evaluated left to right
    // In C, function parameters are (usually) evaluated right to left
    printf("pre_increment(a): %d, %d, %d\n", a, pre_increment(&a), a);

    return EXIT_SUCCESS;
}
