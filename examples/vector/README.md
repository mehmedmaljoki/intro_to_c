# Armstrong Numbers

Welcome to Vector.
If you need help running the tests or working with the code, check out `HELP.md`.

## Instructions

An [Vector][vector] is a sequence of elements that can be accessed by index. It is similar to an array in that it can be used to store a collection of data. However, unlike an array, a vector can grow and shrink in size as needed.

For example:

- Initializing a vector:
```c
struct vector vec = vector_create(10);
```

- Adding an element to a vector:
```c
vector_add(&vec, 5);
```

- Accessing an element by index:
```c
int value = vector_get(&vec, 0);
```

- Removing an element from a vector:
```c
vector_remove(&vec, 0);
```

- Freeing the vector:
```c
vector_free(&vec);
```

[vector]: https://medium.com/@adam.rizk9/the-c-equivalent-to-javas-arraylist-exploring-std-vector-b3a4afc8e9c6

## Source

### Created by

- @mehmedmaljoki

### Based on

Wikipedia - https://medium.com/@adam.rizk9/the-c-equivalent-to-javas-arraylist-exploring-std-vector-b3a4afc8e9c6