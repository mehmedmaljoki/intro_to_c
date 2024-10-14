

#include <stdio.h>
#include <stdlib.h>

int main() {
  // w write
  // r read
  // a append
  // w+ read and write
  // r+ read and write
  //
  // FILE *pFile = fopen("test.txt", "a");
  //
  // fprintf(pFile, "Hello again!\n");
  //
  // fclose(pFile);


  // delete a file
  if (remove("test.txt") == 0) {
    printf("Deleted successfully");
    return EXIT_SUCCESS;
  }

  printf("Unable to delete the file");
  return EXIT_FAILURE;
}
