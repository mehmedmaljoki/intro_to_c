#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(int argc, char** argv) {
  if (argc < 2) {
    printf("Please provide elements as command-line arguments.\n");
    return EXIT_FAILURE;
  }

  // Create the head of the linked list with the first argument
  node* head = createHead(argv[1]);

  // Append each subsequent argument to the linked list
  for (int i = 2; i < argc; i++) {
    append(head, argv[i]);
  }

  print(head);

  return EXIT_SUCCESS;
}
