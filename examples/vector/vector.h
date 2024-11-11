// Header file is a public interface
// it includes method declarations, structs, ..

// Include guard: ensures that the structures in this file are only instantiated
// a single time.

#ifndef C4JP_VECTOR_H_INCLUDED
#define C4JP_VECTOR_H_INCLUDED
#include <stddef.h>

struct vector {
    size_t size; /**< The number of elements stored in the vector. */
    size_t capacity; /**< The maximum number of elements that can be stored in the vector. */
    size_t element_size; /**< The number of bytes each element occupies. */
    char *con; /**< The actual elements in the vector, as an array. */
};

/**
 * Creates a new vector with the given initial capacity.
 *
 * @param initial_capacity The initial capacity of the vector.
 * @return The newly created vector.
 */
struct vector vector_create(size_t initial_capacity, size_t element_size);

/**
* Deallocates the dynamic memory held by the vector.
*
* @param vec The vector to destroy.
*/
void vector_destroy(struct vector *vec);

/**
 * Adds an element to the end of the vector.
 *
 * @param vec The vector to add the element to.
 * @param value The value to add to the vector.
 */
void vector_add(struct vector *vec, void *value);

/**
 * Retrieves the element at the given index in the vector.
 *
 * @param vec The vector to retrieve the element from.
 * @param index The index of the element to retrieve.
 * @return The element at the given index.
 */
void *vector_get(struct vector *vec, size_t index);

/**
 * Inserts an element at the given index in the vector.
 *
 * @param vec The vector to insert the element into.
 * @param index The index at which to insert the element.
 * @param value The value to insert into the vector.
 */
void vector_insert(struct vector *vec, size_t index, void *value);

#endif //C4JP_VECTOR_H_INCLUDED
