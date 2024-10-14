
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int main() {

    // unsigned int x = 0;
    // unsigned int y = -1; // 0b11111111_11111111_11111111_11111111 => 2^32 - 1
                            // Lösung mache beide signed casten bei der operation selbst in if
                            // oder vorher beide signed deklarieren

    int x = 0;
    int y = -1;
    if ( x > y) {
        puts("Math is worrking!");
        return EXIT_SUCCESS;
    } else {
        puts("What is happening? I am not sure");
        return EXIT_FAILURE;
    }

}
