#include <stdio.h>

int main(int argc, char **argv) {
  char *p = "Hello\n";
  char **p2 = &p;
  printf("Das ist der pointer%p\n", *p2);
  return 0;
}
