#include "vector.h"

#include <stdlib.h>
#include <assert.h>
#include <string.h>

struct vector vector_create(size_t initial_capacity, size_t element_size) {
    return (struct vector){
        .size = 0,
        .capacity = initial_capacity,
        .element_size = element_size,
        .con = malloc(initial_capacity * element_size),
    };
}

void vector_destroy(struct vector *vec) {
    assert(vec != NULL);
    free(vec->con);
    vec->con = NULL;
}

static void vector_try_resize(struct vector *vec) {
    if (vec->size == vec->capacity) {
        vec->capacity = vec->capacity * 2 + 10;
        vec->con = realloc(vec->con, vec->capacity * vec->element_size);
        assert(vec->con != NULL);
    }
}

void vector_add(struct vector *vec, void *value) {
    assert(vec != NULL);
    vector_try_resize(vec);
    memcpy(vec->con + (vec->size * vec->element_size), value, vec->element_size);
    vec->size++;
}

void *vector_get(struct vector *vec, size_t index) {
    assert(vec != NULL);
    assert(index < vec->size);
    return vec->con + (index * vec->element_size);
}

void vector_insert(struct vector *vec, size_t index, void *value) {
    assert(vec != NULL);
    // Allow inserting at the end of the vector
    assert(index <= vec->size);
    vector_try_resize(vec);
    // shift elements after the index down
    if (index != vec->size) {
        // in Java like System.arraycopy
        memmove(vec->con + ((index + 1) * vec->element_size),
                vec->con + (index * vec->element_size),
                (vec->size - index) * vec->element_size);
        // memcopy is faster bc it does not use the temp array
        // memcpy(vec->con + index + 1,
        //         vec->con + index,
        //         (vec->size - index) * sizeof(int)); // can wary from platform to platform
    }
    memcpy(vec->con + (index * vec->element_size), value, vec->element_size);
    vec->size++;
}
