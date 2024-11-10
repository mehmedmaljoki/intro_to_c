
#include <stdlib.h>

#include "vector.h"

#include <assert.h>

struct vector vector_create(size_t initial_capacity) {
    return (struct vector) {
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

static void vector_resize(struct vector *vec) {
    vec->capacity = vec->capacity * 2 + 10;
    vec->con = realloc(vec->con, vec->capacity * sizeof(int));
    assert(vec->con != NULL);
}

void vector_add(struct vector *vec, int value) {
    assert(vec != NULL);
    if (vec->size == vec->capacity) {
        // grow the vector
        vector_resize(vec);
    }
    vec->con[vec->size] = value;
    vec->size++;
}

int vector_get(struct vector *vec, size_t index) {
    assert(vec != NULL);
    assert(index < vec->size);
    return vec->con[index];
}

void vector_insert(struct vector *vec, size_t index, int value) {

}