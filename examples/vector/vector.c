#include "vector.h"

#include <stdlib.h>
#include <assert.h>
#include <string.h>

struct vector vector_create(size_t initial_capacity) {
    return (struct vector){
        .size = 0,
        .capacity = initial_capacity,
        .con = malloc(initial_capacity * sizeof(int)),
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
        vec->con = realloc(vec->con, vec->capacity * sizeof(int));
        assert(vec->con != NULL);
    }
}

void vector_add(struct vector *vec, int value) {
    assert(vec != NULL);
    vector_try_resize(vec);
    vec->con[vec->size] = value;
    vec->size++;
}

int vector_get(struct vector *vec, size_t index) {
    assert(vec != NULL);
    assert(index < vec->size);
    return vec->con[index];
}

void vector_insert(struct vector *vec, size_t index, int value) {
    assert(vec != NULL);
    // Allow inserting at the end of the vector
    assert(index <= vec->size);
    vector_try_resize(vec);
    // shift elements after the index down
    if (index != vec->size) {
        // in Java like System.arraycopy
        memmove(vec->con + index + 1,
                vec->con + index,
                (vec->size - index) * sizeof(int));
    }
    vec->con[index] = value;
    vec->size++;
}
