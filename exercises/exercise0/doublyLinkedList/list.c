#include "list.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// creation
node* createHead(char *data) {
  node* head = malloc(sizeof(node)); // acquire memomry for head node
  if (head == NULL) {
    fprintf(stderr, "createHead: malloc failed");
    exit(EXIT_FAILURE);
  }
  head->data = data;                // set data pointer
  head->next = NULL;                // set next to NULL to signal it is not valid (this is the last element)
  head->prev = NULL;
  return head;
}

// helper function, only visible in this file
static node* findLast(node *head) {
  if (head->next == NULL) { // no next node, this must be the last
    return head;
  } else {
    return findLast(head->next); // recursive function call
  }
}

// create new node for data and append to the end of the list
node* append(node* head, char *data) {
  node *newNode = createHead(data);
  node *last = findLast(head);
  last->next = newNode;
  newNode->prev = last;
  return head;
}

// helper function, only visible in this file
static node* findFirst(node *head) {
  // recursive
  /*if (head->prev == NULL) { // no prev node, this must be the first
    return head;
  } else {
    return findFirst(head->prev); // recursive function call
  }*/
  // non-recursive
  node *p = head;
  while (p->prev != NULL)
    p = p->prev;
  return p;
}

// findFirst will not return if called for a ring
// findFirstOrDetectRing will return NULL if a ring is detected
node* findFirstOrDetectRing(node *head) {
  size_t size = 8;
  size_t i = 0;
  node **known = malloc(sizeof(node*) * size);
  node *p = head;

  while (p->prev != NULL) {
    bool isKnown = false;
    for (int j = 0; j < i; j++)
      isKnown = isKnown || known[j] == p;
    if (isKnown)
      return NULL;

    if (i >= size) {
      size *= 2;
      // printf("Double size of known to %d\n", size);
      known = realloc(known, sizeof(node*) * size);
      if (known == NULL) {
        fprintf(stderr, "realloc failed");
        exit(EXIT_FAILURE);
      }
    }

    known[i++] = p;
    p = p->prev;
  }

  return p;
}

node* prepend(node *head, char *data) {
  node *newNode = createHead(data);
  node *first = findFirst(head);
  first->prev = newNode;
  newNode->next = first;
  return newNode;
}

// print, one element per line
static void printPrime(int i, node *head) {
  while (head != NULL) {
    printf("%d: %s\n", i, head->data);
    i++;
    head = head->next;
  }
}

void print(node *head) {
  printPrime(0, head);
  /*
  int i = 0;
  while (head != NULL) {
    printf("%d: %s\n", i, head->data);
    i++;
    head = head->next;
  }
  */
}

// move
node* forward(node *head) {
  // explicit:
  if (head->next != NULL){
    return head->next;
  } else { // return NULL to signal that move is not possible
    return NULL;
  }
  // or just:
  // return head->next;
  // because if head->next is NULl, head->next is NULL ;-)
}

node* backward(node *head) {
  return head->prev;
}

// modify
// remove the given element, merge the list parts and
// return the element before the one we just removed (if it exists)
//     or the element after  the one we just removed (if it exists, but no previous element exists)
//     or NULL (if this was the only elemnt)
node* delete(node *head) {
  node *prev = head->prev;
  node *next = head->next;

  free(head);

  if (prev != NULL)
    prev->next = next;

  if (next != NULL)
    next->prev = prev;

  if (prev != NULL)
    return prev;
  if (next != NULL)
    return next;
  return NULL;
}

// 9.
void makeRing(node *head) {
  node *first = findFirst(head);
  node *last = findLast(head);
  first->prev = last;
  last->next = first;
}

// 10.
void splitRing(node *head) {
  node *prev = head->prev;
  prev->next = NULL;
  head->prev = NULL;
}

// 12.
void freeList(node *head) {
  node *p = findFirst(head);
  node *next;
  while (p) {
    next = p->next;
    free(p);
    p = next;
  }
}

// 13.
void freeListAndData(node *head) {
  node *p = findFirst(head);
  node *next;
  while (p) {
    next = p->next;
    free(p->data);
    free(p);
    p = next;
  }
}

// 14.
node *appendList(node *head, node *head2) {
  node *last1 = findLast(head);
  last1->next = head2;
  head2->prev = last1;

  return head;
}
