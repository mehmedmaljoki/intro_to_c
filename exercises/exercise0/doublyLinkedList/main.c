#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

void error_exit_malloc(char *s) {
  fprintf(stderr, "malloc failed for %s", s);
  exit(EXIT_FAILURE);
}

int main (int argc, char** argv) {
  // create a linked list containg three elements
  node* head = createHead("first element");
  append(head, "second element");
  append(head, "third element");

  printf("list with 3 elements:\n");
  print(head);

  node* newHead = prepend(head, "zeroeth element");

  printf("list with prepended element:\n");
  print(newHead);

  node *nodeTmp = backward(delete(forward(forward(newHead))));
  printf("list with one element deleted:\n");
  print(nodeTmp);

  // 11.
  makeRing(nodeTmp);
  // prints forever:
  // printf("print ring:\n");
  // print(nodeTmp);

  nodeTmp = forward(forward(nodeTmp));
  splitRing(nodeTmp);
  printf("after splitting two elements forward, 'third element' should be first:\n");
  print(nodeTmp);

  freeList(nodeTmp);
  // freeListAndData(nodeTmp); // segmentation fault

  // test 13.
  char *string1 = malloc(3 * sizeof(char));
  if (string1 == NULL)
    error_exit_malloc("string1");
  strncpy(string1, "01", 2);
  string1[2] = '\0';

  char *string2 = malloc(3 * sizeof(char));
  if (string2 == NULL) {
    free(string1);
    error_exit_malloc("string2");
  }
  strncpy(string2, "02", 2);
  string2[2] = '\0';

  char *string3 = malloc(6 * sizeof(char));
  if (string3 == NULL) {
    free(string1);
    free(string2);
    error_exit_malloc("string3");
  }
  strncpy(string3, "three", 5);
  string3[5] = '\0';

  node* headWithFreeableData = createHead(string1);
  append(headWithFreeableData, string2);
  append(headWithFreeableData, string3);

  printf("new list:\n");
  print(headWithFreeableData);

  //freeListAndData(headWithFreeableData);

  // test 14.
  char *string4 = malloc(4 * sizeof(char));
  if (string4 == NULL) {
    free(string1);
    free(string2);
    free(string3);
    error_exit_malloc("string4");
  }
  strncpy(string4, "2_1", 3);
  string4[3] = '\0';

  char *string5 = malloc(4 * sizeof(char));
  if (string5 == NULL) {
    free(string1);
    free(string2);
    free(string3);
    free(string4);
    error_exit_malloc("string5");
  }
  strncpy(string5, "2_2", 3);
  string5[3] = '\0';

  char *string6 = malloc(8 * sizeof(char));
  if (string6 == NULL) {
    free(string1);
    free(string2);
    free(string3);
    free(string4);
    free(string5);
    error_exit_malloc("string6");
  }
  strncpy(string6, "2_three", 7);
  string6[7] = '\0';

  node* headWithFreeableData2 = createHead(string4);
  append(headWithFreeableData2, string5);
  append(headWithFreeableData2, string6);

  node* combined = appendList(headWithFreeableData, headWithFreeableData2);
  printf("combined lists:\n");
  print(combined);
  freeListAndData(combined);

  // 15.
  node *argvList = createHead(argv[0]);
  for (int i = 1; i < argc; i++) {
    append(argvList, argv[i]);
  }

  printf("argv list:\n");
  print(argvList);
  freeList(argvList);

  // findFirst in ring
  node *ring = createHead("ring0");
  append(ring, "ring1");
  append(ring, "ring2");
  append(ring, "ring3");
  append(ring, "ring4");
  append(ring, "ring5");
  append(ring, "ring6");
  append(ring, "ring7");
  append(ring, "ring8");
  append(ring, "ring9");
  append(ring, "ringA");

  printf("Not yet a ring:\n");
  print(ring);

  makeRing(ring);
  printf("Now it's a ring.\n");
  //print(ring);

  node *firstInRingOrNull = findFirstOrDetectRing(forward(forward(ring)));
  printf("ring: %p, firstInRingOrNull: %p\n", ring, firstInRingOrNull);
  if (firstInRingOrNull)
    print(firstInRingOrNull);
  return 0;
}
