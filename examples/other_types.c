#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>

int main() {
    // Floating-point
    float some_value = 1.5f;
    double pi = 3.14159265;

    // z = print size, u = unsigned
    printf("float <%zu>: %f\n", sizeof(float), some_value);
    printf("double <%zu>: %lf\n", sizeof(double), pi);

    // Operands of different sizes -> promote to the larger type
    printf("float + double <%zu>: %f\n", sizeof(some_value + pi), some_value + pi);

    // Booleans (as int)
    // - 0: false
    // - non-0: true
    int condition = 0;
    if (condition) {
        printf("%d is true!\n", condition);
    } else {
        printf("%d is false!\n", condition);
    }

    unsigned char condition2 = 256; // [0, 2^N - 1] => [0, 255] -> Overflow und wird zu 0
    if (condition2) {
        printf("%d is true!\n", condition2);
    } else {
        printf("%d is false!\n", condition2);
    }

    // Booleans (as boolean)
    _Bool condition_bool = 256;
    bool testing_new_c = true;
    bool testing_new_c2 = false;
    if (condition_bool) {
        printf("%d is true!\n", condition_bool);
    } else {
        printf("%d is false!\n", condition_bool);
    }

    return EXIT_SUCCESS;
}
