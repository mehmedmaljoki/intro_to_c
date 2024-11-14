#include "list.h"

#include <stdio.h>
#include <stdlib.h>

// creation
node* createHead(char *data) {
  node* head = malloc(sizeof(node)); // acquire memomry for head node
  head->data = data;                // set data pointer
  head->prev = NULL;                // set prev to NULL to signal it is not valid (this is the first element)
  head->next = NULL;                // set next to NULL to signal it is not valid (this is the last element)
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
  if (head->prev == NULL) { // no previous node, this must be the first
    return head;
  } else {
    return findFirst(head->prev); // recursive function call
  }
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
  printf("%d: %s\n", i, head->data);
  if (head->next != NULL) {
    printPrime(i + 1, head->next);
  }
}

static void printPrimeNotRecursive(node *head) {
  int i = 0;
  while (head != NULL) {
    printf("%d: %s\n", i, head->data);
    head = head->next;
    i++;
  }
}

node* ring(node *head) {
  node *last = findLast(head);
  last->next = head;
  head->prev = last;
  return head;
}

node* split(node *head) {
  node *last = findLast(head);
  last->next = NULL;
  head->prev = NULL;
  return head;
}

void destroy(node *head) {
  if (head->next != NULL) {
    destroy(head->next);
  }
  free(head);
}

void destroyWithStrings(node *head) {
  if (head->next != NULL) {
    destroyWithStrings(head->next);
  }
  free(head->data);
  free(head);
}

node* appendList(node *head, node *tail) {
  node *last = findLast(head);
  last->next = tail;
  tail->prev = last;
  return head;
}

void print(node *head) {
  printPrime(0, head);
}

// move
node* forward(node *head) {
  if (head->next != NULL){
    return head->next;
  } else { // return NULL to signal that move is not possible
    return NULL;
  }
}

node* backward(node *head) {
    if (head->prev != NULL){
        return head->prev;
    } else { // return NULL to signal that move is not possible
        return NULL;
    }
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
    if (prev != NULL) {
        prev->next = next;
        if (next != NULL) {
            next->prev = prev;
            return prev;
        } else {
            return NULL;
        }
    } else {
        if (next != NULL) {
            next->prev = NULL;
            return next;
        } else {
            return NULL;
        }
    }
}
