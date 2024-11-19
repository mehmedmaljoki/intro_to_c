#ifndef __LIST_H__
#define __LIST_H__

struct node_s {
  char *data;
  struct node_s *next;
  struct node_s *prev;
};

typedef struct node_s node;

// creation
node* createHead(char *data);
node* append(node* head, char *data);
node* prepend(node* head, char *data);

// print, one element per line
void print(node *head);

// move
node* forward(node *head);
node* backward(node *head);

// modify
node* delete(node *head);

// make double linked list a ring
void makeRing(node *head);

// split the ring into regular list
void splitRing(node *head);

// Write a function that destroys a linked list, freeing up all the memory it used for nodes (but don't worry about the data strings)
void freeList(node *head);

// Write another function that destroys a linked list, but also frees up the memory used by the data strings. (be careful to only use strings you can actually free when testing this)
void freeListAndData(node *head);

// Write a function to append a whole list to another list.
node* appendList(node *head, node *tail);

#endif // __LIST_H__
