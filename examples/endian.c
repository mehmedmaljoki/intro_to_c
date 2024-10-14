
#include <stdio.h>
#include <stdlib.h>

int main() {
    unsigned int sample = 0xBEEFCAFE;           // FE CA EF BE
    printf("Ox%x\n", sample & 0xFFu);     // 00 00 00 FE

    return EXIT_SUCCESS;
}

//      BE EF CA FE
//  &   00 00 00 FF (1111 1111)
