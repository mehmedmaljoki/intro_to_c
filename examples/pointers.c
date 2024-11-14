#include <stdint.h>
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

void bswap32_in_place(int *bytes) {
    // from OxDE.AD.BE.EF to => 0xEF.BE.AD.DE
    // *bytes ~ 00 11 22 33
    // 1. swap 00 <-> 33 => 33 11 22 00
    int swapped = 0;
    swapped |= (*bytes >> 24) & 0xFF00;    // 00 00 00 00
    swapped |= *bytes << 24;    // 33 00 00 00
    // 2. swap 11 <-> 22 => 33 22 11 00
    swapped |= (*bytes >> 8) & 0xFF00;          // 00 00 11 00
    swapped |= (*bytes << 8) & 0xFF0000;        // 00 22 00 00
    *bytes = swapped;
}

void bswap32_in_place_better(int *input) {
    // from OxDE.AD.BE.EF to => 0xEF.BE.AD.DE
    // *bytes ~ 00 11 22 33
    // 1. swap 00 <-> 33 => 33 11 22 00
    uint8_t *bytes = (uint8_t *) input;
    int swapped = 0;
    for (int i = 0; i < sizeof(int); i++) {
        *((uint8_t *) &swapped + (3 - i)) = *(bytes + i);
    }

    *input = swapped;
}

//wont change the callers str
void foo(char *str){
    str = "Not a new string";
}

//will change the callers str
void foo1(char **str){
    *str = "New String!\n";
}

int main() {
#if 0
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
#endif

    int sample = 0x00112233;
    bswap32_in_place(&sample);

    printf("0x%x\n", sample);

    int sample2 = 0xBEEFCAFE;
    bswap32_in_place_better(&sample2);

    printf("0x%x\n", sample2);


    // pls think how this works
    char *str = "Initial String\n";
    printf("str = %s\n", str);
    foo(str);
    printf("str = %s\n", str);
    foo1(&str);
    printf("str = %s\n", str);

    return EXIT_SUCCESS;
}
