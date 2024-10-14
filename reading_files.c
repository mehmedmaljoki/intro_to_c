#include <stdio.h>
#include <stdlib.h>

int main() {

    FILE *pFile = fopen("test.txt", "r");

    char buffer[255];

    if (pFile == NULL) {
        puts("Unable to open file");
        return EXIT_FAILURE;
    } else {
        while (fgets(buffer, 255, pFile) != NULL) {
            printf("%s", buffer); // single line
        }
    }

    fclose(pFile);

    return EXIT_SUCCESS;
}
