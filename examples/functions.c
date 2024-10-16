#include <stdio.h>
#include <stdlib.h>

// Forward declaration
int average(int, int);

void swap(int a, int b) {

}

int main() {
    int fn_val = average(10, 20);
    fn_val = average(10, 20);

    printf("Average: %d\n", fn_val);

    return EXIT_SUCCESS;
}

int average(int a, int b) {
    int sum = 0, ret_val = 0;

    printf("> average(%d, %d) = %d / 2 = %d\n", a, b, sum, ret_val);

    sum = a + b;
    ret_val = sum / 2;

    printf("< average(%d, %d) = %d / 2 = %d\n", a, b, sum, ret_val);

    return ret_val;
}
