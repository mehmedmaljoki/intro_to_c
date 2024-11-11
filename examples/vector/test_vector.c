#include <stdlib.h>

#include "vector.h"
#include "test-framework/unity.h"

static struct vector vec;

void setUp(void) {
    vec = vector_create(10, sizeof(short));
}

void tearDown(void) {
    vector_destroy(&vec);
}
// #pragma FIXTURE_START
// #pragma FIXTURE_END
//
// #pragma TEST_START
// #pragma TEST_END


static void test_vector_create_works(void) {
    TEST_ASSERT_NOT_NULL(vec.con);
    TEST_ASSERT(vec.capacity == 10);
    TEST_ASSERT(vec.size == 0);
}

static void test_vector_destroy_works(void) {
    vector_destroy(&vec);
    TEST_ASSERT_NULL(vec.con);
}

static void test_vector_add_single_element(void) {
    short a = 42;
    vector_add(&vec, &a);
    TEST_ASSERT_EQUAL_INT(42, vec.con[0]);
    TEST_ASSERT_EQUAL(*((short *) vector_get(&vec, 0)), 42);
    TEST_ASSERT_EQUAL_INT(1, vec.size);
}

static void test_add_multiple_elements(void) {
    short a = 42, b = 43, c = 44;
    vector_add(&vec, &a);
    vector_add(&vec, &b);
    vector_add(&vec, &c);
    TEST_ASSERT_EQUAL(*((short *) vector_get(&vec, 0)), 42);
    TEST_ASSERT_EQUAL(*((short *) vector_get(&vec, 1)), 43);
    TEST_ASSERT_EQUAL(*((short *) vector_get(&vec, 2)), 44);
    TEST_ASSERT_EQUAL_INT(3, vec.size);
}

static void test_vector_add_with_resize(void) {
    for (short i = 0; i < 11; i++) {
        vector_add(&vec, &i);
    }
    TEST_ASSERT_EQUAL(11, vec.size);
    TEST_ASSERT_EQUAL(*((short *) vector_get(&vec, 10)), 10);
}

static void test_insert_into_empty_vector(void) {
    short a = 42;
    vector_insert(&vec, 0, &a);
    TEST_ASSERT_EQUAL(*((short *) vector_get(&vec, 0)), 42);
    TEST_ASSERT_EQUAL(1, vec.size);
}

static void test_insert_into_front_of_vector(void) {
    short a = 42, b = 43, c = 41;
    vector_add(&vec, &a);
    vector_add(&vec, &b);
    vector_insert(&vec, 0, &c);
    TEST_ASSERT_EQUAL(*((short *) vector_get(&vec, 0)), 41);
    TEST_ASSERT_EQUAL(*((short *) vector_get(&vec, 1)), 42);
    TEST_ASSERT_EQUAL(*((short *) vector_get(&vec, 2)), 43);
    TEST_ASSERT_EQUAL(3, vec.size);
}


static void test_insert_at_back_of_vector(void) {
    short a = 42, b = 43, c = 44;
    vector_add(&vec, &a);
    vector_add(&vec, &b);
    vector_insert(&vec, 2, &c);
    TEST_ASSERT_EQUAL(*((short *) vector_get(&vec, 0)), 42);
    TEST_ASSERT_EQUAL(*((short *) vector_get(&vec, 1)), 43);
    TEST_ASSERT_EQUAL(*((short *) vector_get(&vec, 2)), 44);
    TEST_ASSERT_EQUAL(3, vec.size);
}

static void test_insert_in_the_middle_of_vector(void) {
    short a = 42, b = 43, c = 41;
    vector_add(&vec, &a);
    vector_add(&vec, &b);
    vector_insert(&vec, 1, &c);
    TEST_ASSERT_EQUAL(*((short *) vector_get(&vec, 0)), 42);
    TEST_ASSERT_EQUAL(*((short *) vector_get(&vec, 1)), 41);
    TEST_ASSERT_EQUAL(*((short *) vector_get(&vec, 2)), 43);
    TEST_ASSERT_EQUAL(3, vec.size);
}

int main() {
    UnityBegin("test_vector.c");

    RUN_TEST(test_vector_create_works);
    RUN_TEST(test_vector_destroy_works);
    RUN_TEST(test_vector_add_single_element);
    RUN_TEST(test_add_multiple_elements);
    RUN_TEST(test_vector_add_with_resize);
    RUN_TEST(test_insert_into_empty_vector);
    RUN_TEST(test_insert_into_front_of_vector);
    RUN_TEST(test_insert_at_back_of_vector);
    RUN_TEST(test_insert_in_the_middle_of_vector);

    return UnityEnd();
}

